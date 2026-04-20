#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define RED        "\033[1;31m"
#define GREEN      "\033[1;32m"
#define YELLOW     "\033[1;33m"
#define RESET      "\033[0m"
#define BLUE       "\033[1;34m"
#define DEEP_ROYAL "\x1b[38;2;0;35;102m"

// ── FILE PATHS ───────────────────────────────────────────────
#define DB_PATH    "accounts.txt"
#define TEMP_PATH  "temp.txt"
#define TEMP2_PATH "temp1.txt"

// ============================================================
//               ENCRYPTION / DECRYPTION SYSTEM
// ============================================================
#define KEY_LEN 8
static const unsigned char ENC_KEY[KEY_LEN] = {
    0x5A, 0x3F, 0x71, 0xC2, 0x88, 0x14, 0xE9, 0x4D
};

void xor_cipher(char *data, int len) {
    for (int i = 0; i < len; i++) {
        if (data[i] == '\n') continue;
        data[i] ^= ENC_KEY[i % KEY_LEN];
    }
}

void write_encrypted(FILE *fptr, const char *plaintext) {
    int len = strlen(plaintext);
    char *buf = (char *)malloc(len + 1);
    if (!buf) return;
    memcpy(buf, plaintext, len + 1);
    xor_cipher(buf, len);
    fwrite(buf, 1, len, fptr);
    free(buf);
}

int read_encrypted_line(FILE *fptr, char *out_buf, int max_len) {
    int i = 0, c;
    while (i < max_len - 1) {
        c = fgetc(fptr);
        if (c == EOF) { if (i == 0) return 0; break; }
        out_buf[i++] = (char)c;
        if (c == '\n') break;
    }
    out_buf[i] = '\0';
    xor_cipher(out_buf, i);
    return 1;
}

int parse_record(const char *line, int *acc_num, int *pin,
                 char *first_name, char *last_name,
                 int *age, long long *phone, float *amount) {
    return (sscanf(line, "%d %d %s %s %d %lld %f",
                   acc_num, pin, first_name, last_name,
                   age, phone, amount) == 7);
}

void build_record(char *buf, int buf_size, int acc_num, int pin,
                  const char *first_name, const char *last_name,
                  int age, long long phone, float amount) {
    snprintf(buf, buf_size, "%d %d %s %s %d %lld %.2f\n",
             acc_num, pin, first_name, last_name, age, phone, amount);
}

void rewrite_from_temp(const char *temp_path) {
    remove(DB_PATH);
    rename(temp_path, DB_PATH);
}
// ============================================================

void login();
void exit_program();
void splash();
void main_menu();
void dashboard(int, int, char[], char[], float);
void acc_creation();
void eadmin();
void admin();

// Flush leftover \n and other chars from stdin
void flush_stdin() {
    int c;
    // Clears EVERYTHING currently in the buffer until it's empty
    while ((c = getchar()) != '\n' && c != EOF);
}
// Print a press-enter prompt and wait
void press_enter() {
    printf("Press " GREEN "Enter" RESET " to continue...");
    flush_stdin();
}

// ============================================================
int main() {
    SetConsoleOutputCP(CP_UTF8);
    splash();
    return 0;
}


void splash() {
    printf("\n ");
    printf(GREEN);
    printf("  ██████  ███████  ██████  ██    ██ ██████  ███████     ██████   █████  ███    ██ ██   ██ \n");
    printf(" ██       ██      ██       ██    ██ ██   ██ ██          ██   ██ ██   ██ ████   ██ ██  ██  \n");
    printf("  █████   █████   ██       ██    ██ ██████  █████       ██████  ███████ ██ ██  ██ █████   \n");
    printf("      ██  ██      ██       ██    ██ ██   ██ ██          ██   ██ ██   ██ ██  ██ ██ ██  ██  \n");
    printf(" ███████  ███████  ██████   ██████  ██   ██ ███████     ██████  ██   ██ ██   ████ ██   ██ \n");
    printf(RESET);
    printf(YELLOW "                              \n\t\t----- Your trusted banking partner -----\n" BLUE);
    printf("\n                ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n");
    printf(  "                ▒▒▒      Secure Banking Utility     ▒▒▒\n");
    printf(  "                ▒▒▒          Developed in C         ▒▒▒\n");
    printf(  "                ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n\n");
    printf(RESET "                        Loading System " RESET);
    Sleep(500); printf(".");
    Sleep(500); printf(".");
    Sleep(500); printf(".");
    Sleep(500);
    printf("\n                     Press " GREEN "Enter " RESET "to continue...");
    flush_stdin();
    main_menu();
}


