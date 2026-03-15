#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void login();
void exit_program();
void splash();
void main_menu();
void dashboard(int, int, char[], char[]);
void acc_creation();

int main(){
    splash();
}

void login(){
    printf("\n=================================\n");
    printf("||              LOGIN          ||\n");
    printf("=================================\n\n");
    
    int ue_pin, ue_acc_num;

    printf("Enter Account Number : ");
    scanf("%d", &ue_acc_num);

    printf("Enter PIN            : ");
    scanf("%d", &ue_pin);
    printf("\n------------------------------\n\n");
    printf("Verifying Credentials... \n\n");

    char first_name[1000], address[2000], last_name[1000];
    int age, phone, pin, acc_num;
    float amount;

    FILE *fptr;

    int found = 0;
    fptr = fopen("accounts.txt", "r");
    while(fscanf(fptr, "%d %d %s %s %d %d %f", &acc_num, &pin, first_name, last_name, &age, &phone, &amount) != EOF){
            if(ue_acc_num == acc_num && ue_pin == pin){
                found = 1;
                printf("Login Successful\n");
                printf("Redirecting to the Dashboard...\n");
                dashboard(acc_num, pin, first_name, last_name);
            }
    }
    if(found == 0){
        printf("Invalid Account Number or PIN\n");
        printf("Try Again");
        main_menu();
    }
}

void exit_program(){
    printf("\n=========================================\n");
    printf("||                                     ||\n");
    printf("||    THANK YOU FOR USING SECUREBANK   ||\n");
    printf("||                                     ||\n");
    printf("||     Your trusted banking partner    ||\n");
    printf("||                                     ||\n");
    printf("=========================================\n\n");
}

void main_menu(){
    int choice1 = 0;

    // Intro UI of Banking System
    printf("\n");
    printf("=========================================\n");
    printf("||               MAIN MENU             ||\n");
    printf("=========================================\n\n");

    printf("1. Create New Account\n");
    printf("2. Login to existing account\n");
    printf("3. Admin Login :- \n");
    printf("4. Exit \n\n");

    printf("-----------------------------------------\n");
    printf("Enter your choice :- ");
    scanf("%d", &choice1);
    printf("\n");

    switch(choice1){
        case 1: acc_creation(); break;
        case 2: login(); break;
        //case 3: adm_login(); break;
        case 4: exit_program(); break;
    }
}

