#include <stdio.h>
#include <string.h>
#include "data.h"
#include "booking1.h"

extern char username[50];

void userMenu() {
    int choice;
    while(1){
        printf("\n===== USER PANEL =====\n");
        printf("1. View Available Slots\n2. Book Slot\n3. Logout\nChoice: ");
        scanf("%d",&choice);

        if(choice==1){
            printf("\nAvailable Slots:\n");
            for(int i=0;i<slotCount;i++){
                if(slots[i].isApproved && slots[i].availableHours>0){
                    printf("ID:%d | %s | %d hrs free | %d tk/hr\n",
                        slots[i].id,
                        slots[i].location,
                        slots[i].availableHours,
                        slots[i].pricePerHour
                    );
                }
            }
        }
        else if(choice==2){
            int slotId,hours;
            printf("Enter Slot ID to book: "); scanf("%d",&slotId);
            printf("Enter hours to book: "); scanf("%d",&hours);
            bookSlot1(slotId,hours);
        }
        else if(choice==3) return;
        else printf("Invalid choice!\n");
    }
}
