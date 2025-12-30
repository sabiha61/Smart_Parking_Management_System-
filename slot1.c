#include <stdio.h>
#include "data.h"

void showSlotStatus1(){
    printf("\n===== SLOT STATUS =====\n");
    for(int i = 0; i < slotCount; i++){
        printf("ID:%d | %s | %d hrs left | %s\n",
            slots[i].id,
            slots[i].location,
            slots[i].availableHours,
            slots[i].isApproved ? "Approved" : "Pending"
        );
    }
}