void dashboard(int par_acc_num, int par_pin, char par_first_name[1000], char par_last_name[1000]){
    printf("\n");
    printf("==================================\n");
    printf("||          USER DASHBOARD      ||\n");
    printf("==================================\n\n");

    printf("Welcome, %s %s\n", par_first_name, par_last_name);

    printf("1. Check Balance\n"); //
    printf("2. Deposit Money\n"); //
    printf("3. Withdraw Money\n"); //
    printf("4. Transfer Money\n"); //
    printf("5. Account Details\n"); //
    printf("6. Update Account Details\n"); 
    printf("7. Logout\n\n"); //

    int choice = 0;
    printf("Enter your choice :- ");
    scanf("%d", &choice);

    if(choice == 5){
        // Code for account details display
        FILE *fptr;
        fptr = fopen("accounts.txt", "r");
        char first_name[1000], address[2000], last_name[1000];
        int age, pin, acc_num;
        long long phone;
        float amount;

        printf("---------------------------------\n");
        printf("          ACCOUNT DETAILS        \n");
        printf("---------------------------------\n\n");
        while(fscanf(fptr, "%d %d %s %s %d %lld %f", &acc_num, &pin, first_name, last_name, &age, &phone, &amount) != EOF){
            if(par_pin == pin && par_acc_num == acc_num){
                printf("Account Number :- %d\n", acc_num);
                printf("Name :- %s %s\n", first_name, last_name);
                printf("Age :- %d\n", age);
                printf("Phone :- %lld\n", phone);
                printf("Amount :- %.2f\n", amount);

                char res;
                printf("Press 'b' to go back :- ");
                scanf(" %c", &res);
                if(res =='b'){
                    dashboard(acc_num, pin, first_name, last_name);
                }
            }
        }
    }

    if(choice == 2){
        // Code for depositing money 
        FILE *fptr, *temp;
        fptr = fopen("accounts.txt", "r");
        temp = fopen("temp.txt", "w");
        char first_name[1000], address[2000], last_name[1000];
        int age, pin, acc_num;
        long long phone;
        float amount;

        printf("---------------------------------\n");
        printf("           DEPOSIT MONEY         \n");
        printf("---------------------------------\n\n");
        while(fscanf(fptr, "%d %d %s %s %d %lld %f", &acc_num, &pin, first_name, last_name, &age, &phone, &amount) != EOF){
            if(par_pin == pin && par_acc_num == acc_num){
                float add_money;
                printf("Current amount in account :- %f\n", amount);
                printf("Enter amount of money to be added :- ");
                scanf("%f", &add_money);
                amount = amount + add_money;
            }
            fprintf(temp, "%d %d %s %s %d %lld %f", acc_num, pin, first_name, last_name, age, phone, amount);
        }
        fclose(temp); fclose(fptr);
        printf("Amount deposited successfully !\n");
        remove("accounts.txt");
        rename("temp.txt", "accounts.txt");

        char res;
        printf("Press 'b' to go back :- ");
        scanf(" %c", &res);
        if(res =='b'){
            dashboard(acc_num, pin, first_name, last_name);
        }
    }

    if(choice == 3){
        // Code for Withdrawing money 
        FILE *fptr, *temp;
        fptr = fopen("accounts.txt", "r");
        temp = fopen("temp.txt", "w");
        char first_name[1000], address[2000], last_name[1000];
        int age, pin, acc_num;
        long long phone;
        float amount;

        printf("---------------------------------\n");
        printf("           WITHDRAW MONEY        \n");
        printf("---------------------------------\n\n");
        while(fscanf(fptr, "%d %d %s %s %d %lld %f", &acc_num, &pin, first_name, last_name, &age, &phone, &amount) != EOF){
            if(par_pin == pin && par_acc_num == acc_num){
                float wd_money;
                printf("Current amount in account :- %f\n", amount);
                printf("Enter amount of money to be withdrawn :- ");
                scanf("%f", &wd_money);
                amount = amount - wd_money;
            }
            fprintf(temp, "%d %d %s %s %d %lld %f", acc_num, pin, first_name, last_name, age, phone, amount);
        }
        fclose(temp); fclose(fptr);
        printf("Amount withdraw successfully !\n");
        remove("accounts.txt");
        rename("temp.txt", "accounts.txt");

        char res;
        printf("Press 'b' to go back :- ");
        scanf(" %c", &res);
        if(res =='b'){
            dashboard(acc_num, pin, first_name, last_name);
        }
    }

    if(choice == 1){
        // Code for checking balance 
        FILE *fptr;
        fptr = fopen("accounts.txt", "r");
        char first_name[1000], address[2000], last_name[1000];
        int age, pin, acc_num;
        long long phone;
        float amount;

        printf("---------------------------------\n");
        printf("           BALANCE CHECK         \n");
        printf("---------------------------------\n\n");
        while(fscanf(fptr, "%d %d %s %s %d %lld %f", &acc_num, &pin, first_name, last_name, &age, &phone, &amount) != EOF){
            if(par_pin == pin && par_acc_num == acc_num){
                printf("Current amount in account :- %f\n", amount);
            }
        }

        char res;
        printf("Press 'b' to go back :- ");
        scanf(" %c", &res);
        if(res =='b'){
            dashboard(acc_num, pin, first_name, last_name);
        }
    }

    if(choice == 7){
        // Code for Logging out 
        FILE *fptr, *temp;
        fptr = fopen("accounts.txt", "r");
        temp = fopen("temp.txt", "w");
        char first_name[1000], address[2000], last_name[1000];
        int age, pin, acc_num;
        long long phone;
        float amount;

        printf("---------------------------------\n");
        printf("              LOGOUT             \n");
        printf("---------------------------------\n\n");
        while(fscanf(fptr, "%d %d %s %s %d %lld %f", &acc_num, &pin, first_name, last_name, &age, &phone, &amount) != EOF){
            if(par_pin != pin || par_acc_num != acc_num){
                fprintf(temp, "\n%d %d %s %s %d %lld %f", acc_num, pin, first_name, last_name, age, phone, amount);
            }else{
                continue;
            }
        }
        fclose(temp); fclose(fptr);
        printf("Logged out successfully !\n");
        remove("accounts.txt");
        rename("temp.txt", "accounts.txt");

        main_menu();
    }

    if(choice == 4){
        // Code for transferring money // Create different variables for age, pin and etc for both the cases and then done
        FILE *fptr, *temp;
        fptr = fopen("accounts.txt", "r");
        temp = fopen("temp.txt", "w");
        char first_name[1000], address[2000], last_name[1000];
        int age, pin, acc_num;
        long long phone;
        float amount;

        printf("---------------------------------\n");
        printf("          TRANSFER MONEY         \n");
        printf("---------------------------------\n\n");

        //int ue1_acc_num, ue1_pin;
        int ue2_acc_num, ue2_pin;
        float money_t;

        printf("Enter Account Number :- ");
        scanf("%d", &ue2_acc_num);
        printf("Enter amount of money to be transferred :- ");
        scanf("%f", &money_t);
        
        while(fscanf(fptr, "%d %d %s %s %d %lld %f", &acc_num, &pin, first_name, last_name, &age, &phone, &amount) != EOF){
            if(par_acc_num == acc_num){
                amount = amount - money_t;
            }
            fprintf(temp, "\n%d %d %s %s %d %lld %f", acc_num, pin, first_name, last_name, age, phone, amount);
        }
        fclose(temp); fclose(fptr);
        remove("accounts.txt");
        rename("temp.txt", "accounts.txt");

        char first_name1[1000], address1[2000], last_name1[1000];
        int age1, pin1, acc_num1;
        long long phone1;
        float amount1;

        FILE *fptr2, *temp2;
        fptr2 = fopen("accounts.txt", "r");
        temp2 = fopen("temp1.txt", "w");
        while(fscanf(fptr2, "%d %d %s %s %d %lld %f", &acc_num1, &pin1, first_name1, last_name1, &age1, &phone1, &amount1) != EOF){
            if(acc_num1 == ue2_acc_num){
                amount1 = amount1 + money_t;
            }
            fprintf(temp2, "\n%d %d %s %s %d %lld %f", acc_num1, pin1, first_name1, last_name1, age1, phone1, amount1);
        }
        fclose(temp2); fclose(fptr2);
        remove("accounts.txt");
        rename("temp1.txt", "accounts.txt");

        printf("Amount is transmitted to account number %d\n", ue2_acc_num);

        char res;
        printf("Press 'b' to go back :- ");
        scanf(" %c", &res);
        if(res =='b'){
            dashboard(acc_num, pin, first_name, last_name);
        }
    }

}

