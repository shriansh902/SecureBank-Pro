#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void login(){
    printf("---------------------------------\n");
    printf("              LOGIN              \n");
    printf("---------------------------------\n\n");
    
    int acc_num, pin;
    printf("Enter Account Number :- ");
    scanf("%d", &acc_num);
    printf("Enter PIN :- "); // Should be star coded
    scanf("%d", &pin);

}

void dashboard(char name[]){
    printf("\n");
    printf("---------------------------------\n");
    printf("             DASHBOARD           \n");
    printf("---------------------------------\n\n");

    printf("Welcome, %s\n", name);

    printf("1. Check Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Transfer Money\n");
    printf("5. Account Details\n");
    printf("6. Update Account Details\n");
    printf("7. Logout\n\n");

    int choice = 0;
    printf("Enter your choice :- ");
    scanf("%d", &choice);

    if(choice == 1){
        FILE *fptr;
        fptr = fopen("accounts.txt", "r");
        
    }

}

void acc_creation(){
    printf("---------------------------------\n");
    printf("        CREATE NEW ACCOUNT       \n");
    printf("---------------------------------\n\n");

    char first_name[1000], last_name[1000], address[2000];
    int age, phone, pin;
    float amount;

    // The concept of Buffer area is used, that how does /n causes a problem
    // Keyboard → Input Buffer (stdin) → scanf()/fgets() → Your Variables
    while(getchar() != '\n');

    printf("Enter First Name     : ");
    fgets(first_name, sizeof(first_name), stdin);
    first_name[strcspn(first_name, "\n")] = '\0';

    printf("Enter Last Name      : ");
    fgets(last_name, sizeof(last_name), stdin);
    last_name[strcspn(last_name, "\n")] = '\0';

    printf("Enter Address        : ");
    fgets(address, sizeof(address), stdin);
    address[strcspn(address, "\n")] = '\0';

    printf("Enter Age            : ");
    scanf("%d", &age);

    printf("Enter Phone Number   : ");
    scanf("%d", &phone);

    printf("Enter 4 digit PIN    : ");
    scanf("%d", &pin);

    printf("Enter Initial Amount : ");
    scanf("%f", &amount);

    srand(time(NULL));
    int acc_num = (rand() % (9000)) + 1000;
    printf("Your Account Number  : %d \n", acc_num);

    char name[2000] = "";
    strcat(name, first_name);
    strcat(name, " ");
    strcat(name, last_name);

    FILE *fptr;
    fptr = fopen("accounts.txt", "a");
    fprintf(fptr,"\n%d %s %d %d %.2f\n", acc_num, name, age, phone, amount);
    fclose(fptr);

    printf("\nYour Account has been created Successfully !\n");

    dashboard(name);
}


void exit_program(){
    printf("--------------------------------\n");
    printf(" THANK YOU FOR USING SECUREBANK  \n");
    printf("--------------------------------\n\n");
    printf("Have a Great day !! \n\n");
}

int main(){
    int choice1 = 0;

    // Intro UI of Banking System
    printf("\n");
    printf("=================================\n");
    printf("      BANKING UTLITY SYSTEM      \n");
    printf("=================================\n\n");
    printf("      Welcome to SecureBank      \n\n");

    printf("1. Create New Account\n");
    printf("2. Login to existing account\n");
    printf("3. Exit \n\n");

    printf("Enter your choice :- ");
    scanf("%d", &choice1);
    printf("\n");

    if(choice1 == 1){
        acc_creation();
    }
    if(choice1 == 2){
        login();
    }
    if(choice1 == 3){
        exit_program();
    }
}

// Testing Zone
// #include <stdio.h>
// #include <string.h>

// int main(){
//     FILE *fptr;
//     fptr = fopen("accounts.txt", "w");
//     fputs(strcat("Hello ", "World"), fptr);
// }