void main_menu() {
    system("cls");
    int choice1 = 0;

    printf("\n");
    printf(GREEN "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n");
    printf(      "▒▒▒           MAIN MENU             ▒▒▒\n");
    printf(      "▒▒▒    Choose One Of The Options!   ▒▒▒\n");
    printf(      "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n\n" RESET);

    printf(BLUE "1. Create New Account\n");
    printf("2. Login to Existing Account\n");
    printf("3. Admin Login\n");
    printf("4. Exit\n\n" RESET);

    printf(YELLOW "Enter your choice :- " RESET);
    scanf("%d", &choice1);
    printf("\n");

    // FIX 1+2: Validate full range 1-4, not just > 4
    if (choice1 < 1 || choice1 > 4) {
        printf(RED "Invalid option! Please enter 1, 2, 3, or 4.\n" RESET);
        Sleep(1000);
        main_menu();
        return; // FIX 1: return prevents fall-through to switch
    }

    printf("Please Wait");
    Sleep(500); printf(".");
    Sleep(500); printf(".");
    Sleep(500); printf(". \n");

    switch (choice1) {
        case 1: acc_creation(); break;
        case 2: login();        break;
        case 3: admin();        break;
        case 4: exit_program(); break;
    }
}


void acc_creation() {
    system("cls");
    printf(GREEN "\n▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n");
    printf(       "▒▒         CREATE ACCOUNT        ▒▒\n");
    printf(       "▒▒     Enter Your Credentials !  ▒▒\n");
    printf(       "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n\n" RESET);

    char first_name[100], last_name[100], address[500];
    int age, pin;
    long long phone;
    float amount;

    flush_stdin(); // FIX: clear buffer before fgets

    printf(BLUE "Enter First Name      : " RESET);
    fgets(first_name, sizeof(first_name), stdin);
    first_name[strcspn(first_name, "\n")] = '\0';

    printf(BLUE "Enter Last Name       : " RESET);
    fgets(last_name, sizeof(last_name), stdin);
    last_name[strcspn(last_name, "\n")] = '\0';

    printf(BLUE "Enter Address         : " RESET);
    fgets(address, sizeof(address), stdin);
    address[strcspn(address, "\n")] = '\0';

    printf(BLUE "Enter Age             : " RESET);
    scanf("%d", &age);

    printf(BLUE "Enter Phone Number    : " RESET);
    scanf("%lld", &phone);

    printf("Set Security PIN      : ");
    scanf("%d", &pin);

    // FIX 11: Validate initial deposit — must be positive
    do {
        printf("Enter Initial Deposit : ");
        scanf("%f", &amount);
        if (amount < 0) printf(RED "Deposit cannot be negative. Try again.\n" RESET);
    } while (amount < 0);

    printf("\n------------------------------------\n\n");
    printf("Creating Account");
    Sleep(1000); printf(". ");
    Sleep(1000); printf(". ");
    Sleep(1000); printf(". ");
    Sleep(1000);

    // FIX 10: Check for duplicate account number before saving
    srand((unsigned int)time(NULL));
    int acc_num, duplicate;
    do {
        acc_num = (rand() % 90000) + 10000;
        duplicate = 0;
        FILE *check = fopen(DB_PATH, "rb");
        if (check) {
            char line[512]; int ea, ep, eg; long long eph; float eamt; char fn[100], ln[100];
            while (read_encrypted_line(check, line, sizeof(line)))
                if (parse_record(line, &ea, &ep, fn, ln, &eg, &eph, &eamt))
                    if (ea == acc_num) { duplicate = 1; break; }
            fclose(check);
        }
    } while (duplicate);

    // FIX 14: NULL-check fopen
    FILE *fptr = fopen(DB_PATH, "ab");
    if (!fptr) {
        printf(RED "\nERROR: Could not open database at:\n%s\n" RESET, DB_PATH);
        press_enter();
        main_menu();
        return;
    }
    char record[512];
    build_record(record, sizeof(record), acc_num, pin, first_name, last_name, age, phone, amount);
    write_encrypted(fptr, record);
    fclose(fptr);

    printf(GREEN "\nAccount Created Successfully!\n\n" RESET);
    printf(YELLOW "Your Account Number : %d\n\n" RESET, acc_num);
    printf("Press Enter to open your Dashboard...");
    flush_stdin();
    dashboard(acc_num, pin, first_name, last_name, amount);
}

