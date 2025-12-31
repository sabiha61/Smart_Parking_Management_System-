#include "data.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

Slot slots[MAX_SLOTS];
int slotCount = 0;

void saveSlots() {
    FILE *fp = fopen("slots.txt", "w");
    for(int i=0; i<slotCount; i++){
        fprintf(fp, "%d %s %d %d %d %d %d %s %s %d %d\n",
            slots[i].id,
            slots[i].location,
            slots[i].pricePerHour,
            slots[i].availableHours,
            slots[i].isApproved,
            slots[i].startTime,
            slots[i].endTime,
            slots[i].bookedBy,
            slots[i].vehicleType,
            slots[i].status,
            slots[i].lastUsedDate
        );
    }
    fclose(fp);
}

void loadSlots() {
    FILE *fp = fopen("slots.txt", "r");
    if(!fp) return;
    slotCount = 0;
    
    // Try to read new format first (with new fields)
    int result;
    while((result = fscanf(fp, "%d %s %d %d %d %d %d %s %s %d %d",
        &slots[slotCount].id,
        slots[slotCount].location,
        &slots[slotCount].pricePerHour,
        &slots[slotCount].availableHours,
        &slots[slotCount].isApproved,
        &slots[slotCount].startTime,
        &slots[slotCount].endTime,
        slots[slotCount].bookedBy,
        slots[slotCount].vehicleType,
        &slots[slotCount].status,
        &slots[slotCount].lastUsedDate)) == 11) {
            slotCount++;
    }
    fclose(fp);
    
    // If no slots loaded or format mismatch, try old format (backward compatibility)
    if(slotCount == 0) {
        fp = fopen("slots.txt", "r");
        if(!fp) return;
        while(fscanf(fp, "%d %s %d %d %d %d %d %s",
            &slots[slotCount].id,
            slots[slotCount].location,
            &slots[slotCount].pricePerHour,
            &slots[slotCount].availableHours,
            &slots[slotCount].isApproved,
            &slots[slotCount].startTime,
            &slots[slotCount].endTime,
            slots[slotCount].bookedBy) == 8) {
                // Set default values for new fields
                strcpy(slots[slotCount].vehicleType, "Any");
                slots[slotCount].status = 0; // Available
                slots[slotCount].lastUsedDate = 0;
                slotCount++;
        }
        fclose(fp);
    }
}

// Feature 10: Auto deactivate slots not used for 30+ days
void checkSlotDeactivation() {
    for(int i=0; i<slotCount; i++) {
        // Increment lastUsedDate for available slots that haven't been booked
        if(slots[i].status == 0 && slots[i].isApproved) {
            slots[i].lastUsedDate++;
        }
        
        // Deactivate if not used for 30+ days
        if(slots[i].lastUsedDate > 30 && slots[i].status == 0) {
            slots[i].status = 3; // Inactive
            printf("Slot ID %d auto-deactivated (not used for %d days)\n", 
                   slots[i].id, slots[i].lastUsedDate);
        }
    }
}
