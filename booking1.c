#include <stdio.h>
#include <string.h>
#include "data.h"
#include "confirmation1.h"

extern char username[50];

void bookSlot1(int slotId, int hours) {
    for(int i=0; i<slotCount; i++){
        if(slots[i].id == slotId && slots[i].isApproved && slots[i].availableHours >= hours){
            slots[i].availableHours -= hours;
            slots[i].lastBookedHours = hours;
            strcpy(slots[i].bookedBy, username);
            printf("Slot booked successfully.\n");
            generateReceipt(&slots[i]); // print receipt + save txt
            saveSlots();
            return;
        }
    }
    printf("Slot not available or insufficient hours.\n");
}