// ============================================================
void login() {
    system("cls");
    printf(GREEN "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n");
    printf(      "▒▒▒       Login To Your Account     ▒▒▒\n");
    printf(      "▒▒▒             Sign In             ▒▒▒\n");
    printf(      "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n\n" RESET);

    int ue_pin, ue_acc_num;
    printf("Enter Account Number : ");
    scanf("%d", &ue_acc_num);
    printf("Enter PIN            : ");
    scanf("%d", &ue_pin);
    printf("\n------------------------------\n\n");
    printf(BLUE "Verifying Credentials...\n\n" RESET);
    Sleep(800);

    char first_name[100], last_name[100], line[512];
    int age, pin, acc_num;
    long long phone;
    float amount;

    FILE *fptr = fopen(DB_PATH, "rb");
    if (!fptr) {
        printf(RED "No accounts database found.\n" RESET);
        Sleep(1500);
        main_menu();
        return;
    }

    int found = 0;
    while (read_encrypted_line(fptr, line, sizeof(line))) {
        if (parse_record(line, &acc_num, &pin, first_name, last_name, &age, &phone, &amount)) {
            if (ue_acc_num == acc_num && ue_pin == pin) { found = 1; break; }
        }
    }
    fclose(fptr);

    if (!found) {
        printf(RED "Invalid Account Number or PIN.\n" RESET);
        Sleep(1000);
        // FIX 13: Offer retry instead of just dumping to main menu
        char retry;
        printf("Try again? (y/n) : ");
        scanf(" %c", &retry);
        if (retry == 'y' || retry == 'Y') login();
        else main_menu();
        return;
    }

    system("cls");
    printf(GREEN "Login Successful!\nRedirecting to Dashboard...\n" RESET);
    Sleep(1500);
    dashboard(acc_num, pin, first_name, last_name, amount);
}

// ============================================================
void exit_program() {
    system("cls");
    printf(YELLOW "           ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n");
    printf(       "            ▒▒▒                                         ▒▒▒\n");
    printf(       "             ▒▒▒      " GREEN "THANK YOU FOR USING SECUREBANK" YELLOW "     ▒▒▒\n");
    printf(       "              ▒▒▒                                         ▒▒▒\n");
    printf(       "               ▒▒▒      " BLUE "Your trusted banking partner " YELLOW "      ▒▒▒\n");
    printf(       "                ▒▒▒                                         ▒▒▒\n");
    printf(       "                 ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n" RESET);
    Sleep(500);
    printf("\n                            Closing Programme");
    Sleep(500); printf(".");
    Sleep(500); printf(".");
    Sleep(500); printf(".");
    Sleep(500);
    exit(0);
}

// ============================================================
void admin() {
    char code[50];
    // FIX 3b: Use string comparison, not floating-point == for password
    printf(RED "Enter Admin Password : " RESET);
    scanf("%49s", code);
    if (strcmp(code, "securebank2024") == 0) {
        eadmin();
    } else {
        printf(RED "\nWRONG Password.\n" RESET);
        char retry;
        printf("Try again? (y/n) : ");
        scanf(" %c", &retry);
        if (retry == 'y' || retry == 'Y') admin();
        else main_menu();
    }
}

