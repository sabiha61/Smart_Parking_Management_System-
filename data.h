#ifndef DATA_H
#define DATA_H

#define MAX_SLOTS 100

typedef struct {
    int id;
    char location[50];
    int pricePerHour;
    int availableHours;
    int isApproved;          // 1 = approved, 0 = pending
    char bookedBy[50];       // user name who booked
    int lastBookedHours;     // hours booked
    int startTime;           // slot start time
    int endTime;             // slot end time
    char vehicleType[20];    // Car, Bike, Truck, etc. (Feature 8)
    int status;              // 0=Available, 1=Booked, 2=Maintenance (Feature 9)
    int lastUsedDate;        // Days since last use (Feature 10)
} Slot;

extern Slot slots[MAX_SLOTS];
extern int slotCount;

void saveSlots();
void loadSlots();
void checkSlotDeactivation(); // Feature 10: Auto deactivate unused slots

#endif
