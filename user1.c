#include <stdio.h>
#include <string.h>
#include "data.h"
#include "booking1.h"

extern char username[50];

void userMenu() {
    int choice;
    while(1){
        printf("\n===== USER PANEL =====\n");
        printf("1. View Available Slots\n2. Search Slots by Location (Feature 11)\n3. Book Slot\n4. Logout\nChoice: ");
        scanf("%d",&choice);

        if(choice==1){
            printf("\nAvailable Slots:\n");
            for(int i=0;i<slotCount;i++){
                if(slots[i].isApproved && slots[i].availableHours>0 && slots[i].status == 0){
                    printf("ID:%d | %s | %s | %d hrs free | %d tk/hr\n",
                        slots[i].id,
                        slots[i].location,
                        slots[i].vehicleType,
                        slots[i].availableHours,
                        slots[i].pricePerHour
                    );
                }
            }
        }
        else if(choice==2){
            // Feature 11: Location-Based Slot Search
            char searchLocation[50];
            printf("Enter location to search: "); scanf("%s",searchLocation);
            printf("\nSlots near '%s':\n", searchLocation);
            int found = 0;
            for(int i=0;i<slotCount;i++){
                if(slots[i].isApproved && slots[i].availableHours>0 && slots[i].status == 0){
                    // Simple location matching (case-insensitive substring)
                    if(strstr(slots[i].location, searchLocation) != NULL || 
                       strstr(searchLocation, slots[i].location) != NULL){
                        printf("ID:%d | %s | %s | %d hrs free | %d tk/hr\n",
                            slots[i].id,
                            slots[i].location,
                            slots[i].vehicleType,
                            slots[i].availableHours,
                            slots[i].pricePerHour
                        );
                        found = 1;
                    }
                }
            }
            if(!found) printf("No slots found near '%s'\n", searchLocation);
        }
        else if(choice==3){
            int slotId,hours;
            char vehicleType[20];
            printf("Enter Slot ID to book: "); scanf("%d",&slotId);
            printf("Enter your vehicle type (Car/Bike/Truck): "); scanf("%s",vehicleType);
            printf("Enter hours to book: "); scanf("%d",&hours);
            bookSlot1(slotId,hours,vehicleType);
        }
        else if(choice==4) return;
        else printf("Invalid choice!\n");
    }
}
