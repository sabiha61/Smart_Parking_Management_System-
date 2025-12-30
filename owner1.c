#include <stdio.h>
#include <string.h>
#include "data.h"

extern char username[50];

void ownerMenu() {
    int choice;
    while(1){
        printf("\n===== OWNER PANEL =====\n");
        printf("1. Add Parking Slot\n2. View Slots\n3. Logout\nChoice: ");
        scanf("%d",&choice);

        if(choice==1){
            if(slotCount>=MAX_SLOTS){
                printf("Maximum slots reached.\n");
                continue;
            }
            Slot s;
            s.id = slotCount+1;
            printf("Enter location: "); scanf("%s",s.location);
            printf("Enter price per hour: "); scanf("%d",&s.pricePerHour);
            printf("Enter available hours: "); scanf("%d",&s.availableHours);
            printf("Enter start time (hour): "); scanf("%d",&s.startTime);
            printf("Enter end time (hour): "); scanf("%d",&s.endTime);
            s.isApproved = 0; // pending
            strcpy(s.bookedBy,"None");
            s.lastBookedHours = 0;

            slots[slotCount++] = s;
            printf("Slot added successfully. Pending admin approval.\n");
        }
        else if(choice==2){
            printf("\nYour Slots:\n");
            for(int i=0;i<slotCount;i++){
                printf("ID:%d | %s | %d hrs | %d tk/hr | %s\n",
                    slots[i].id,
                    slots[i].location,
                    slots[i].availableHours,
                    slots[i].pricePerHour,
                    slots[i].isApproved ? "Approved":"Pending"
                );
            }
        }
        else if(choice==3) return;
        else printf("Invalid choice!\n");
    }
}