// ============================================================
void eadmin() {
    system("cls");
    FILE *fptr = fopen(DB_PATH, "rb");
    if (!fptr) {
        printf(RED "No database found.\n" RESET);
        press_enter();
        main_menu(); // FIX 4: always navigate somewhere
        return;
    }

    int acc, p, age;
    long long ph;
    float bal;
    char fn[100], ln[100], line[512];

    printf(GREEN "============================================================\n");
    printf(      "                     ALL ACCOUNTS                          \n");
    printf(      "============================================================\n\n" RESET);

    int i = 1;
    while (read_encrypted_line(fptr, line, sizeof(line))) {
        if (parse_record(line, &acc, &p, fn, ln, &age, &ph, &bal)) {
            printf(YELLOW "#%d\n" RESET, i);
            printf("  Account No : %d\n",   acc);
            printf("  Name       : %s %s\n", fn, ln);
            printf("  Age        : %d\n",   age);
            printf("  Phone      : %lld\n", ph);
            printf("  Balance    : %.2f\n", bal);
            printf("  PIN        : %d\n",   p);
            printf(GREEN "------------------------------------------------------------\n" RESET);
            i++;
        }
    }
    if (i == 1) printf(RED "No accounts found in database.\n" RESET);
    fclose(fptr);

    printf("\n");
    flush_stdin();
    press_enter();
    main_menu();
}

