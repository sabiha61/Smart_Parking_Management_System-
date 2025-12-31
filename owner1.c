#include <stdio.h>
#include <string.h>
#include "data.h"
#include "utils1.h"

extern char username[50];

void ownerMenu() {
    int choice;
    while(1){
        printf("\n===== OWNER PANEL =====\n");
        printf("1. Add Parking Slot\n2. View Slots\n3. Logout\n");
        choice = getIntInRange("Choice: ", 1, 3);

        if(choice==1){
            if(slotCount>=MAX_SLOTS){
                printf("Maximum slots reached.\n");
                continue;
            }
            Slot s;
            s.id = slotCount+1;
            printf("Enter location: "); scanf("%s",s.location);
            s.pricePerHour = getValidInt("Enter price per hour: ");
            s.availableHours = getValidInt("Enter available hours: ");
            s.startTime = getIntInRange("Enter start time (hour, 0-23): ", 0, 23);
            s.endTime = getIntInRange("Enter end time (hour, 0-23): ", 0, 23);
            printf("Enter vehicle type (Car/Bike/Truck/Any): "); scanf("%s",s.vehicleType);
            s.isApproved = 0; // pending
            s.status = 0; // Available (Feature 9)
            s.lastUsedDate = 0; // Feature 10
            strcpy(s.bookedBy,"None");
            s.lastBookedHours = 0;

            slots[slotCount++] = s;
            printf("Slot added successfully. Pending admin approval.\n");
        }
        else if(choice==2){
            printf("\nYour Slots:\n");
            for(int i=0;i<slotCount;i++){
                char statusStr[20];
                if(slots[i].status == 0) strcpy(statusStr, "Available");
                else if(slots[i].status == 1) strcpy(statusStr, "Booked");
                else if(slots[i].status == 2) strcpy(statusStr, "Maintenance");
                else strcpy(statusStr, "Inactive");
                
                printf("ID:%d | %s | %s | %d hrs | %d tk/hr | %s | %s\n",
                    slots[i].id,
                    slots[i].location,
                    slots[i].vehicleType,
                    slots[i].availableHours,
                    slots[i].pricePerHour,
                    slots[i].isApproved ? "Approved":"Pending",
                    statusStr
                );
            }
        }
        else if(choice==3) return;
        else printf("Invalid choice!\n");
    }
}
