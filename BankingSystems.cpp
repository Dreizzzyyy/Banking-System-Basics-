//Start of Program
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

//Program Structure
class BankAccount {
    public:
        string name;
        int accountNumber;
        float balance;
    
        void displayAccountInfo();
        void deposit(float amount);
        void withdraw(float amount);
        void computeinterest ();
        vector<string> transactions;

        void addTransaction(string transaction);
        void displayStatement();
};



//Account Preview
void BankAccount::displayAccountInfo() {
    cout << "\nAccount Number: " << accountNumber << endl;
    cout << "Account Name: " << name << endl;
    cout << "Account Balance: Php" << balance << endl;
}

//Deposit Money
void BankAccount::deposit(float amount) {
    if (amount > 0) {
        balance += amount;
        cout << "Deposit successful. Your new balance is Php" << balance << endl;
    } else {
        cout << "Please enter a valid amount to deposit." << endl;
    }
}

// Withdraw money
void BankAccount::withdraw(float amount) {
    if (amount > 0) {
        if (balance >= amount) {
            balance -= amount;
            cout << "\nWithdrawal successful. Your new balance is Php" << balance << endl;
        } else {
            cout << "\nInsufficient balance." << endl;
        }
    } else {
        cout << "\nPlease enter a valid amount to withdraw." << endl;
    }
}

