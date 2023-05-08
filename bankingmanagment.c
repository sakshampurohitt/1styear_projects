#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
int ac_1 = 5738321;
int cust_no = 100, cust_avail = 0;

char admin_user[10] = "admin123";
char admin_pass[20] = "adminpass123";

int infinity = 0;

// structure of customers data
struct data
{
    int srno;
    int ac;
    char name[30];
    char phone[10];
    char pass[20];
    int age;
    char pan[10];
    float balance;
    // credit score
    int credit_s;
    float loan_amt;
    float emi;
    float bull_pay;
    float fd;
} d[100];

// BANK DEPOSIT RECIEPT
void deposit_reciept(int ac, int deposit)
{
    printf("*****************************************\n");
    printf("*                S.A.S BANK             *\n");
    printf("*****************************************\n");
    printf("*                                       *\n");
    printf("*              Deposit Reciept          *\n");
    printf("*                                       *\n");
    printf("*    Account Number: %d                 \n", ac);
    printf("*    Ammount deposited: Rs.%d           \n", deposit);
    printf("*                                       *\n");
    printf("*****************************************\n");
}

// CASH WITHDRAWAL RECIEPT
void withdraw_reciept(int ac, int withdrawal)
{
    printf("*****************************************\n");
    printf("*                S.A.S BANK             *\n");
    printf("*****************************************\n");
    printf("*                                       *\n");
    printf("*            Withdrawal Reciept         *\n");
    printf("*                                       *\n");
    printf("*    Account Number: %d\n", ac);
    printf("*    Withdrawal Amount: Rs.%d\n", withdrawal);
    printf("*                                       *\n");
    printf("*****************************************\n");
}

// MONEY TRANSFER RECIEPT
void transfer_reciept(int sender_ac, int reciever_ac, int amount, char *bank_name)
{
    printf("*****************************************\n");
    printf("*                S.A.S BANK             *\n");
    printf("*****************************************\n");
    printf("*                                       *\n");
    printf("*             Transfer Reciept          *\n");
    printf("*                                       *\n");
    printf("*    Sender Account Number: %d\n", sender_ac);
    printf("*    Reciever Account Number: %d\n", reciever_ac);
    printf("*    Withdrawal Amount: Rs.%d\n", amount);
    printf("     Bank of reciever: %s", bank_name);
    printf("*                                       *\n");
    printf("*****************************************\n");
}

// TO CHECK PRESENCE OF ACCOUNT NUMBER
int check_ac(int ac)
{
    for (int i = 0; i < cust_avail; i++)
    {
        if (ac == d[i].ac)
        {
            return i + 1;
        }
    }
    return 0;
}

// TO CHECK ACCOUNT NUMBER AND PASSWORD OF CUSTOMER
int check_pass()
{
    int ac_try;
    char pass_try[20];
    printf("                      Enter account no");
    scanf("%d", &ac_try);
    printf("\n                    Enter your password");
    scanf("%s", pass_try);
    int i;
    for (i = 0; i < cust_avail; i++)
    {
        if (ac_try == d[i].ac)
        {
            if (strcmp(pass_try, d[i].pass) == 0)
                return i;
        }
    }
    return -1;
}

// TO SEARCH ACCOUNT NUMBER
int check_ac_search()
{
    int ac_try;
    printf("        Enter account no to search user: ");
    scanf("%d", &ac_try);
    for (int i = 0; i <= cust_avail; i++)
    {
        if (ac_try == d[i].ac)
        {
            return i;
        }
    }
    return -1;
}

