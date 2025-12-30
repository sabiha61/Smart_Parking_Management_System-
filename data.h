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
} Slot;

extern Slot slots[MAX_SLOTS];
extern int slotCount;

#endif