//Compute Interest
void BankAccount :: computeinterest(){
    
    // Calculate and Check for the Interest
    
    float interestRate, time, interest;
    char period, type;

    cout << "Do you want to calculate simple (s) or compound (c) interest?: ";
    cin >> type;
                
    if (type == 'c') //Compound Interest
        {
        float interest,A,Af,Ai,t;
        bool R = false, N = false, T = false;
        int p,n;      
            //Rate
            do
            {   
            cout << "Enter the Compound interest rate (in decimals): ";
            if (cin >> interestRate){ 
                if (interestRate > 0 && interestRate < 1) {
                    cout << "\nInterest Rate is accepted." << endl;
                    R = true;
                } else {
                    cout << "\nInterest Rate is not accepted. Enter decimal between 0 to 1." << endl;
                    }   
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nInvalid input. Please enter a number." << endl;
            }  
            } 
            while (R != true);
        
            //Compound number
            do
            {   
            cout << "Enter the number of times is it compounded per year: ";
            if (cin >> n){
                if (n > 0) {
                    cout << "\nValue is accepted." << endl;
                    N = true;
                } else {
                    cout << "\nValue Rate is not accepted. Enter number greater than 0." << endl;
                }
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nInvalid input. Please enter a number." << endl;
            }
            } while (N != true);

            //Time Period
            do
            {
            cout << "Enter the time period (in years): ";
            if (cin >> t){
                if (t > 0) {
                    cout << "\nValue is accepted." << endl;
                    T = true;
                } else {
                    cout << "\nValue is not accepted. Enter number greater than 0." << endl;
                }
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nInvalid input. Please enter a number." << endl;
            }
            }while (T != true);
                
            p = n*t;
            Ai = 1+(interestRate/n);
            Af = pow(Ai,p);
            A = balance*Af;
            interest = A - balance;

            cout << "\nYour interest is Php"<<interest<<endl;
            // Simple Interest
    }else if (type =='s'){ 
            bool R = false, T = false, X = false;

            //Rate
            do
            {   
            cout << "Enter the interest rate (in decimals): ";
            if (cin >> interestRate){ 
                if (interestRate > 0 && interestRate < 1) {
                    cout << "\nInterest Rate is accepted." << endl;
                    R = true;
                } else {
                    cout << "\nInterest Rate is not accepted. Enter decimal between 0 to 1." << endl;
                    }   
            } else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nInvalid input. Please enter a number." << endl;
            }  
            } 
            while (R != true);
                
            // Time Period: How many years are you going to Invest
            do
            {
            cout << "Enter the time period (in years): ";
            cin >> time;
                if (cin.fail()){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\nInvalid input. Please enter a number." << endl;
                } else if (time > 0) {
                    cout << "\nValue is accepted." << endl;
                    T = true;
                } else {
                    cout << "\nValue is not accepted. Enter time greater than 0." << endl;
                }
            } while (T != true);
                
            //Annual, Quarterly, Monthly
            cout << "Is the interest added annually(a), quarterly(q), or monthly(m)?: ";
            cin >> period;
                    
            // Annual Intererest
            if (period=='a') {
                float interest = balance * interestRate* time; 
                }
            // Quarterly Interest
            else if (period =='q') {
                float interest = balance * interestRate* (time*4); 
                } 
            // Monthly Intrest
                else if (period =='m') {
                float interest = balance * interestRate* (time*12);
                 }
            else {
                cout << "Invalid choice.\n";
                return;
                }
            cout << "Your interest is " << interest << endl;
    } else if(type !='s','c')
        {
            cout << "\nInvalid choice.\n";
    }
}
// Bank Transaction
void BankAccount::addTransaction(string transaction) {
    transactions.push_back(transaction);
}
// Bank Statement
void BankAccount::displayStatement() {
    cout << "\nTransaction History:" << endl;
    for (int i = 0; i < transactions.size(); i++) {
        cout << transactions[i] << endl;
    }
}
//Main Program
int main() {
    //Initialize variables
    int choice;
    string name;
    int accountNumber;
    float balance;

    //Opening - create an account
    cout << "\n===========================" << endl;
    cout << "     Bank of One Eleven     " << endl;
    cout << "===========================" << endl;
    cout << "" <<endl;
    cout << "Create an account to get started." << endl;
    cout << "" <<endl;
    // Account Number
    while (true) {
    cout << "Enter Account Number (6 digits. It must not start with 0.): ";
        if (!(cin >> accountNumber) || accountNumber < 100000 || accountNumber > 1000000) {
            cout << "Invalid input. Please enter a 6-digit number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize> ::max(), '\n');
            }
            else {
                break; // Break out of the loop if input is valid
            }
    }

    cout << "" <<endl;
// Account Name
    while (true) {
        cout << "Enter Name: ";
        cin>> name;

        bool valid_name = true;
        for (char c : name) {
            if (isdigit (c)) {
                valid_name = false;
                break;
            }
        }

        if (valid_name) {
            break;
        } else {
            cout << "Invalid name. Name cannot contain numeric digits"<< endl;
        }
    }

    cout << "" <<endl;
  // Account Deposit 
   while (true){
    cout << "Enter Initial Deposit (minimum: Php 500): ";
    cin >> balance;
    if (balance < 500) {
        cout << "\nPlease enter at least Php 500." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize> ::max(), '\n');
    }
    else {
        break; // exit the loop
    
    }
    }

    cout << "\nAccount Successfully Created!" << endl;
    
    //initialization
    BankAccount account;
    account.name = name;
    account.accountNumber = accountNumber;
    account.balance = balance;

    //Main menu
    do {
        cout << "\n===========================" << endl;
        cout << "     Bank of One Eleven     " << endl;
        cout << "===========================" << endl;
        cout << "1. DEPOSIT" << endl;
        cout << "2. WITHDRAW" << endl;
        cout << "3. DISPLAY ACCOUNT INFO" << endl;
        cout << "4. COMPUTE INTEREST" << endl;
        cout << "5. TRANSACTION HISTORY" << endl;
        cout << "6. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
            if (choice < 1) {
                cout << "\nPlease enter a valid value." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize> ::max(), '\n');;
            }
                else {
        // Options
        switch (choice) {
            case 1:
                float depositAmount;
                cout << "\nEnter amount to deposit: ";
                if (!(cin >> depositAmount)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize> ::max(), '\n');
                    cout << "\nInvalid input.";
                    break;
                }  
                    account.deposit(depositAmount);
                    account.addTransaction("Deposit: Php " + to_string(depositAmount));
                    break;
                    
            case 2:
                float withdrawAmount;
                cout << "\nEnter amount to withdraw: ";
                if (!(cin >> withdrawAmount)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize> ::max(), '\n');
                    cout << "\nInvalid input.";
                    break;
                } 
                    account.withdraw(withdrawAmount);
                    account.addTransaction("Withdrawal: Php " + to_string(withdrawAmount));
                    break;
        
            case 3:
                account.displayAccountInfo();
                break;
            
            case 4: 
                account.computeinterest();
                break;

            case 5:
                account.displayStatement();
                break;

            case 6:
                cout << "Thank you for banking with us!" << endl;
                cout << "\n \n";
                // Receipt
                cout << "+--------------------------------------+" << endl;
                cout << "|            BANK RECEIPT              |" << endl;
                cout << "+--------------------------------------+" << endl;
                cout << " Account: " << name << endl;
                cout << " Account No.: " << accountNumber << endl;
                cout << " Balance: Php" << account.balance << endl;
                cout << "+--------------------------------------+" << endl;
                cout << "|    Thank you for your transaction.   |" << endl;
                cout << "+--------------------------------------+" << endl;
                break;

            default:
                cout << "\nInvalid choice. Please try again." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize> ::max(), '\n');;
        }
    } 
    } while (choice != 6);
    //End of Program
} 
