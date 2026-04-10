#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define GREEN1  "\083[1;32m"
#define YELLOW  "\033[1;33m"
#define RESET   "\033[0m"
#define BLUE    "\033[1;34m"
#define DEEP_ROYAL "\x1b[38;2;0;35;102m"
void login();
void exit_program();
void splash();
void main_menu();
void dashboard(int, int, char[], char[],float);
void acc_creation();
void eadmin();
void admin();


int main(){
    SetConsoleOutputCP(CP_UTF8);
    splash();
}
void splash(){
    printf("\n ");
printf(GREEN );
    // Note: All backslashes are doubled to prevent the "melting" alignment issue
    printf("  ██████  ███████  ██████  ██    ██ ██████  ███████     ██████   █████  ███    ██ ██   ██ \n");
    printf(" ██       ██      ██       ██    ██ ██   ██ ██          ██   ██ ██   ██ ████   ██ ██  ██  \n");
    printf("  █████   █████   ██       ██    ██ ██████  █████       ██████  ███████ ██ ██  ██ █████   \n");
    printf("      ██  ██      ██       ██    ██ ██   ██ ██          ██   ██ ██   ██ ██  ██ ██ ██  ██  \n");
    printf(" ███████  ███████  ██████   ██████  ██   ██ ███████     ██████  ██   ██ ██   ████ ██   ██ \n");
    printf(RESET);
    printf(YELLOW"                              \n\t\t----- Your trusted banking partner -----\n"BLUE);
    printf("\n                ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n");
    printf(  "                ▒▒▒      Secure Banking Utility     ▒▒▒\n");
    printf(  "                ▒▒▒          Developed in C         ▒▒▒\n");
    printf(  "                ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n\n");



    printf(RESET"                        Loading System "RESET);
    Sleep(1000);
    printf(". ");
    Sleep(1000);
    printf(". ");    
    Sleep(1000);
    printf(". ");
    Sleep(1000);
    printf("\n                     Press "GREEN"Enter "RESET "to continue...");
    while (getchar() != '\n'); 
    main_menu();
}
void main_menu(){
    system("cls");
    int choice1 = 0;

    // Intro UI of Banking System
    printf("\n");
    printf(GREEN "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n");
    printf(      "▒▒▒           MAIN MENU             ▒▒▒\n");
    printf(      "▒▒▒    Choose One Of The Options!   ▒▒▒\n");
    printf(      "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n\n"RESET);

    printf(BLUE"1. Create New Account\n");
    printf("2. Login to existing account\n");
    printf("3. Admin Login :- \n");
    printf("4. Exit \n\n"RESET);

    printf("\n");
    printf(YELLOW"Enter your choice :- "RESET);
    scanf("%d", &choice1);
    printf("\n");
    if (choice1 > 4 ){
        printf(RED"Enter A valid Option!"RESET);
        Sleep(1000);
        main_menu();
    }
    printf("Please Wait");
    Sleep(500);
    printf(". ");    Sleep(500);
    printf(". ");    Sleep(500);
    printf(". ");
    switch(choice1){
        case 1: acc_creation(); break;
        case 2: login(); break;
        case 3: admin(); break;
        case 4: exit_program(); break;
    }
}
void acc_creation(){
    system("cls");
    printf(GREEN"\n▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n");
    printf(       "▒▒         CREATE ACCOUNT        ▒▒\n");    
    printf(       "▒▒     Enter Your Credentials !  ▒▒\n");
    printf(       "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n\n"RESET);
    

    char first_name[1000], last_name[1000], address[2000];
    int age, pin;
    long long phone;
    float amount;

    // The concept of Buffer area is used, that how does /n causes a problem
    // Keyboard → Input Buffer (stdin) → scanf()/fgets() → Your Variables
    while(getchar() != '\n');

    printf(BLUE"Enter First Name      : "RESET);
    fgets(first_name, sizeof(first_name), stdin);
    first_name[strcspn(first_name, "\n")] = '\0';

    printf(BLUE"Enter Last Name       : "RESET);
    fgets(last_name, sizeof(last_name), stdin);
    last_name[strcspn(last_name, "\n")] = '\0';

    printf(BLUE"Enter Address         : "RESET);
    fgets(address, sizeof(address), stdin);
    address[strcspn(address, "\n")] = '\0';

    printf(BLUE"Enter Age             : "RESET);
    scanf("%d", &age);

    printf(BLUE"Enter Phone Number    : "RESET);
    scanf("%lld", &phone);

    printf("\n");
    printf("Set Security PIN      : ");
    scanf("%d", &pin);

    printf("Enter Initial Deposit : ");
    scanf("%f", &amount);

    printf("\n------------------------------------\n\n");
    printf("Creating Account");
    Sleep(1000);
    printf(". ");
    Sleep(1000);
    printf(". ");    
    Sleep(1000);
    printf(". ");
    Sleep(1000);

    srand(time(NULL));
    int acc_num = (rand() % (90000)) + 10000;

    FILE *fptr;
    fptr = fopen("accounts.txt", "a");
    fprintf(fptr,"\n%d %d %s %s %d %lld %.2f\n", acc_num, pin, first_name, last_name, age, phone, amount);
    fclose(fptr);

    printf(GREEN"Acount Created Successfully\n\n"RESET);
    
    printf(YELLOW"Your Account Number  : %d \n\n", acc_num);
    printf(RESET"Press Enter To Open Account Dashboard");
    while (getchar() != '\n'); 
    dashboard(acc_num, pin, first_name, last_name,amount);
}
void login(){
    system("cls");
    printf(GREEN "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n");
    printf(      "▒▒▒       Login To Your Account     ▒▒▒\n");
    printf(      "▒▒▒             Sign In             ▒▒▒\n");
    printf(      "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n\n"RESET);
    
    int ue_pin, ue_acc_num;

    printf("Enter Account Number : ");
    scanf("%d", &ue_acc_num);

    printf("Enter PIN            : ");
    scanf("%d", &ue_pin);
    printf("\n------------------------------\n\n");
    printf(BLUE"Verifying Credentials... \n\n"RESET);

    char first_name[1000], address[2000], last_name[1000];
    int age, pin, acc_num;
    long long phone;
    float amount;

    FILE *fptr;

    int found = 0;
    fptr = fopen("accounts.txt", "r");
    while(fscanf(fptr, "%d %d %s %s %d %lld %f", &acc_num, &pin, first_name, last_name, &age, &phone, &amount) != EOF){
            if(ue_acc_num == acc_num && ue_pin == pin){
                found = 1;
                break;
            }
    }
    if(found == 0){
        printf(RED"Invalid Account Number or PIN\n"RESET);
        Sleep(500);
        printf("Press"GREEN "Enter"RESET "Try Again");
        system("cls");
        main_menu();
    }
    if(found == 1){  
        system("cls");     
        printf(GREEN"Login Successful\n");
        printf("Redirecting to the Dashboard...\n"RESET);
        Sleep(1500);
        dashboard(acc_num, pin, first_name, last_name,amount);
    }
}

