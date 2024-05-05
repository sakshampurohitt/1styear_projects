#include <iostream>
using namespace std;
#include <cmath>
#include <cstring>
#include <string>

// sample number of users
const int MAX_USERS = 10;

int choice = 0;
int numUsers = 0;
int infinity = 0;

// class income
class income
{
public:
    float activeinc;
    float passiveinc;
    float totalinc;
    // added variable for total income

    // to-go constructor for income class
    void getincome()
    {
        totalinc = 0;
        cout << " _________________________________________________" << endl;
        cout << "|                 YOUR TOTAL INCOME               |" << endl;
        cout << "|_________________________________________________|" << endl;
        getactive();
        cout << " _________________________________________________" << endl;
        getpassive();
        cout << " _________________________________________________" << endl;
    }

    // add active income
    void getactive()
    {
        cout << "Enter your active income: ";
        cin >> activeinc;
        totalinc += activeinc;
        // add active income to total
    }

    // add passive income
    void getpassive()
    {
        cout << "Enter your passive income: ";
        cin >> passiveinc;
        // add passive income to total
        totalinc += passiveinc;
    }

    // function to return total income
    float gettotalinc()
    {
        cout << totalinc;
        return totalinc;
    }
};

// class expense
class expense
{
public:
    // data members set to public
    float accomodation;
    float food;
    float transport;
    float misc;
    // added variable for total expense
    float totalexp;

public:
    // to-go constructor or expense class
    void getexpense()
    {
        totalexp = 0;
        cout << " _________________________________________________" << endl;
        cout << "|            YOUR TOTAL EXPENSE                   |" << endl;
        cout << "|_________________________________________________|" << endl;
        getaccom();
        cout << " _________________________________________________" << endl;
        getfood();
        cout << " _________________________________________________" << endl;
        gettrans();
        cout << " _________________________________________________" << endl;
        getmisc();
        cout << " _________________________________________________" << endl;
        gettotalexp();
        cout << " _________________________________________________" << endl;
    }

    // added accomodation expense
    void getaccom()
    {
        cout << "Enter your accommodation expense: ";
        cin >> accomodation;
        // add accommodation expense to total
        totalexp += accomodation;
    }

    // added food expense
    void getfood()
    {
        cout << "Enter your food expense: ";
        cin >> food;
        // add food expense to total
        totalexp += food;
    }

    // added transport expense
    void gettrans()
    {
        cout << "Enter your transport expense: ";
        cin >> transport;
        // add transport expense to total
        totalexp += transport;
    }

    // added miscelleneous expense
    void getmisc()
    {
        cout << "Enter your miscellaneous expense: ";
        cin >> misc;
        // add miscellaneous expense to total
        totalexp += misc;
    }

    // function to return total expense
    float gettotalexp()
    {
        return totalexp;
    }
};

// personal details class
class personalDeets
{

public:
    char name[10];
    char mobileNo[10];
    char address[10];
    char mailId[10];
    char user[10];
    char pass[20];
    income inc;
    expense exp;

    // constructor for personalDeets class
    personalDeets()
    {
        cout << " _________________________________________________" << endl;
        cout << "|         ENTER PERSONAL DETAILS OF USER          |" << endl;
        cout << "|_________________________________________________|" << endl;
        getName();
        cout << " _________________________________________________" << endl;
        getMobileNo();
        cout << " _________________________________________________" << endl;
        getAddress();
        cout << " _________________________________________________" << endl;
        getmail_Address();
        cout << " _________________________________________________" << endl;
        getUser();
        cout << " _________________________________________________" << endl;
        getPass();
        cout << " _________________________________________________" << endl;
        cout << "           User successfully created:" << endl;
    }

    // function to check if password is strong
    bool isStrongPassword(const char *password)
    {
        // Password must have at least 8 characters
        if (strlen(password) < 8)
        {
            return false;
        }

        // Password must have at least one uppercase letter
        bool hasUppercase = false;
        for (int i = 0; password[i]; i++)
        {
            if (isupper(password[i]))
            {
                hasUppercase = true;
                break;
            }
        }
        // to check uppercase letters
        if (!hasUppercase)
        {
            return false;
        }

        // Password must have at least one lowercase letter
        bool hasLowercase = false;
        for (int i = 0; password[i]; i++)
        {
            if (islower(password[i]))
            {
                hasLowercase = true;
                break;
            }
        }

        // if there is no lowecase
        if (!hasLowercase)
        {
            return false;
        }

        // Password must have at least one digit
        bool hasDigit = false;
        for (int i = 0; password[i]; i++)
        {
            if (isdigit(password[i]))
            {
                hasDigit = true;
                break;
            }
        }

        // if there is no digit
        if (!hasDigit)
        {
            return false;
        }

        // Password must have at least one special character
        bool hasSpecialChar = false;
        for (int i = 0; password[i]; i++)
        {
            if (!isalnum(password[i]))
            {
                hasSpecialChar = true;
                break;
            }
        }

        // if there is no specialcharacter
        if (!hasSpecialChar)
        {
            return false;
        }

        // All criteria met, password is strong
        return true;
    }

