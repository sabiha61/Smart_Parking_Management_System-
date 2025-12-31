#include <stdio.h>
#include "data.h"
#include "utils1.h"

void adminMenu() {
    int choice;
    while(1){
        printf("\n===== ADMIN PANEL =====\n");
        printf("1. Approve Slots\n2. View All Slots\n3. Set Slot Maintenance (Feature 9)\n4. Logout\n");
        choice = getIntInRange("Choice: ", 1, 4);

        if(choice==1){
            printf("\nPending Slots:\n");
            for(int i=0;i<slotCount;i++){
                if(slots[i].isApproved==0){
                    printf("ID:%d | %s | %d hrs | %d tk/hr\n",
                        slots[i].id,
                        slots[i].location,
                        slots[i].availableHours,
                        slots[i].pricePerHour
                    );
                    int approve = getIntInRange("Approve this slot? (1=Yes,0=No): ", 0, 1);
                    if(approve) slots[i].isApproved=1;
                }
            }
        }
        else if(choice==2){
            printf("\nAll Slots:\n");
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
        else if(choice==3){
            // Feature 9: Set Slot Maintenance Status
            int slotId = getValidInt("Enter Slot ID: ");
            int maintChoice = getIntInRange("Set status - 0=Available, 2=Maintenance: ", 0, 2);
            
            for(int i=0; i<slotCount; i++){
                if(slots[i].id == slotId){
                    if(maintChoice == 0 || maintChoice == 2){
                        slots[i].status = maintChoice;
                        printf("Slot %d status updated to %s\n", slotId, 
                               maintChoice == 0 ? "Available" : "Maintenance");
                        saveSlots();
                    } else {
                        printf("Invalid status choice!\n");
                    }
                    break;
                }
            }
        }
        else if(choice==4) return;
        else printf("Invalid choice!\n");
    }
}
