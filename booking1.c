#include <stdio.h>
#include <string.h>
#include "data.h"
#include "confirmation1.h"

extern char username[50];

void bookSlot1(int slotId, int hours, char* vehicleType) {
    for(int i=0; i<slotCount; i++){
        if(slots[i].id == slotId){
            // Feature 8: Vehicle-Type Compatibility Check
            if(strcmp(slots[i].vehicleType, "Any") != 0 && 
               strcmp(slots[i].vehicleType, vehicleType) != 0){
                printf("Error: Vehicle type mismatch! Slot is for %s, but you have %s.\n", 
                       slots[i].vehicleType, vehicleType);
                return;
            }
            
            // Feature 9: Check status (not maintenance or inactive)
            if(slots[i].status == 2){
                printf("Error: Slot is under maintenance.\n");
                return;
            }
            if(slots[i].status == 3){
                printf("Error: Slot is inactive.\n");
                return;
            }
            
            if(slots[i].isApproved && slots[i].availableHours >= hours && slots[i].status == 0){
                slots[i].availableHours -= hours;
                slots[i].lastBookedHours = hours;
                slots[i].status = 1; // Booked (Feature 9)
                slots[i].lastUsedDate = 0; // Reset counter
                strcpy(slots[i].bookedBy, username);
                printf("Slot booked successfully.\n");
                generateReceipt(&slots[i]); // print receipt + save txt
                saveSlots();
                return;
            }
            else if(slots[i].status == 1){
                printf("Error: Slot is already booked.\n");
                return;
            }
            else if(!slots[i].isApproved){
                printf("Error: Slot is not approved yet.\n");
                return;
            }
            else if(slots[i].availableHours < hours){
                printf("Error: Insufficient available hours.\n");
                return;
            }
        }
    }
    printf("Slot not found.\n");
}