void exit_program(){
    system("cls");
    
    printf(YELLOW "           ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n");
    printf(       "            ▒▒▒                                         ▒▒▒\n");
    printf(       "             ▒▒▒      "GREEN"THANK YOU FOR USING SECUREBANK"YELLOW"     ▒▒▒\n");
    printf(       "              ▒▒▒                                         ▒▒▒\n");
    printf(       "               ▒▒▒      "BLUE"Your trusted banking partner "YELLOW"      ▒▒▒\n");
    printf(       "                ▒▒▒                                         ▒▒▒\n");
    printf(       "                 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n"RESET);

    Sleep(2000);
    printf("\n                            Closing Programme");
    Sleep(700);
    printf(".");
    Sleep(700);
    printf(".");
    Sleep(700);
    printf(".");
    Sleep(700);
    exit(0);
}
void admin(){
    system("sys");
    double k;
    double j = 1;
    printf(RED"Enter The 15 Digit Admin Entry Code: "RESET);
    scanf("%lf",&k);
    if (k == j){
        eadmin();
    }
    else{
        printf(RED"WRONG Entry Code"YELLOW" \nRetry again\n"RESET);
        Sleep(3000);
        admin();
    }
}
void eadmin() {
    FILE *fptr = fopen("accounts.txt", "r");
    if (fptr == NULL) {
        printf("No database found.\n");
        return;
    }

    int acc, p, age;
    long long ph;
    float bal;
    char fn[100], ln[100];
    printf("------------------------------------------------------------\n");
    int i = 1;
    // The loop keeps running as long as it finds 7 items per line
    while (fscanf(fptr, "%d %d %s %s %d %lld %f", &acc, &p, fn, ln, &age, &ph, &bal) != EOF) {
        printf("%d \nAccount Number:%-7d         Pin: %-4d \nUserName: %-10s %-5s \nPhone Number: %-10lld \nBalance In Account: %.2f\n", i, acc, p, fn, ln, ph, bal);
        i++;
    }

    fclose(fptr);
};