    // added name of user
    void getName()
    {
        cout << "Enter your name:";
        cin >> name;
    }

    // added mobile number of user
    void getMobileNo()
    {
        cout << "Enter your mobile number:";
        cin >> mobileNo;
    }

    // added address of user
    void getAddress()
    {
        cout << "Enter your address:";
        cin >> address;
    }

    // added email address of user
    void getmail_Address()
    {
        cout << "Enter your e-mail id:";
        cin >> mailId;
    }

    // added username
    void getUser()
    {
        cout << "Enter username:";
        cin >> user;
    }

    // added password of user to login
    void getPass()
    {
        while (true)
        {
            cout << "Enter password (must be at least 8 characters, with at least one uppercase letter, one lowercase letter, one digit, and one special character): ";
            cin >> pass;
            if (isStrongPassword(pass))
            {
                break;
            }
            else
            {
                cout << "Password is not strong enough, please try again." << endl;
            }
        }
    }

    // to calculate difference between income and expense
    float calcdiff()
    {

        float difference = inc.totalinc - exp.totalexp;
        if (difference > 0)
        {
            cout << "You have surplus of " << difference << " funds to spare" << endl;
            recommendExpenseCuts();
        }
        else if (difference < 0)
        {
            cout << "Your expenses are more than your income by " << difference << endl;
            recommendExpenseCuts();
        }
        else if (difference == 0)
        {
            cout << "Your income and expense are balanced" << endl;
            recommendExpenseCuts();
        }
        return difference;
    }

    // recommend person to cut expenses if needed
    void recommendExpenseCuts()
    {

        // Calculate the percentage of each expense category relative to the total expenses
        float totalExp = exp.gettotalexp();
        float accomPercent = (exp.accomodation / totalExp) * 100;
        float foodPercent = (exp.food / totalExp) * 100;
        float transPercent = (exp.transport / totalExp) * 100;
        float miscPercent = (exp.misc / totalExp) * 100;

        // Determine the category with the highest percentage and recommend cutting expenses in that category
        if (accomPercent >= foodPercent && accomPercent >= transPercent && accomPercent >= miscPercent)
        {
            cout << "Your accommodation expenses are " << accomPercent << "% of your total expenses. You may want to consider finding a cheaper place to live." << endl;
        }
        if (foodPercent >= accomPercent && foodPercent >= transPercent && foodPercent >= miscPercent)
        {
            cout << "Your food expenses are " << foodPercent << "% of your total expenses." << endl;
            cout << "your food expense is too much,you should consider to control your food expenses" << endl;
        }
        if (transPercent >= accomPercent && transPercent >= foodPercent && transPercent >= miscPercent)
        {
            cout << "Your transport expenses are " << transPercent << "% of your total expenses." << endl;
            cout << "you may want to consider using public transport instead of uber or ola" << endl;
        }
        if (miscPercent >= accomPercent && miscPercent >= transPercent && miscPercent >= foodPercent)
        {
            cout << "Your misc expenses are " << miscPercent << "% of your total expenses." << endl;
            cout << " You may want to consider decreasing your misc expenses " << endl;
        }
    }

    // Function to explain expense management

    void manage_expense()
    {
        cout << " ___________________________________________________________________" << endl;
        cout << "|                        EXPENSE MANAGEMENT                         |" << endl;
        cout << "|___________________________________________________________________|" << endl;
        cout << "|                                                                   |" << endl;
        cout << "| 1. Keep track of all expenses: Record all your expenses and       |" << endl;
        cout << "|    categorize them to identify where you are spending the most.   |" << endl;
        cout << "|                                                                   |" << endl;
        cout << "| 2. Create a budget: Make a monthly or weekly budget to plan and   |" << endl;
        cout << "|    manage your expenses. Make sure to include all expenses        |" << endl;
        cout << "|    such as bills, food, transportation, etc.                      |" << endl;
        cout << "|                                                                   |" << endl;
        cout << "| 3. Cut back on unnecessary expenses: Identify areas where you     |" << endl;
        cout << "|    can cut back on expenses such as eating out, buying expensive  |" << endl;
        cout << "|    coffee, etc.                                                   |" << endl;
        cout << "|                                                                   |" << endl;
        cout << "| 4. Use cash instead of credit cards: This can help you avoid      |" << endl;
        cout << "|    overspending and accumulating debt.                            |" << endl;
        cout << "|                                                                   |" << endl;
        cout << "| 5. Seek professional advice: Consider seeking advice from a       |" << endl;
        cout << "|    financial planner or accountant to help you manage your        |" << endl;
        cout << "|    expenses and plan for the future.                              |" << endl;
        cout << "|___________________________________________________________________|" << endl;
    }

