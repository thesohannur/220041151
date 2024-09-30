#include <iostream>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string accountHolderName;
    string accountType;
    float balance;
    static int totalAccounts;
    static float totalSourceTax;
    const float interestRate;

public:
    // Default constructor
    BankAccount() : accountNumber(0), accountHolderName("Default"), accountType("Default"), balance(0.0F), interestRate(3.0F) {}

    // Parameterized constructor
    BankAccount(int accountNumber, string accountHolderName, string accountType, float balance)
        : accountNumber(accountNumber), accountHolderName(accountHolderName), accountType(accountType), balance(balance), interestRate(3.0F)
    {
        totalAccounts++;
    }

    // Show all account information
    void showAllinfo()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Current Balance: " << balance << endl;
    }

    // Show balance
    void showBalance()
    {
        cout << "Current Balance: " << balance << endl;
    }

    // Deposit amount
    void deposit(float amount)
    {
        if (amount > 0)
        {
            balance += amount;
        }
        else
        {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Withdraw amount
    void withdrawal(float amount)
    {
        if (amount > 0 && balance - amount >= 0)
        {
            balance -= amount;
        }
        else
        {
            cout << "Invalid withdrawal amount." << endl;
        }
    }

    // Calculate total interest and update balance
    void Total_interest()
    {
        float interest = (balance * interestRate) / 100;
        float sourceTax = (interest * 10) / 100;
        balance += interest - sourceTax;
        totalSourceTax += sourceTax;
    }

    // Static function to get total accounts
    static int getTotalAccounts()
    {
        return totalAccounts;
    }

    // Static function to get total source tax
    static float getTotalSourceTax()
    {
        return totalSourceTax;
    }

    // Destructor
    ~BankAccount()
    {
        totalAccounts--;
        cout << "Account of Mr./Ms. " << accountHolderName << " with account no. " << accountNumber << " is destroyed with a balance of BDT " << balance << endl;
    }
};

// Static member initialization
int BankAccount::totalAccounts = 0;
float BankAccount::totalSourceTax = 0.0F;

// Display statistics
void display_stat()
{
    cout << "Total number of accounts: " << BankAccount::getTotalAccounts() << endl;
    cout << "Total source tax collected: BDT " << BankAccount::getTotalSourceTax() << endl;
}

int main()
{
    BankAccount account1(12345, "John Doe", "Savings", 1000);
    BankAccount account2(67890, "Jane Smith", "Current", 5000);

    account1.showAllinfo();
    account1.deposit(500);
    account1.withdrawal(200);
    account1.showBalance();
    account1.Total_interest();
    account1.showBalance();

    account2.showAllinfo();
    account2.deposit(1000);
    account2.withdrawal(700);
    account2.showBalance();
    account2.Total_interest();
    account2.showBalance();

    display_stat();

    return 0;
}
