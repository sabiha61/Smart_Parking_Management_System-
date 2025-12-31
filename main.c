#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"
#include "owner1.h"
#include "admin1.h"
#include "user1.h"
#include "auth1.h"

char username[50];
char password[50];
char role[20];

void mainMenu() {
    int choice;
    while(1) {
        printf("\n===== SMART PARKING MANAGEMENT SYSTEM =====\n");
        printf("1. Register\n2. Login\n3. Exit\nChoice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                // Feature 6: Garage Owner Registration (using auth1.c)
                printf("Enter Username: "); scanf("%s",username);
                printf("Enter Password: "); scanf("%s",password);
                printf("Enter Role (Admin/Owner/User): "); scanf("%s",role);
                
                if(registerUser(username, password, role)){
                    printf("Registration Successful!\n");
                } else {
                    printf("Registration Failed! Username may already exist.\n");
                }
                break;

            case 2:
                // Feature 6: Login using auth1.c
                printf("Username: "); scanf("%s",username);
                printf("Password: "); scanf("%s",password);
                
                char roleOut[20];
                if(loginUser(username, password, roleOut)){
                    strcpy(role, roleOut);
                    printf("\nWelcome %s!\nRole: %s\n", username, role);

                    if(strcmp(role,"Admin")==0) adminMenu();
                    else if(strcmp(role,"Owner")==0) ownerMenu();
                    else if(strcmp(role,"User")==0) userMenu();
                    else printf("Unknown role!\n");
                } else {
                    printf("Login Failed! Invalid username or password.\n");
                }
                break;

            case 3:
                printf("Exiting...\n"); exit(0);

            default: printf("Invalid choice!\n");
        }
    }
}

int main() {
    loadSlots(); // load previous slots from file
    checkSlotDeactivation(); // Feature 10: Check and deactivate unused slots
    mainMenu();
    return 0;
}