void dashboard(int par_acc_num, int par_pin, char par_first_name[1000], char par_last_name[1000], float amt){
    system("cls");
    int changeOpt;
    printf(GREEN"\n");
    printf("==================================\n");
    printf("||          USER DASHBOARD      ||\n");
    printf("==================================\n\n"RESET);

    printf("Welcome, %s %s\n", par_first_name, par_last_name);

    printf(YELLOW"1. Check Balance\n"); //
    Sleep(300);
    printf("2. Deposit Money\n"); //
    Sleep(200);
    printf("3. Withdraw Money\n"); //
    Sleep(150);
    printf("4. Transfer Money\n"); //
    Sleep(150);
    printf("5. Account Details\n"); //
    Sleep(100);
    printf("6. Update Account Details\n"); 
    Sleep(50);
    printf("7. Logout\n\n"RESET); //

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
        system("cls");

        printf(GREEN"---------------------------------\n");
        printf("          ACCOUNT DETAILS        \n");
        printf("---------------------------------\n\n"RESET);
        while(fscanf(fptr, "%d %d %s %s %d %lld %f", &acc_num, &pin, first_name, last_name, &age, &phone, &amount) != EOF){
            if(par_pin == pin && par_acc_num == acc_num){
                printf("Account Number :- %d\n", acc_num);
                printf("Name :- %s %s\n", first_name, last_name);
                printf("Age :- %d\n", age);
                printf("Phone :- %lld\n", phone);
                printf("Amount :- %.2f\n", amount);
                printf("\nPress Enter to go Back...");
                while (getchar() != '\n'); 
                system("cls");
                dashboard(par_acc_num,par_pin,par_first_name,par_last_name,amount);
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
            dashboard(acc_num, pin, first_name, last_name,amt);
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
            dashboard(acc_num, pin, first_name, last_name,amount);
        }
    }

    if(choice == 1){
        printf(GREEN"---------------------------------\n");
        printf("           BALANCE CHECK         \n");
        printf("---------------------------------\n\n"RESET);
        printf("Current amount in account :- %f\n", amt);
        Sleep(2000);
        printf("Press Enter to continue...");
        while (getchar() != '\n'); 
        system("cls");
        dashboard(par_acc_num,par_pin,par_first_name,par_last_name,amt);


  
        
    }

    if(choice == 7){
        // Code for Logging out 
        // FILE *fptr, *temp;
        // fptr = fopen("accounts.txt", "r");
        // temp = fopen("temp.txt", "w");
        // char first_name[1000], address[2000], last_name[1000];
        // int age, pin, acc_num;
        // long long phone;
        // float amount;

        // printf("---------------------------------\n");
        // printf("              LOGOUT             \n");
        // printf("---------------------------------\n\n");
        // while(fscanf(fptr, "%d %d %s %s %d %lld %f", &acc_num, &pin, first_name, last_name, &age, &phone, &amount) != EOF){
        //     if(par_pin != pin || par_acc_num != acc_num){
        //         fprintf(temp, "\n%d %d %s %s %d %lld %f", acc_num, pin, first_name, last_name, age, phone, amount);
        //     }else{
        //         continue;
        //     }
        // // }
        // fclose(temp); fclose(fptr);
        printf("Logged out successfully !\n");
        Sleep(1500);
        // remove("accounts.txt");
        // rename("temp.txt", "accounts.txt");

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
            dashboard(acc_num, pin, first_name, last_name,amt);
        }
    }

    if(choice == 6){
        char nfirst_name[1000], nlast_name[1000];
        int age,trypin;
        long long int eph,nphone;
        char ep[500];
        printf(YELLOW"1. Edit First Name\n");
        printf("2. Edit Last Name\n");
        printf("3. Edit Phone Number\n"RESET);
        printf("4. Exit\n");

        scanf("%d",&changeOpt);
        if (changeOpt!=4){
            printf("Re enter Your Pin To cofirm ");
            scanf("%d",&trypin);
            if (trypin != par_pin){
                printf(RED"Wrong Pin Entered\n"RESET);
                Sleep(1500);
                main_menu();
            }
            else{
                system("cls");
            }

        }
        else{
            system("cls");
            main_menu();
        }
    
        if (changeOpt == 1){
            while(getchar() != '\n');
            printf(BLUE"Enter First Name      : "RESET);
            fgets(nfirst_name, sizeof(nfirst_name), stdin);
            nfirst_name[strcspn(nfirst_name, "\n")] = '\0';
            int acc=par_acc_num;

            FILE *original = fopen("accounts.txt", "r");
            FILE *temp = fopen("temp.txt", "w");

            while (fscanf(original, "%d %d %s %s %d %lld %f", &par_acc_num, &par_pin, par_first_name,par_last_name, &age,&nphone,&amt) != EOF) {
                if (acc == par_acc_num) {
                    fprintf(temp, "%d %d %s %s %d %lld %f\n",par_acc_num, par_pin, nfirst_name,par_last_name, age,nphone,amt);
                    printf(BLUE"Record Updated Successfully!\n"RESET);
                } 
                else {
                    fprintf(temp, "%d %d %s %s %d %lld %.2f\n",par_acc_num, par_pin, par_first_name,par_last_name,age, nphone, amt);
                }
            }

            fclose(original);
            fclose(temp);
            remove("accounts.txt");             
            rename("temp.txt", "accounts.txt");  
            Sleep(1000);
            main_menu(); 
        }
        if (changeOpt == 2){
            printf(BLUE"Enter Last Name      : "RESET);
            fgets(nlast_name, sizeof(nlast_name), stdin);
            nlast_name[strcspn(nlast_name, "\n")] = '\0';
            int acc=par_acc_num;

            FILE *original = fopen("accounts.txt", "r");
            FILE *temp = fopen("temp.txt", "w");

            while (fscanf(original, "%d %d %s %s %d %lld %f", &par_acc_num, &par_pin, par_first_name,par_last_name, &age,&nphone,&amt) != EOF) {
                if (acc == par_acc_num) {
                    fprintf(temp, "%d %d %s %s %d %lld %f\n",par_acc_num, par_pin, par_first_name,nlast_name, age,nphone,amt);
                    printf(BLUE"Record Updated Successfully!\n"RESET);
                } 
                else {
                    fprintf(temp, "%d %d %s %s %d %lld %.2f\n",par_acc_num, par_pin, par_first_name,par_last_name,age, nphone, amt);
                }
            }

            fclose(original);
            fclose(temp);
            remove("accounts.txt");             
            rename("temp.txt", "accounts.txt");  
            Sleep(1000);
            main_menu(); 
        }
        if (changeOpt == 3){
            printf(BLUE"Enter Phone Number     : "RESET);
            fgets(ep, sizeof(1300), stdin);
            ep[strcspn(ep, "\n")] = '\0';
            int acc=par_acc_num;
            eph = atoll(ep);

            FILE *original = fopen("accounts.txt", "r");
            FILE *temp = fopen("temp.txt", "w");

            while (fscanf(original, "%d %d %s %s %d %lld %f", &par_acc_num, &par_pin, par_first_name,par_last_name, &age,&nphone,&amt) != EOF) {
                if (acc == par_acc_num) {
                    fprintf(temp, "%d %d %s %s %d %lld %f\n",par_acc_num, par_pin, par_first_name,par_last_name, age,eph,amt);
                    printf(BLUE"Record Updated Successfully!\n"RESET);
                } 
                else {
                    fprintf(temp, "%d %d %s %s %d %lld %.2f\n",par_acc_num, par_pin, par_first_name,par_last_name,age, nphone, amt);
                }
            }

            fclose(original);
            fclose(temp);
            remove("accounts.txt");             
            rename("temp.txt", "accounts.txt"); 
            Sleep(1000);
            main_menu(); 

        }
    }
}


// int main(){
//     FILE *fptr;
//     fptr = fopen("accounts.txt", "w");
//     fputs(strcat("Hello ", "World"), fptr);
// }
