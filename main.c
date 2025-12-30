#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"
#include "owner1.h"
#include "admin1.h"
#include "user1.h"

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
                printf("Enter Username: "); scanf("%s",username);
                printf("Enter Password: "); scanf("%s",password);
                printf("Enter Role (Admin/Owner/User): "); scanf("%s",role);
                printf("Registration Successful!\n");
                break;

            case 2:
                printf("Username: "); scanf("%s",username);
                printf("Password: "); scanf("%s",password);

                printf("\nWelcome %s!\nRole: %s\n", username, role);

                if(strcmp(role,"Admin")==0) adminMenu();
                else if(strcmp(role,"Owner")==0) ownerMenu();
                else if(strcmp(role,"User")==0) userMenu();
                else printf("Unknown role!\n");
                break;

            case 3:
                printf("Exiting...\n"); exit(0);

            default: printf("Invalid choice!\n");
        }
    }
}

int main() {
    loadSlots(); // load previous slots from file
    mainMenu();
    return 0;
}