    // function to explain drawbacks of having expense more than income

    void higher_expense()
    {
        cout << "|------------------------------------------------------------------|" << endl;
        cout << "|                    DOWNSIDE OF HIGHER EXPENSES                   |" << endl;
        cout << "|------------------------------------------------------------------|" << endl;
        cout << "|  Drawbacks of higher expenses:                                   |" << endl;
        cout << "|------------------------------------------------------------------|" << endl;
        cout << "| 1. Financial instability: Higher expenses can lead to financial  |" << endl;
        cout << "|    instability as it becomes difficult to manage expenses and    |" << endl;
        cout << "|    meet financial goals.                                         |" << endl;
        cout << "|                                                                  |" << endl;
        cout << "| 2. Limited savings: When expenses are high, there is limited     |" << endl;
        cout << "|    room for savings which can result in limited financial        |" << endl;
        cout << "|    security for the future.                                      |" << endl;
        cout << "|                                                                  |" << endl;
        cout << "| 3. Debt accumulation: Higher expenses can lead to debt           |" << endl;
        cout << "|    accumulation if expenses are not managed properly.            |" << endl;
        cout << "|                                                                  |" << endl;
        cout << "| 4. Stress: High expenses can lead to financial stress and        |" << endl;
        cout << "|    negatively affect mental and physical health.                 |" << endl;
        cout << "|                                                                  |" << endl;
        cout << "| 5. Lack of flexibility: When expenses are high, there is limited |" << endl;
        cout << "|    flexibility in the budget to accommodate unexpected expenses. |" << endl;
        cout << "|                                                                  |" << endl;
        cout << "|------------------------------------------------------------------|" << endl;
    }

    // function to give investment advice

    void invest_advice()
    {
        cout << "|--------------------------------------------------------------------------------|" << endl;
        cout << "|                          Tips on How to Invest Funds                           |" << endl;
        cout << "|--------------------------------------------------------------------------------|" << endl;
        cout << "|                                                                                |" << endl;
        cout << "| 1. Understand your goals and risk tolerance before making any investments.     |" << endl;
        cout << "|                                                                                |" << endl;
        cout << "| 2. Diversify your investments to reduce the risk of loss.                      |" << endl;
        cout << "|                                                                                |" << endl;
        cout << "| 3. Start investing as early as possible to take advantage of compound interest.|" << endl;
        cout << "|                                                                                |" << endl;
        cout << "| 4. Research and evaluate investment options before investing.                  |" << endl;
        cout << "|                                                                                |" << endl;
        cout << "| 5. Rebalance your investment portfolio periodically to maintain the desired    |" << endl;
        cout << "|    level of risk and return.                                                   |" << endl;
        cout << "|                                                                                |" << endl;
        cout << "|--------------------------------------------------------------------------------|" << endl;
    }

    // tips to increase income of user

    void inc_income_advice()
    {
        cout << " _______________________________________________________________________________" << endl;
        cout << "|                                                                               |" << endl;
        cout << "|                      Tips on How to Increase Your Income                      |" << endl;
        cout << "|-------------------------------------------------------------------------------|" << endl;
        cout << "|                                                                               |" << endl;
        cout << "| 1. Learn new skills and take up courses to improve your knowledge and         |" << endl;
        cout << "|    expertise.                                                                 |" << endl;
        cout << "|                                                                               |" << endl;
        cout << "| 2. Look for better-paying job opportunities in your field.                    |" << endl;
        cout << "|                                                                               |" << endl;
        cout << "| 3. Consider starting a side business or freelancing to supplement your income.|" << endl;
        cout << "|                                                                               |" << endl;
        cout << "| 4. Negotiate for a salary increase or a performance-based bonus at work.      |" << endl;
        cout << "|                                                                               |" << endl;
        cout << "| 5. Invest in yourself by networking, building your personal brand, and        |" << endl;
        cout << "|    showcasing your work to potential clients or employers.                    |" << endl;
        cout << "|_______________________________________________________________________________|" << endl;
    }

