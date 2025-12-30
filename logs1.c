#include <stdio.h>
#include "logs1.h"

void writeMasterLog(char msg[]){
    FILE* fp = fopen("smart_parking_data.txt","a");
    if(fp){
        fprintf(fp,"%s\n",msg);
        fclose(fp);
    }
}
