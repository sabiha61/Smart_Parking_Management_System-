#include <stdio.h>
#include <string.h>
#include "auth1.h"

#define MAX_LINE 100
#define USER_FILE "users.txt"

int registerUser(const char *username, const char *password, const char *role){
    FILE *fp = fopen(USER_FILE,"a+");
    if(!fp) return 0;

    // check if username already exists
    char u[50], p[50], r[20];
    while(fscanf(fp,"%s %s %s\n", u, p, r)==3){
        if(strcmp(u, username)==0){
            fclose(fp);
            return 0; // username exists
        }
    }

    fprintf(fp,"%s %s %s\n", username, password, role);
    fclose(fp);
    return 1;
}

int loginUser(const char *username, const char *password, char *roleOut){
    FILE *fp = fopen(USER_FILE,"r");
    if(!fp) return 0;

    char u[50], p[50], r[20];
    while(fscanf(fp,"%s %s %s\n", u, p, r)==3){
        if(strcmp(u, username)==0 && strcmp(p, password)==0){
            strcpy(roleOut, r);
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