// ============================================================
void dashboard(int par_acc_num, int par_pin, char par_first_name[100], char par_last_name[100], float amt) {
    system("cls");

    // FIX 5: Always re-read balance from file so it's never stale
    {
        FILE *rf = fopen(DB_PATH, "rb");
        if (rf) {
            char line[512];
            int a, p, ag; long long ph; float bl; char fn[100], ln[100];
            while (read_encrypted_line(rf, line, sizeof(line)))
                if (parse_record(line, &a, &p, fn, ln, &ag, &ph, &bl))
                    if (a == par_acc_num && p == par_pin) { amt = bl; break; }
            fclose(rf);
        }
    }

    printf(GREEN "\n==================================\n");
    printf(      "||       USER DASHBOARD         ||\n");
    printf(      "==================================\n\n" RESET);
    printf("Welcome, " YELLOW "%s %s\n\n" RESET, par_first_name, par_last_name);

    printf(BLUE "1. Check Balance\n");
    Sleep(100); printf("2. Deposit Money\n");
    Sleep(100); printf("3. Withdraw Money\n");
    Sleep(100); printf("4. Transfer Money\n");
    Sleep(100); printf("5. Account Details\n");
    Sleep(100); printf("6. Update Account Details\n");
    Sleep(100); printf("7. Logout\n\n" RESET);

    int choice = 0;
    printf("Enter your choice :- ");
    scanf("%d", &choice);

    // ── 1. CHECK BALANCE ──────────────────────────────────────
    if (choice == 1) {
        system("cls");
        printf(GREEN "---------------------------------\n");
        printf(      "         BALANCE CHECK           \n");
        printf(      "---------------------------------\n\n" RESET);
        printf("Current Balance : " YELLOW "%.2f\n\n" RESET, amt);
        flush_stdin();
        press_enter();
        dashboard(par_acc_num, par_pin, par_first_name, par_last_name, amt);
        return;
    }

    // ── 2. DEPOSIT ────────────────────────────────────────────
    if (choice == 2) {
        system("cls");
        printf(GREEN "---------------------------------\n");
        printf(      "          DEPOSIT MONEY          \n");
        printf(      "---------------------------------\n\n" RESET);

        FILE *fptr = fopen(DB_PATH, "rb");
        FILE *temp = fopen(TEMP_PATH, "wb");
        if (!fptr || !temp) {
            printf(RED "Database error!\n" RESET);
            if (fptr) fclose(fptr); if (temp) fclose(temp);
            press_enter();
            dashboard(par_acc_num, par_pin, par_first_name, par_last_name, amt);
            return;
        }

        char first_name[100], last_name[100], line[512], record[512];
        int age, pin, acc_num; long long phone; float amount;
        int deposited = 0; // guard: ensure prompt fires exactly once

        // Collect deposit amount BEFORE entering the file-copy loop
        float add_money = 0;
        // Re-read current balance from file first so we show the correct figure
        {
            FILE *br = fopen(DB_PATH, "rb");
            if (br) {
                char bl[512]; int ba, bp, bag; long long bph; float bamt; char bfn[100], bln[100];
                while (read_encrypted_line(br, bl, sizeof(bl)))
                    if (parse_record(bl, &ba, &bp, bfn, bln, &bag, &bph, &bamt))
                        if (ba == par_acc_num && bp == par_pin) { amt = bamt; break; }
                fclose(br);
            }
        }
        printf("Current Balance : %.2f\n", amt);
        do {
            printf("Amount to deposit : ");
            if (scanf("%f", &add_money) != 1) { flush_stdin(); add_money = 0; }
            if (add_money <= 0) printf(RED "Amount must be positive.\n" RESET);
        } while (add_money <= 0);

        while (read_encrypted_line(fptr, line, sizeof(line))) {
            if (!parse_record(line, &acc_num, &pin, first_name, last_name, &age, &phone, &amount)) continue;
            if (par_acc_num == acc_num && par_pin == pin && !deposited) {
                amount += add_money;
                amt = amount;
                deposited = 1;
            }
            build_record(record, sizeof(record), acc_num, pin, first_name, last_name, age, phone, amount);
            write_encrypted(temp, record);
        }
        fclose(fptr); fclose(temp);

        if (!deposited) {
            // Account not found in file — discard temp, do not corrupt DB
            remove(TEMP_PATH);
            printf(RED "\nError: Your account was not found in the database.\n" RESET);
            press_enter();
            dashboard(par_acc_num, par_pin, par_first_name, par_last_name, amt);
            return;
        }

        rewrite_from_temp(TEMP_PATH);
        printf(GREEN "\nDeposit successful! New Balance: %.2f\n" RESET, amt);
        press_enter();
        dashboard(par_acc_num, par_pin, par_first_name, par_last_name, amt);
        return;
    }

    // ── 3. WITHDRAW ───────────────────────────────────────────
    if (choice == 3) {
        system("cls");
        printf(GREEN "---------------------------------\n");
        printf(      "         WITHDRAW MONEY          \n");
        printf(      "---------------------------------\n\n" RESET);

        FILE *fptr = fopen(DB_PATH, "rb");
        FILE *temp = fopen(TEMP_PATH, "wb");
        if (!fptr || !temp) {
            printf(RED "Database error!\n" RESET);
            if (fptr) fclose(fptr); if (temp) fclose(temp);
            press_enter();
            dashboard(par_acc_num, par_pin, par_first_name, par_last_name, amt);
            return;
        }

        char first_name[100], last_name[100], line[512], record[512];
        int age, pin, acc_num; long long phone; float amount;
        int withdrawn = 0;

        // Collect withdrawal amount BEFORE the file-copy loop
        float wd_money = 0;
        // Re-read current balance so the prompt shows the real figure
        {
            FILE *br = fopen(DB_PATH, "rb");
            if (br) {
                char bl[512]; int ba, bp, bag; long long bph; float bamt; char bfn[100], bln[100];
                while (read_encrypted_line(br, bl, sizeof(bl)))
                    if (parse_record(bl, &ba, &bp, bfn, bln, &bag, &bph, &bamt))
                        if (ba == par_acc_num && bp == par_pin) { amt = bamt; break; }
                fclose(br);
            }
        }
        printf("Current Balance : %.2f\n", amt);
        do {
            printf("Amount to withdraw : ");
            // FIX: flush on non-numeric input so scanf doesn't spin forever
            if (scanf("%f", &wd_money) != 1) { flush_stdin(); wd_money = 0; continue; }
            if (wd_money <= 0)
                printf(RED "Amount must be positive.\n" RESET);
            else if (wd_money > amt)
                printf(RED "Insufficient balance! You only have %.2f\n" RESET, amt);
        } while (wd_money <= 0 || wd_money > amt);

        while (read_encrypted_line(fptr, line, sizeof(line))) {
            if (!parse_record(line, &acc_num, &pin, first_name, last_name, &age, &phone, &amount)) continue;
            if (par_acc_num == acc_num && par_pin == pin && !withdrawn) {
                amount -= wd_money;
                amt = amount;
                withdrawn = 1;
            }
            build_record(record, sizeof(record), acc_num, pin, first_name, last_name, age, phone, amount);
            write_encrypted(temp, record);
        }
        fclose(fptr); fclose(temp);

        if (!withdrawn) {
            remove(TEMP_PATH);
            printf(RED "\nError: Your account was not found in the database.\n" RESET);
            press_enter();
            dashboard(par_acc_num, par_pin, par_first_name, par_last_name, amt);
            return;
        }

        rewrite_from_temp(TEMP_PATH);
        printf(GREEN "\nWithdrawal successful! New Balance: %.2f\n" RESET, amt);
        press_enter();
        dashboard(par_acc_num, par_pin, par_first_name, par_last_name, amt);
        return;
    }

    // ── 4. TRANSFER ───────────────────────────────────────────
    if (choice == 4) {
        system("cls");
        printf(GREEN "---------------------------------\n");
        printf(      "         TRANSFER MONEY          \n");
        printf(      "---------------------------------\n\n" RESET);

        int ue2_acc_num;
        float money_t;
        printf("Recipient Account Number : ");
        scanf("%d", &ue2_acc_num);

        // FIX: prevent self-transfer
        if (ue2_acc_num == par_acc_num) {
            printf(RED "Cannot transfer to your own account.\n" RESET);
            press_enter();
            dashboard(par_acc_num, par_pin, par_first_name, par_last_name, amt);
            return;
        }

        printf("Amount to transfer       : ");
        scanf("%f", &money_t);
        if (money_t <= 0) {
            printf(RED "Amount must be positive.\n" RESET);
            press_enter();
            dashboard(par_acc_num, par_pin, par_first_name, par_last_name, amt);
            return;
        }

        char first_name[100], last_name[100], line[512], record[512];
        int age, pin, acc_num; long long phone; float amount;

        // ── SAFETY CHECK: Verify recipient account EXISTS before touching any money ──
        // This prevents the "money gone but not credited" bug entirely.
        {
            FILE *chk = fopen(DB_PATH, "rb");
            if (chk) {
                int found_r = 0;
                char cl[512]; int ca, cp, cag; long long cph; float camt; char cfn[100], cln[100];
                while (read_encrypted_line(chk, cl, sizeof(cl)))
                    if (parse_record(cl, &ca, &cp, cfn, cln, &cag, &cph, &camt))
                        if (ca == ue2_acc_num) { found_r = 1; break; }
                fclose(chk);
                if (!found_r) {
                    printf(RED "Recipient account %d does not exist. Transfer cancelled.\n" RESET, ue2_acc_num);
                    press_enter();
                    dashboard(par_acc_num, par_pin, par_first_name, par_last_name, amt);
                    return;
                }
            }
        }

        // Pass 1: deduct from sender
        FILE *fptr = fopen(DB_PATH, "rb");
        FILE *temp = fopen(TEMP_PATH, "wb");
        if (!fptr || !temp) {
            printf(RED "Database error!\n" RESET);
            if (fptr) fclose(fptr); if (temp) fclose(temp);
            press_enter();
            dashboard(par_acc_num, par_pin, par_first_name, par_last_name, amt);
            return;
        }

        while (read_encrypted_line(fptr, line, sizeof(line))) {
            if (!parse_record(line, &acc_num, &pin, first_name, last_name, &age, &phone, &amount)) continue;
            if (par_acc_num == acc_num) {
                if (money_t > amount) {
                    printf(RED "Insufficient balance! You have %.2f\n" RESET, amount);
                    fclose(fptr); fclose(temp);
                    remove(TEMP_PATH);
                    press_enter();
                    dashboard(par_acc_num, par_pin, par_first_name, par_last_name, amt);
                    return;
                }
                amount -= money_t;
                amt = amount;
            }
            build_record(record, sizeof(record), acc_num, pin, first_name, last_name, age, phone, amount);
            write_encrypted(temp, record);
        }
        fclose(fptr); fclose(temp);
        rewrite_from_temp(TEMP_PATH);

        // Pass 2: credit recipient (safe — we already confirmed recipient exists above)
        char fn1[100], ln1[100];
        int age1, pin1, acc_num1; long long phone1; float amount1;

        FILE *fptr2 = fopen(DB_PATH, "rb");
        FILE *temp2 = fopen(TEMP2_PATH, "wb");
        if (!fptr2 || !temp2) {
            // Pass 1 already committed — money was deducted. Warn loudly.
            printf(RED "CRITICAL ERROR: Deduction succeeded but credit failed (DB open error).\n");
            printf("Please contact support. Amount lost: %.2f\n" RESET, money_t);
            if (fptr2) fclose(fptr2);
            if (temp2) fclose(temp2);
            press_enter();
            dashboard(par_acc_num, par_pin, par_first_name, par_last_name, amt);
            return;
        }

        int recipient_found = 0;
        while (read_encrypted_line(fptr2, line, sizeof(line))) {
            if (!parse_record(line, &acc_num1, &pin1, fn1, ln1, &age1, &phone1, &amount1)) continue;
            if (acc_num1 == ue2_acc_num) { amount1 += money_t; recipient_found = 1; }
            build_record(record, sizeof(record), acc_num1, pin1, fn1, ln1, age1, phone1, amount1);
            write_encrypted(temp2, record);
        }
        fclose(fptr2); fclose(temp2);
        rewrite_from_temp(TEMP2_PATH);

        // recipient_found will always be 1 here (pre-checked above), but kept as a guard
        if (!recipient_found)
            printf(RED "WARNING: Recipient account %d not credited. Contact support.\n" RESET, ue2_acc_num);
        else
            printf(GREEN "Transfer of %.2f to account %d successful!\nYour new balance: %.2f\n" RESET,
                   money_t, ue2_acc_num, amt);

        press_enter();
        dashboard(par_acc_num, par_pin, par_first_name, par_last_name, amt);
        return;
    }

    // ── 5. ACCOUNT DETAILS ────────────────────────────────────
    if (choice == 5) {
        system("cls");
        printf(GREEN "---------------------------------\n");
        printf(      "         ACCOUNT DETAILS         \n");
        printf(      "---------------------------------\n\n" RESET);

        FILE *fptr = fopen(DB_PATH, "rb");
        if (!fptr) {
            printf(RED "Database error!\n" RESET);
            press_enter();
            dashboard(par_acc_num, par_pin, par_first_name, par_last_name, amt);
            return;
        }

        char first_name[100], last_name[100], line[512];
        int age, pin, acc_num; long long phone; float amount;
        int found = 0;

        while (read_encrypted_line(fptr, line, sizeof(line))) {
            if (!parse_record(line, &acc_num, &pin, first_name, last_name, &age, &phone, &amount)) continue;
            if (par_pin == pin && par_acc_num == acc_num) {
                printf("Account Number : %d\n",    acc_num);
                printf("Name           : %s %s\n", first_name, last_name);
                printf("Age            : %d\n",    age);
                printf("Phone          : %lld\n",  phone);
                printf("Balance        : %.2f\n",  amount);
                found = 1;
                break;
            }
        }
        fclose(fptr); // FIX 7: fclose BEFORE calling dashboard, not after return

        if (!found) printf(RED "Account not found.\n" RESET);
        flush_stdin();
        press_enter();
        dashboard(par_acc_num, par_pin, par_first_name, par_last_name, amt);
        return;
    }

    // ── 6. UPDATE ACCOUNT DETAILS ─────────────────────────────
    if (choice == 6) {
        system("cls");
        printf(GREEN "---------------------------------\n");
        printf(      "      UPDATE ACCOUNT DETAILS     \n");
        printf(      "---------------------------------\n\n" RESET);

        printf(YELLOW "1. Edit First Name\n");
        printf("2. Edit Last Name\n");
        printf("3. Edit Phone Number\n");
        printf("4. Back to Dashboard\n\n" RESET);

        int changeOpt = 0; // FIX 9: declared and initialized here, not at top of dashboard
        printf("Enter option : ");
        scanf("%d", &changeOpt);

        if (changeOpt == 4) {
            dashboard(par_acc_num, par_pin, par_first_name, par_last_name, amt);
            return;
        }
        if (changeOpt < 1 || changeOpt > 3) {
            printf(RED "Invalid option.\n" RESET);
            press_enter();
            dashboard(par_acc_num, par_pin, par_first_name, par_last_name, amt);
            return;
        }

        int trypin;
        printf("Re-enter PIN to confirm : ");
        scanf("%d", &trypin);
        if (trypin != par_pin) {
            printf(RED "Wrong PIN. Update cancelled.\n" RESET);
            Sleep(1500);
            dashboard(par_acc_num, par_pin, par_first_name, par_last_name, amt);
            return;
        }

        // FIX 8: collect new value BEFORE opening files — not inside the read loop
        char new_value[200] = {0};
        flush_stdin();
        if (changeOpt == 1) {
            printf(BLUE "Enter New First Name   : " RESET);
        } else if (changeOpt == 2) {
            printf(BLUE "Enter New Last Name    : " RESET);
        } else {
            printf(BLUE "Enter New Phone Number : " RESET);
        }
        fgets(new_value, sizeof(new_value), stdin);
        new_value[strcspn(new_value, "\n")] = '\0';

        char first_name[100], last_name[100], line[512], record[512];
        int age2, pin2, acc_num2; long long phone2; float amount2;

        FILE *original = fopen(DB_PATH, "rb");
        FILE *temp     = fopen(TEMP_PATH, "wb");
        if (!original || !temp) {
            printf(RED "Database error!\n" RESET);
            if (original) fclose(original);
            if (temp)     fclose(temp);
            press_enter();
            dashboard(par_acc_num, par_pin, par_first_name, par_last_name, amt);
            return;
        }

        while (read_encrypted_line(original, line, sizeof(line))) {
            if (!parse_record(line, &acc_num2, &pin2, first_name, last_name, &age2, &phone2, &amount2)) continue;
            if (acc_num2 == par_acc_num) {
                if (changeOpt == 1)
                    build_record(record, sizeof(record), acc_num2, pin2, new_value, last_name, age2, phone2, amount2);
                else if (changeOpt == 2)
                    build_record(record, sizeof(record), acc_num2, pin2, first_name, new_value, age2, phone2, amount2);
                else
                    build_record(record, sizeof(record), acc_num2, pin2, first_name, last_name, age2, atoll(new_value), amount2);
            } else {
                build_record(record, sizeof(record), acc_num2, pin2, first_name, last_name, age2, phone2, amount2);
            }
            write_encrypted(temp, record);
        }
        fclose(original);
        fclose(temp);
        rewrite_from_temp(TEMP_PATH);

        // Update in-memory name so dashboard header reflects change immediately
        if (changeOpt == 1) strncpy(par_first_name, new_value, 99);
        if (changeOpt == 2) strncpy(par_last_name,  new_value, 99);

        printf(GREEN "\nRecord Updated Successfully!\n" RESET);
        Sleep(1000);
        dashboard(par_acc_num, par_pin, par_first_name, par_last_name, amt); // FIX 12
        return;
    }

    // ── 7. LOGOUT ─────────────────────────────────────────────
    if (choice == 7) {
        printf("\n");
        printf(GREEN "Logged out successfully!\n" RESET);
        Sleep(1500);
        main_menu();
        return;
    }

    // FIX 12: Catch-all for invalid dashboard choice (e.g. 0, 8, 99...)
    printf(RED "Invalid choice. Please enter 1-7.\n" RESET);
    press_enter();
    dashboard(par_acc_num, par_pin, par_first_name, par_last_name, amt);
}
