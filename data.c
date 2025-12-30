#include "data.h"
#include <stdio.h>

Slot slots[MAX_SLOTS];
int slotCount = 0;

void saveSlots() {
    FILE *fp = fopen("slots.txt", "w");
    for(int i=0; i<slotCount; i++){
        fprintf(fp, "%d %s %d %d %d %d %d %s\n",
            slots[i].id,
            slots[i].location,
            slots[i].pricePerHour,
            slots[i].availableHours,
            slots[i].isApproved,
            slots[i].startTime,
            slots[i].endTime,
            slots[i].bookedBy
        );
    }
    fclose(fp);
}

void loadSlots() {
    FILE *fp = fopen("slots.txt", "r");
    if(!fp) return;
    slotCount = 0;
    while(fscanf(fp, "%d %s %d %d %d %d %d %s",
        &slots[slotCount].id,
        slots[slotCount].location,
        &slots[slotCount].pricePerHour,
        &slots[slotCount].availableHours,
        &slots[slotCount].isApproved,
        &slots[slotCount].startTime,
        &slots[slotCount].endTime,
        slots[slotCount].bookedBy) != EOF) {
            slotCount++;
    }
    fclose(fp);
}
