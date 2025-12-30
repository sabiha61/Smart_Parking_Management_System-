#include <stdio.h>
#include "data.h"

void adminMenu() {
    int choice;
    while(1){
        printf("\n===== ADMIN PANEL =====\n");
        printf("1. Approve Slots\n2. View All Slots\n3. Logout\nChoice: ");
        scanf("%d",&choice);

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
                    printf("Approve this slot? (1=Yes,0=No): ");
                    int approve; scanf("%d",&approve);
                    if(approve) slots[i].isApproved=1;
                }
            }
        }
        else if(choice==2){
            printf("\nAll Slots:\n");
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
