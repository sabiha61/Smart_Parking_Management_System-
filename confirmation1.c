#include <stdio.h>
#include "data.h"

void generateReceipt(Slot *s){
    FILE *fp = fopen("receipt.txt", "w");
    int total = s->lastBookedHours * s->pricePerHour;
    fprintf(fp,
        "\n========== PARKING RECEIPT ==========\n"
        "User        : %s\n"
        "Location    : %s\n"
        "Hours Booked: %d\n"
        "Rate/hour   : %d TK\n"
        "------------------------------------\n"
        "TOTAL       : %d TK\n"
        "====================================\n",
        s->bookedBy,
        s->location,
        s->lastBookedHours,
        s->pricePerHour,
        total
    );
    fclose(fp);

    printf("\n========== PARKING RECEIPT ==========\n"
           "User        : %s\n"
           "Location    : %s\n"
           "Hours Booked: %d\n"
           "Rate/hour   : %d TK\n"
           "------------------------------------\n"
           "TOTAL       : %d TK\n"
           "====================================\n",
           s->bookedBy,
           s->location,
           s->lastBookedHours,
           s->pricePerHour,
           total
    );
}