    // detailed financial report of user including income, expense, profit/loss and expense advice

    void finance_report(int accesslogin)
    {
        cout << " ______________________________________________________________________________________" << endl;
        cout << "|                                                                                      |" << endl;
        cout << "|                                      FINANCE REPORT                                  |" << endl;
        cout << "|                                                                                      |" << endl;
        cout << "|   INCOME:                                                                             " << endl;
        cout << "|          PASSIVE INCOME = " << inc.passiveinc << endl;
        cout << "|          ACTIVE  INCOME = " << inc.activeinc << endl;
        cout << "|          TOTAL   INCOME = " << inc.totalinc << endl;
        cout << "|                                                                               " << endl;
        cout << "|   EXPENSE:" << endl;
        cout << "|          ACCOMODATION = " << exp.accomodation << endl;
        cout << "|          FOOD = " << exp.food << endl;
        cout << "|          TRANSPORT = " << exp.transport << endl;
        cout << "|          MISCELLANEOUS = " << exp.misc << endl;
        cout << "|          TOTAL = " << exp.totalexp << endl;
        cout << "|                                                                                       |" << endl;
        cout << "|_______________________________________________________________________________________| " << endl;
        cout << " _______________________________________________________________________________________" << endl;
        cout << "|   STATEMENT:                                                                          " << endl;
        cout << "|                                                                                       " << endl;
        cout << "|          " << calcdiff() << endl;
        cout << "|_______________________________________________________________________________________" << endl;
    }

    // to display data of user

    void display_data()
    {
        cout << "|---------------------------------------------------|" << endl;
        cout << "|                                                   |" << endl;
        cout << "|             PESRONAL DETAILS                      |" << endl;
        cout << "|                                                   |" << endl;
        cout << "|     name :" << name << "                          |" << endl;
        cout << "|     mobileNo:" << mobileNo << "                   |" << endl;
        cout << "|     address: " << address << "                    |" << endl;
        cout << "|     email id: " << mailId << "                    |" << endl;
        cout << "|                                                   |" << endl;
        cout << "|---------------------------------------------------|" << endl;
    }
};

// declaring 10 User pointer as sample
personalDeets *personal[MAX_USERS];

// to check login credentials

int logincheck()
{
    char usercheck[10];
    char passcheck[20];
    cout << " ___________________________________________________" << endl;
    cout << "|  Enter username: ";
    cin >> usercheck;
    cout << "|  Enter password: ";
    cin >> passcheck;
    cout << "|____________________________________________________" << endl;
    for (int i = 0; i < MAX_USERS; i++)
    {
        if (personal[i] != nullptr && !strcmp(personal[i]->user, usercheck) && !strcmp(personal[i]->pass, passcheck))
        {
            return i;
        }
    }
    cout << "Details not matched" << endl;
    return -1;
}

// main function

