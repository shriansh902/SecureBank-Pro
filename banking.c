#include <stdio.h>

void acc_creation(){
    printf("=================================\n");
    printf("        CREATE NEW ACCOUNT       \n");
    printf("=================================\n\n");

    char full_name[1000], user_name[1000], address[1000];
    int ph_num, age, init_dep;
    printf("Enter Full Name :- ");
    fgets(full_name, 1000, stdin);
    printf("Enter Age :- ");
    scanf("%d", &age);
    printf("Enter Phone Number :- ");
    scanf("%d", &ph_num);
    printf("Enter Adress :- ");
    fgets(address, 1000, stdin);
    printf("Enter Initial Deposit :- ");
    scanf("%d", &init_dep);

    printf("\n");
    printf("Your account Number is :- "); // Some random gen 4 digit num
    printf("\n");

    printf("Your Account has been created Successfully !!");
}

void adm_login(){

}

void login(){
    printf("=================================\n");
    printf("              LOGIN              \n");
    printf("=================================\n\n");
    
    int acc_num, pin;
    printf("Enter Account Number :- ");
    scanf("%d", &acc_num);
    printf("Enter PIN :- "); // Should be star coded
    scanf("%d", &pin);

}

void exit_program(){
    printf("=================================\n");
    printf(" THANK YOU FOR USING SECUREBANK  \n");
    printf("=================================\n\n");
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
    printf("3. Admin Login\n");
    printf("4. Exit \n\n");

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
        adm_login();
    }
    if(choice1 == 4){
        exit_program();
    }
}