// MAIN FUNCTION
int main()
{
    // SAMPLE DATA OF 10 CUSTOMERS
    for (int i = 0; i < 10; i++)
    {
        d[i].srno = i + 1;
        d[i].ac = 5738121 + i * 13;
        // name
        // pan
        d[i].age = rand() % 50;
        d[i].balance = 5000 + rand() % 1000000;
        // phone
        d[i].credit_s = 400 + rand() % 500;
        d[i].loan_amt = 0;
        d[i].emi = 0;
        d[i].bull_pay = 0;
        d[i].fd = 10000 * rand() % 10;
        cust_avail++;
    }
    strcpy(d[0].name, "Aarush");
    strcpy(d[1].name, "Shiva");
    strcpy(d[2].name, "Saksham");
    strcpy(d[3].name, "Shivam");
    strcpy(d[4].name, "Raghav");
    strcpy(d[5].name, "Anant");
    strcpy(d[6].name, "Vivek");
    strcpy(d[7].name, "Saran");
    strcpy(d[8].name, "Yash");
    strcpy(d[9].name, "Kabir");
    strcpy(d[0].pan, "234567");
    strcpy(d[1].pan, "234568");
    strcpy(d[2].pan, "234569");
    strcpy(d[3].pan, "345678");
    strcpy(d[4].pan, "345679");
    strcpy(d[5].pan, "123456");
    strcpy(d[6].pan, "987654");
    strcpy(d[7].pan, "345671");
    strcpy(d[8].pan, "134657");
    strcpy(d[9].pan, "453678");
    strcpy(d[0].phone, "9897775154");
    strcpy(d[1].phone, "9897775458");
    strcpy(d[2].phone, "7544841158");
    strcpy(d[2].phone, "7854447185");
    strcpy(d[3].phone, "9898556247");
    strcpy(d[4].phone, "5652184515");
    strcpy(d[5].phone, "3958845665");
    strcpy(d[6].phone, "5572484826");
    strcpy(d[7].phone, "9898769432");
    strcpy(d[8].phone, "7483195747");
    strcpy(d[9].phone, "8383256569");

    // MENU DRIVEN PROGRAM
    while (infinity == 0)
    {
        int choice1;
        printf(" _______________________________________________________________________________\n");
        printf("|                                                                               |\n");
        printf("|                                                                               |\n");
        printf("|                                   SAS BANK                                    |\n");
        printf("|                                                                               |\n");
        printf("|                                                                               |\n");
        printf("|                               Welcome to SAS BANK                             |\n");
        printf("|                                   ---------->                                 |\n");
        printf("|                                                                               |\n");
        printf("|                                                                               |\n");
        printf("|                               ENTER YOUR CHOICE:                              |\n");
        printf("|                                                                               |\n");
        printf("|                               1. LOGIN                                        |\n");
        printf("|                               2. NEW CUSTOMER?                                |\n");
        printf("|                               3. ADMIN LOGIN PAGE                             |\n");
        printf("|                                                                               |\n");
        printf("|                               4. CLOSE APPLICATION                            |\n");
        printf("|                                                                               |\n");
        printf("|_______________________________________________________________________________|\n");
        scanf("%d", &choice1);

        // LOGIN
        if (choice1 == 1)
        {
            int try_cust = 0;
            int counter = check_pass();
            if (counter == -1)
            {
                int check;
                printf("Wrong username or password, Try again....\nY-->1\nN-->2");
                scanf("%d", &check);
                if (check == 1)
                    check_pass();
                else
                {
                    break;
                }
            }
            while (infinity == 0)
            {
                int choice_log;
                printf(" _______________________________________________________________________________\n");
                printf("|                                                                               |\n");
                printf("|                                   SAS BANK                                    |\n");
                printf("|   Welcome %s                                               8. Logout    \n", d[counter].name);
                printf("|   Account Number: %d                                                          \n", d[counter].ac);
                printf("|                                                                               |\n");
                printf("|                                   ---------->                                 |\n");
                printf("|                                                                               |\n");
                printf("|                                                                               |\n");
                printf("|                               ENTER YOUR CHOICE:                              |\n");
                printf("|                                                                               |\n");
                printf("|                               1. My account details                           |\n");
                printf("|                               2. Deposit                                      |\n");
                printf("|                               3. Withdrawal                                   |\n");
                printf("|                               4. Money Transfer                               |\n");
                printf("|                               5. Loan Application                             |\n");
                printf("|                               6. Loan Repayment                               |\n");
                printf("|                               7. Set Up Fixed deposit                         |\n");
                printf("|                                                                               |\n");
                printf("|_______________________________________________________________________________|\n");
                fflush(stdin);
                scanf("%d", &choice_log);

                // my account details
                if (choice_log == 1)
                {
                    printf(" _______________________________________________________________________________\n");
                    printf("|                                                                               \n");
                    printf("|                                   SAS BANK                                    \n");
                    printf("|   Welcome %s                                                     1. Back    \n", d[counter].name);
                    printf("|   Account Number: %d                                                          \n", d[counter].ac);
                    printf("|                                                        \n");
                    printf("|   Assets                                               \n");
                    printf("|   Balance: %f                                          \n", d[counter].balance);
                    printf("|   F.D: %f                                              \n", d[counter].fd);
                    printf("|                                                        \n");
                    printf("|   Liabilities                                          \n");
                    printf("|   Loan: %f                                             \n", d[counter].loan_amt);
                    printf("|   E.M.I on Loan: %f                                    \n", d[counter].emi);
                    printf("|                                                        \n");
                    printf("|                                                        \n");
                    printf("|                Edit your personal details              \n");
                    printf("|                                                        \n");
                    printf("|_______________________________________________________________________________\n");
                }

                // Deposit
                else if (choice_log == 2)
                {
                    float dep_amt;
                    printf("_____________________________________________________________\n");
                    printf("                            S.A.S BANK                       \n");
                    printf("       Enter the amount you want to deposit:");
                    scanf("%f", &dep_amt);
                    d[counter].balance = d[counter].balance + dep_amt;
                    int dep_reciept;
                    printf("\n\nDo you want to print the deposit reciept\nY-->1\nN-->2:");
                    scanf("%d", &dep_reciept);
                    if (dep_reciept == 1)
                    {
                        deposit_reciept(d[counter].ac, dep_amt);
                    }
                }

                // withdrawal
                else if (choice_log == 3)
                {
                    float with_amt;
                    printf("_____________________________________________________________\n");
                    printf("                            S.A.S BANK                    \n");
                    printf("     ENTER THE AMOUNT YOU WANT TO WITHDRAW :");
                    scanf("%f", &with_amt);
                    d[counter].balance = d[counter].balance - with_amt;
                    withdraw_reciept(d[counter].ac, with_amt);
                }

                // Money Transfer
                else if (choice_log == 4)
                {
                    int choice_transfer;
                    printf(" _______________________________________________________________________________\n");
                    printf("|                                                                               |\n");
                    printf("|                                   SAS BANK                                    |\n");
                    printf("|   Welcome %s                                                   \n", d[counter].name);
                    printf("|   Account Number: %d                                                          \n", d[counter].ac);
                    printf("|                              MONEY TRANSFER WINDOW                               |\n");
                    printf("|                                   ---------->                                 |\n");
                    printf("|                                                                               |\n");
                    printf("|                       1. Transfer to account in S.A.S Bank                    |\n");
                    printf("|                       2. Transfer to account in another bank                  |\n");
                    printf("|                       3. Exit window                                          |\n");
                    printf("|                                                                               |\n");
                    printf("|_______________________________________________________________________________|\n");
                    scanf("%d", &choice_transfer);
                    // transfer to a/c in SAS bank
                    if (choice_transfer == 1)
                    {
                        int yn;
                        int reciever_ac;
                        char bank_name[10] = "S.A.S BANK";
                        printf("__________________________________________________________\n");
                        printf("      Enter Account number of Reciever:");
                        scanf("%d", &reciever_ac);
                        for (int i = 0; i < cust_avail; i++)
                        {
                            // TO FIND RECIEVER ACCOUNT IN S.A.S BANK
                            if (check_ac(reciever_ac) == 0)
                            {
                                // IF ACCOUNT NOT PRESENT IN DATA
                                printf("******** Account not present in Bank *********");
                                printf("     Do you want to enter reciver account number again....");
                                printf("Y->1 N->0\n");
                                scanf("%d", &yn);
                                if (yn != 1)
                                {
                                    break;
                                }
                            }
                            else
                            {
                                float amt_transfer;
                                printf(" Enter amount to be transferred:");
                                scanf("%f", &amt_transfer);
                                if (amt_transfer <= d[counter].balance)
                                {
                                    printf(" Processing....");
                                    printf("\n\n\n");
                                    d[counter].balance = d[counter].balance - amt_transfer;
                                    d[check_ac(reciever_ac) - 1].balance += amt_transfer;
                                    transfer_reciept(d[counter].ac, reciever_ac, amt_transfer, bank_name);
                                }
                                else
                                {
                                    // MONEY TRANSFER FAILED IF AMOUNT ENTERED IS LESS THAN BALANCE
                                    printf("   Money cannot be transferred.\n   Account balance low");
                                    printf("Y->1 N->0\n");
                                    scanf("%d", &yn);
                                    if (yn != 1)
                                    {
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    // transfer to a/c outside SAS bank
                    else if (choice_transfer == 2)
                    {
                        while (infinity == 0)
                        {
                            int yn;
                            int reciever_ac;
                            float amt_transfer;
                            char bank_name[10];
                            printf("__________________________________________________________\n");
                            printf("      Enter Account number of Reciever:");
                            scanf("%d", &reciever_ac);
                            printf("      Enter Bank Name:");
                            scanf("%s", bank_name);
                            printf("      Enter amount to be transferred:");
                            scanf("%f", &amt_transfer);
                            if (amt_transfer <= d[counter].balance)
                            {
                                printf("Processing....");
                                printf("\n\n\n");
                                d[counter].balance = d[counter].balance - amt_transfer;
                                transfer_reciept(d[counter].ac, reciever_ac, amt_transfer, bank_name);
                                break;
                            }
                            else
                            {
                                printf("   Money cannot be transferred.\n   Account balance low");
                                printf("Y->1 N->0\n");
                                scanf("%d", &yn);
                                if (yn != 1)
                                {
                                    break;
                                }
                            }
                        }
                    }
                    // Exit window
                    else if (choice_transfer == 3)
                    {
                        break;
                    }
                }

                // Loan Application
                else if (choice_log == 5)
                {
                    if (d[counter].loan_amt > d[counter].balance * 20)
                    {
                        // IF USER ALREADY HAS A LOAN ON THEMSELVES
                        printf("You cannot get furthur loans as you already have a loan of Rs. %d", d[counter].loan_amt);
                        break;
                    }
                    float loan_app = 1, max_loan = 0;
                    int repayment;
                    printf(" _________________________________________________________________\n");
                    printf("|                             S.A.S BANK                          \n");
                    printf("|                                                                 \n");
                    printf("|                         LOAN APPLICATION                        \n");
                    printf("|                                                                 \n");
                    printf("|                      Your credit score is %d                    \n", d[counter].credit_s);
                    printf("\n");
                    while (loan_app > max_loan)
                    {
                        printf("|               Enter loan amount:");
                        scanf("%f", &loan_app);
                        int T; // T-->time period
                        printf("|\n");
                        printf("|               Enter Time Period in months:");
                        scanf("%d", &T);
                        printf("|                                                             |\n");
                        printf("|_____________________________________________________________|\n");

                        max_loan = (d[counter].credit_s * d[counter].balance) / 100 - d[counter].loan_amt;
                        if (loan_app <= max_loan)
                        {
                            printf("LOAN APPROVED\n");
                            printf("Choose Repayment Option:\n");
                            printf("1.EMI\n");
                            printf("2.Bullet Payment\n");
                            d[counter].loan_amt += loan_app + (loan_app * 1.5 * T) / 100;
                            scanf("%d", &repayment);
                            // EMI
                            if (repayment == 1)
                            {
                                d[counter].emi += (loan_app + (1.5 / 100 * loan_app) * T) / T;
                                printf("Your EMI: %f\n", d[counter].emi);
                            }
                            // BULLET PAYMENT
                            else if (repayment == 2)
                            {
                                float bullet_pay = (d[counter].loan_amt * 1.5 * T) / 100;
                                d[counter].bull_pay += bullet_pay;
                                printf("Your Bullet repayment amount:%f you have to pay it in %d months\n", bullet_pay, T);
                            }
                        }
                        else
                        {
                            // LOAN FAILED DUE TO UNSATISFIED REQUIREMENTS
                            printf("LOAN CANNOT BE APPROVED DUE TO LOW CREDIT SCORE AND BALANCE \n");
                        }
                    }
                }

                // Loan Repayment
                if (choice_log == 6)
                {
                    printf("_______________________________________________________________________________\n");
                    printf("                                   S.A.S BANK\n");
                    printf("\n");
                    printf("                            LOAN REPAYMENT PLANS\n");
                    printf("\n");
                    printf("                   Total Loan Amount Left: %f\n", d[counter].loan_amt);
                    if (d[counter].emi != 0)
                        printf("                   EMI for each month to be paid is: %f\n", d[counter].emi);
                    if (d[counter].bull_pay != 0)
                    {
                        printf("                   Bullet payment to be made is: %f\n", d[counter].emi);
                    }
                    if (d[counter].emi != 0 && d[counter].bull_pay != 0)
                    {
                        printf("                   What mode do you want to pay\n");
                        printf("                        1. EMI\n");
                        printf("                        2. Bullet Payment\n");
                        int rep_choice;
                        scanf("%d", &rep_choice);
                        if (rep_choice == 1)
                        {
                            if (d[counter].balance < d[counter].emi)
                            {
                                printf("    Insufficient Funds\n");
                            }
                            else
                            {
                                printf("    Paying %f towards EMI from A/c %d", d[counter].emi, d[counter].ac);
                                d[counter].balance -= d[counter].emi;
                            }
                        }
                        else if (rep_choice == 2)
                        {
                            if (d[counter].balance < d[counter].bull_pay)
                            {
                                printf("    Insufficient Funds\n");
                            }
                            else
                            {
                                printf("    Paying %d towards bullet payment from A/c %d", d[counter].bull_pay, d[counter].ac);
                                d[counter].balance -= d[counter].bull_pay;
                            }
                        }
                    }
                    if (d[counter].emi != 0 && d[counter].bull_pay == 0)
                    {
                        if (d[counter].balance < d[counter].emi)
                        {
                            printf("    Insufficient Funds\n");
                        }
                        else
                        {
                            printf("    Paying %d towards EMI from A/c %d", d[counter].emi, d[counter].ac);
                            d[counter].balance -= d[counter].emi;
                        }
                    }
                    if (d[counter].emi == 0 && d[counter].bull_pay != 0)
                    {
                        if (d[counter].balance < d[counter].bull_pay)
                        {
                            printf("    Insufficient Funds\n");
                        }
                        else
                        {
                            printf("    Paying %d towards bullet payment from A/c %d", d[counter].bull_pay, d[counter].ac);
                            d[counter].balance -= d[counter].bull_pay;
                        }
                    }
                    printf("_______________________________________________________________________________\n");
                }

                // Set Up Fixed deposit
                if (choice_log == 7)
                {
                    int month = 0;
                    float final_amt, fd_amt;
                    printf(" _______________________________________________________________________________\n");
                    printf("|                                                                               |\n");
                    printf("|                           THANKS FOR SHOWING INTEREST IN F.D                  |\n");
                    printf("|                                                                               |\n");
                    printf("|             ****WE PROVIDE GREAT INTEREST RATES ON YOUR DEPOSITS****          |\n");
                    printf("|                                                                               |\n");
                    printf("|                           OUR INTEREST RATES ARE GIVEN BELOW :                |\n");
                    printf("|                                                                               |\n");
                    printf("|                                                                               |\n");
                    printf("|                          FOR 6-12 MONTH         ---->       5%%                |\n");
                    printf("|                                                                               |\n");
                    printf("|                          FOR 12-18 MONTH        ---->       6%%                |\n");
                    printf("|                                                                               |\n");
                    printf("|                          FOR MORE THAN 18 MONTH ---->       7%%                |\n");
                    printf("|                                                                               |\n");
                    printf("|                                                                               |\n");
                    printf("|     *T&C- Minimum term of 6 months required to set up an F.D.                 |\n");
                    printf("|                                                                               |\n");
                    printf("|_______________________________________________________________________________|\n\n\n");
                    printf("ENTER HOW MUCH MONEY YOU WANT TO DEPOSIT :");
                    fflush(stdin);
                    scanf("%f", &fd_amt);
                    while (month < 6)
                    {
                        printf("FOR HOW MUCH PERIOD YOU WANT TO MAKE F.D :");
                        scanf("%d", &month);
                        // FOR LESS THAN 12 MONTHS
                        if (month < 12 && month >= 6)
                        {
                            final_amt = fd_amt + (fd_amt * 5 * (month / 12) / 100);
                            printf("YOUR DEPOSITED MONEY WILL BECOME %f IN %d MONTHS", final_amt, month);
                            d[counter].fd += final_amt;
                        }
                        // FOR LESS THAN 18 MONTHS
                        else if (month >= 12 && month < 18)
                        {
                            final_amt = fd_amt + (fd_amt * 6 * (month / 12) / 100);
                            printf("YOUR DEPOSITED MONEY WILL BECOME %f IN %d MONTHS", final_amt, month);
                            d[counter].fd += final_amt;
                        }
                        // FOR GREATER THAN 18 MONTHS
                        else if (month >= 18)
                        {
                            final_amt = fd_amt + (fd_amt * 7 * (month / 12) / 100);
                            printf("YOUR DEPOSITED MONEY WILL BECOME %f IN %d MONTHS", final_amt, month);
                            d[counter].fd += final_amt;
                        }
                        // IF TIME ENTERED IS LESS THAN 6 MONTHS
                        else
                        {
                            printf("YOUR F.D TENURE IS TOO SMALL. ONLY MORE THAN 6 MONTHS F.D ARE ALLOWED");
                        }
                        printf("\n");
                    }
                }
                // LOGOUT
                else if (choice_log == 8)
                {
                    printf("                   S.A.S BANK                       \n");
                    printf("         Thanks for operating your account\n");
                    printf("               We will see you soon\n");
                    break;
                }
            }
        }

        // New customer?
        else if (choice1 == 2)
        {
            float entered_bal = 0;
            d[cust_avail].balance = 0;
            printf("\n\n\n\n");
            printf(" ________________________________________________________________________\n");
            printf("|                     ***** WELCOME  TO  S.A.S  BANK *****               |\n");
            printf("|                                                                        |\n");
            printf("|                              Let's get you started                     |\n");
            printf("|                                                                        |\n");
            printf("|             Enter your mobile number:");
            scanf("%s", d[cust_avail].phone);
            printf("|                                                                        |\n");
            printf("|             Enter a new password:");
            scanf("%s", d[cust_avail].pass);
            printf("|                                                                        |\n");
            printf("|             Enter your full name:");
            scanf("%s", d[cust_avail].name);
            printf("|                                                                        |\n");
            printf("|             Enter  your Age:");
            scanf("%d", &d[cust_avail].age);
            printf("|                                                                        |\n");
            printf("|             Enter your Pancard number:");
            scanf("%s", d[cust_avail].pan);
            printf("|                                                                        |\n");
            printf("|             Enter your CIBIL score:");
            scanf("%d", &d[cust_avail].credit_s);
            printf("|                                                                        |\n");
            printf("|________________________________________________________________________|\n\n\n");
            d[cust_avail].srno = cust_avail + 1;
            if (cust_avail == 0)
            {
                d[cust_avail].ac = 5738321;
            }
            else
            {
                d[cust_avail].ac = d[cust_avail - 1].ac + 13;
            }
            // ACCOUNT CREATED A/C NUMBER ALLOTED
            printf(" ___________________________________________________________________________ \n");
            printf("|                     ***** WELCOME  TO  S.A.S  BANK *****                   |\n");
            printf("|                                                                            |\n");
            printf("|    Your account has been created. Your account number is %d                |\n", d[cust_avail].ac);
            printf("|       Welcome to S.A.S Bank, where we treat our customers as family        |\n");
            printf("|       Let us go through some guidelines. Every bank user needs to know     |\n");
            printf("|       maintain a minimum account balance of Rs.5000                        |\n");
            printf("|                                                                            |\n");
            printf("|____________________________________________________________________________|\n\n\n");

            // TO CHECK BALANCE IS MORE THAN RS. 5000
            while (entered_bal < 5000)
            {
                printf("\n\n      Enter amount of money you want to deposit to your bank account:");
                float bal;
                scanf("%f", &bal);
                entered_bal += bal;
                fflush(stdin);
                d[cust_avail].balance += entered_bal;
                printf("\n\nDo you want to print the deposit reciept\nY-->1\nN-->2:");
                int reciept;
                scanf("%d", &reciept);
                // RECIEPT PRINT
                if (reciept == 1)
                {
                    deposit_reciept(d[cust_avail].ac, entered_bal);
                }
                if (entered_bal < 5000)
                {
                    printf("Please deposit atleast %f more amount to reach minimum requirement", (5000 - entered_bal));
                }
            }
            printf("\n\n");
            printf("\n\n");
            cust_avail++;
        }

        // Admin login
        else if (choice1 == 3)
        {
            int try_admin = 0;
            char user_try[10];
            char pass_try[20];
            printf("                      Enter admin username:");
            scanf("%s", user_try);
            printf("\n                       Enter admin password:");
            scanf("%s", pass_try);
            // LOGIN CONDITION FOR ADMIN
            if (strcmp(user_try, admin_user) == 0 && strcmp(pass_try, admin_pass) == 0)
            {
                while (infinity == 0)
                {
                    int choice_admn;
                    printf(" \n_______________________________________________________________________________\n");
                    printf("|                                                                               |\n");
                    printf("|                                                                               |\n");
                    printf("|                                    SAS BANK                                   |\n");
                    printf("|                                                                               |\n");
                    printf("|                                     ADMIN                                     |\n");
                    printf("|                              Welcome to SAS BANK                              |\n");
                    printf("|                                   ---------->                                 |\n");
                    printf("|                                                                               |\n");
                    printf("|                                                                               |\n");
                    printf("|                               ENTER YOUR CHOICE:                              |\n");
                    printf("|                                                                               |\n");
                    printf("|                               1. SHOW USER DATA BASE                          |\n");
                    printf("|                               2. SEARCH USER                                  |\n");
                    printf("|                               3. MONITOR BANK'S WEALTH                        |\n");
                    printf("|                                                                               |\n");
                    printf("|                               4. LOG OUT                                      |\n");
                    printf("|                                                                               |\n");
                    printf("|_______________________________________________________________________________|\n");
                    scanf("%d", &choice_admn);

                    // SHOW USER DATA BASE
                    if (choice_admn == 1)
                    {
                        printf("SRNO\tACC.NO.\tNAME\tPHONE\t\tAGE\tPAN NO\tBALANCE\t\tCREDIT SCORE\tLOAN AMOUNT\tEMI\t\tBULLET PAYMENT\tFIXED DEPOSIT\n");
                        for (int j = 0; j < cust_avail; j++)
                        {
                            printf("%d\t%d\t%s\t%s\t%d\t%s\t%f\t%d\t\t%f\t%f\t%f\t%f\n", d[j].srno, d[j].ac, d[j].name, d[j].phone, d[j].age, d[j].pan, d[j].balance, d[j].credit_s, d[j].loan_amt, d[j].emi, d[j].bull_pay, d[j].fd);
                        }
                    }

                    // SEARCH USER
                    else if (choice_admn == 2)
                    {
                        int choice_search;
                        printf(" _______________________________________________________________________________\n");
                        printf("|                                                                               |\n");
                        printf("|                                                                               |\n");
                        printf("|                                    SAS BANK                                   |\n");
                        printf("|                                                                               |\n");
                        printf("|                                     ADMIN                                     |\n");
                        printf("|                              Welcome to SAS BANK                              |\n");
                        printf("|                                   ---------->                                 |\n");
                        printf("|                                                                               |\n");
                        printf("|                                                                               |\n");
                        printf("|                       ENTER HOW YOU WANT TO SEARCH THE USER:                  |\n");
                        printf("|                                                                               |\n");
                        printf("|                          1. SEARCH BY ACCOUNT NUMBER                          |\n");
                        printf("|                                                                               |\n");
                        printf("|                                                                               |\n");
                        printf("|                                                                               |\n");
                        printf("|_______________________________________________________________________________|\n");
                        scanf("%d", &choice_search);
                        // Search By Account Number
                        if (choice_search == 1)
                        {
                            int j = check_ac_search();
                            printf("SRNO\tACC.NO.\tNAME\tPHONE\t\tAGE\tPAN NO\tBALANCE\t\tCREDIT SCORE\tLOAN AMOUNT\tEMI\t\tBULLET PAYMENT\tFIXED DEPOSIT\n");
                            printf("%d\t%d\t%s\t%s\t%d\t%s\t%f\t%d\t\t%f\t%f\t%f\t%f\n", d[j].srno, d[j].ac, d[j].name, d[j].phone, d[j].age, d[j].pan, d[j].balance, d[j].credit_s, d[j].loan_amt, d[j].emi, d[j].bull_pay, d[j].fd);
                        }
                    }

                    // MONITOR BANK'S WEALTH
                    else if (choice_admn == 3)
                    {
                        float bank_wealth = 0;
                        float bank_deposits = 0;
                        float bank_fixed_deposits = 0;
                        float bank_loans = 0;

                        // TO CALCULATE TOTAL BANK WEALTH
                        for (int i = 0; i < cust_avail; i++)
                        {
                            bank_wealth = bank_wealth + d[i].balance + d[i].fd - d[i].loan_amt;
                            bank_deposits = bank_deposits + d[i].balance;
                            bank_fixed_deposits = bank_fixed_deposits + d[i].fd;
                            bank_loans = bank_loans + d[i].loan_amt;
                        }
                        printf(" _______________________________________________________________________________\n");
                        printf("|                                                                               |\n");
                        printf("|                                                                               |\n");
                        printf("|                           SAS BANK                                            |\n");
                        printf("|                                                                               |\n");
                        printf("|                                                                               |\n");
                        printf("|                   Bank total wealth          : %f                             \n", bank_wealth);
                        printf("|                                                                               |\n");
                        printf("|                   Bank total deposits        : %f                             \n", bank_deposits);
                        printf("|                                                                               |\n");
                        printf("|                   Bank total fixed_deposits  : %f                             \n", bank_fixed_deposits);
                        printf("|                                                                               |\n");
                        printf("|                   Bank  total loan Amount    : %f                             \n", bank_loans);
                        printf("|                                                                               |\n");
                        printf("|                                                                               |\n");
                        printf("|_______________________________________________________________________________|\n");
                    }

                    // LOG OUT
                    else if (choice_admn == 4)
                    {
                        printf("Logging Out.....\n");
                        break;
                    }
                }
            }
        }

        // CLOSE APPLICATION
        else if (choice1 == 4)
        {
            printf("                See you soon");
            break;
        }
        else
            printf("                Wrong choice choose again\n");
    }
}