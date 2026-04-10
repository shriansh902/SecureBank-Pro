
    SetConsoleOutputCP(CP_UTF8);
    exit_program();
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