int main()
{ // Declare variables

    // Menu loop
    while (infinity == 0)
    {
        // Display menu
        printf(" _____________________________________________________________\n");
        printf("|                                                             |\n");
        printf("|                     BUDGET TRACKER                          |\n");
        printf("|                                                             |\n");
        printf("|                 1. New user? Singup                         |\n");
        printf("|                                                             |\n");
        printf("|                 2. Login to existing user                   |\n");
        printf("|                                                             |\n");
        printf("|                 3. User exit                                |\n");
        printf("|_____________________________________________________________|\n");
        cout << "Enter choice: ";
        cin >> choice;

        // Handle menu choice
        switch (choice)
        {
        case 1:
            // Sign up
            if (numUsers < MAX_USERS)
            {

                // Create user object and add to array
                personal[numUsers] = new personalDeets();
                numUsers++;
                cout << "User created successfully!" << endl;
            }
            else
            {
                cout << "Maximum number of users reached!" << endl;
            }
            break;
        case 2:
            // login page
            int accesslogin;
            accesslogin = logincheck();
            if (accesslogin == -1)
            {
                cout << "INVALID CREDENTIALS USED, PLEASE TRY AGAIN" << endl;
            }
            else
            {
                // Display users
                int infinity1 = 0;
                while (infinity1 == 0)
                {
                    printf(" ____________________________________________________________________\n");
                    printf("|                                                                    |\n");
                    printf("|                 Welcome to our Budget Tracking App                 |\n");
                    printf("|       Log in to track your expenses and manage your finances       |\n");
                    printf("|                                                                    |\n");
                    printf("|                 1. Enter Income sources                            |\n");
                    printf("|                 2. Enter user expenses                             |\n");
                    printf("|                 3. View user details                               |\n");
                    printf("|                 4. Edit user details                               |\n");
                    printf("|                 5. Check financial status                          |\n");
                    printf("|                 6. Get financial advice                            |\n");
                    printf("|                 7. User exit                                       |\n");
                    printf("|____________________________________________________________________|\n");
                    int choice1;
                    cout << "Enter your choice:";
                    cin >> choice1;
                    switch (choice1)
                    {
                    // to show income sources
                    case 1:
                        personal[accesslogin]->inc.getincome();
                        break;

                    // to show expense sources
                    case 2:
                        personal[accesslogin]->exp.getexpense();
                        break;

                    // to View personal details
                    case 3:
                        printf(" ________________________________________________________________\n");
                        printf("|                                                                |\n");
                        printf("|                                                                |\n");
                        printf("|                   VIEW YOUR DETAILS                            |\n");
                        printf("|                                                                |\n");
                        printf("|                                                                |\n");
                        cout << "|                 1. NAME:" << personal[accesslogin]->name << endl;
                        cout << "|                 2. Mobile No:" << personal[accesslogin]->mobileNo << endl;
                        cout << "|                 3. Address:" << personal[accesslogin]->address << endl;
                        cout << "|                 4. Mail Id:" << personal[accesslogin]->mailId << endl;
                        cout << "|                 5. Username:" << personal[accesslogin]->user << endl;
                        cout << "|                 6. Password:" << personal[accesslogin]->pass << endl;
                        printf("|                                                                |\n");
                        printf("|________________________________________________________________|\n");
                        break;

                    // to edit users details
                    case 4:
                        printf(" ________________________________________________________________\n");
                        printf("|                                                                |\n");
                        printf("|                                                                |\n");
                        printf("|                   EDIT YOUR DETAILS                            |\n");
                        printf("|                                                                |\n");
                        printf("|                                                                |\n");
                        printf("|                 1. NAME                                        |\n");
                        printf("|                 2. Mobile No                                   |\n");
                        printf("|                 3. Address                                     |\n");
                        printf("|                 4. Mail Id                                     |\n");
                        printf("|                 5. Username                                    |\n");
                        printf("|                 6. Password                                    |\n");
                        printf("|                 7. Exit to login page                          |\n");
                        printf("|                                                                |\n");
                        printf("|________________________________________________________________|\n");
                        int choice23;
                        cout << "Enter your choice:";
                        cin >> choice23;
                        // to access choices of edit details
                        switch (choice23)
                        {
                        case 1:
                            personal[accesslogin]->getName();
                            break;
                        case 2:
                            personal[accesslogin]->getMobileNo();
                            break;
                        case 3:
                            personal[accesslogin]->getAddress();
                            break;
                        case 4:
                            personal[accesslogin]->getmail_Address();
                            break;
                        case 5:
                            personal[accesslogin]->getUser();
                            break;
                        case 6:
                            personal[accesslogin]->getPass();
                            break;
                        default:
                            break;
                        }
                        break;

                    // Printing financial report
                    case 5:
                        personal[accesslogin]->finance_report(accesslogin);
                        break;

                    // to show financial advice portal
                    case 6:
                        while (infinity == 0)
                        {
                            cout << " _________________________________________________________________ " << endl;
                            cout << "|                    FINANCIAL ADVICE PORTAL                      |" << endl;
                            cout << "|                                                                 |" << endl;
                            cout << "|              1. Expense management                              |" << endl;
                            cout << "|              2. Drawbacks of higher expense                     |" << endl;
                            cout << "|              3. How to invest funds                             |" << endl;
                            cout << "|              4. How to increase income                          |" << endl;
                            cout << "|              5. Exit to Login page                              |" << endl;
                            cout << "|_________________________________________________________________|" << endl;
                            int choice6;
                            cout << "Enter your choice:";
                            cin >> choice6;

                            switch (choice6)
                            {
                            case 1:
                                personal[accesslogin]->manage_expense();
                                break;

                            case 2:
                                personal[accesslogin]->higher_expense();
                                break;

                            case 3:
                                personal[accesslogin]->invest_advice();
                                break;

                            case 4:
                                personal[accesslogin]->inc_income_advice();
                                break;

                            case 5:
                                break;

                            default:
                                break;
                            }
                            break;
                        }
                        break;

                    case 7:
                        infinity1 = 1;
                        break;
                    
                    default:
                        infinity1 = 1;
                        break;
            
                    }
                }

            }
            // to end process
        case 3:
            cout << "Thank you for using our application" << endl;
            infinity = 1;
            break; // Exit application
        default:
            break;
        }
    }
    return 0;
}