void acc_creation(){
    printf("\n=====================================\n");
    printf("||          CREATE ACCOUNT         ||\n");
    printf("=====================================\n\n");

    char first_name[1000], last_name[1000], address[2000];
    int age, pin;
    long long phone;
    float amount;

    // The concept of Buffer area is used, that how does /n causes a problem
    // Keyboard → Input Buffer (stdin) → scanf()/fgets() → Your Variables
    while(getchar() != '\n');

    printf("Enter First Name      : ");
    fgets(first_name, sizeof(first_name), stdin);
    first_name[strcspn(first_name, "\n")] = '\0';

    printf("Enter Last Name       : ");
    fgets(last_name, sizeof(last_name), stdin);
    last_name[strcspn(last_name, "\n")] = '\0';

    printf("Enter Address         : ");
    fgets(address, sizeof(address), stdin);
    address[strcspn(address, "\n")] = '\0';

    printf("Enter Age             : ");
    scanf("%d", &age);

    printf("Enter Phone Number    : ");
    scanf("%lld", &phone);

    printf("\n");
    printf("Set Security PIN      : ");
    scanf("%d", &pin);

    printf("Enter Initial Deposit : ");
    scanf("%f", &amount);

    printf("\n------------------------------------\n\n");
    printf("Creating Account...\n\n");

    srand(time(NULL));
    int acc_num = (rand() % (90000)) + 10000;

    FILE *fptr;
    fptr = fopen("accounts.txt", "a");
    fprintf(fptr,"\n%d %d %s %s %d %lld %.2f\n", acc_num, pin, first_name, last_name, age, phone, amount);
    fclose(fptr);

    printf("Acount Created Successfully\n\n");
    
    printf("Your Account Number  : %d \n\n", acc_num);

    dashboard(acc_num, pin, first_name, last_name);
}

void splash(){
    printf("\n======================================\n");
    printf("||                                  ||\n");
    printf("||             SECURE BANK          ||\n");
    printf("||                                  ||\n");
    printf("||       Secure Banking Utility     ||\n");
    printf("||                                  ||\n");
    printf("======================================\n\n");

    printf("            Developed in C            \n\n");
    printf("Loading System....\n\n");

    main_menu();
}


// Testing Zone
// #include <stdio.h>
// #include <string.h>

// int main(){
//     FILE *fptr;
//     fptr = fopen("accounts.txt", "w");
//     fputs(strcat("Hello ", "World"), fptr);
// }