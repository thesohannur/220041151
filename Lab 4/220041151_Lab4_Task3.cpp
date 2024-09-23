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

    BankAccount () : accountNumber(0), accountHolderName("Default"), accountType("Default"), balance(0), interestRate(3.0)}
    BankAccount(int accountNumber, string accountHolderName, string accountType , float balance,int totalAccounts,float totalSourceTax, const float interestRate)
    {
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->accountType = accountType;
        this->balance = balance;
        this->totalAccounts = totalAccounts;
        this->totalSourceTax = totalAccounts;
        totalAccounts++;
    }

    void showAllinfo()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Current Balance: " << balance << endl;
    }

    void showBalance()
    {
        cout << "Current Balance: " << balance << endl;
    }

    void deposit(float amount)
    {
        if(amount > 0)
        {
            balance += amount;
        }
        else
        {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdrawal(float amount)
    {
        if(amount > 0 && balance - amount >= 0)
        {
            balance -= amount;
        }
        else
        {
            cout << "Invalid withdrawal amount." << endl;
        }
    }

    void Total_interest()
    {
        float interest = (balance*interestRate)/100;
        float sourceTax = (interest * 10) / 100;
        balance += interest - sourceTax;
        totalSourceTax += sourceTax;
    }

    static int getTotalAccounts()
    {
        return totalAccounts;
    };

    static float getTotalSourceTax()
    {
        return totalSourceTax;
    }

    ~BankAccount()
    {
        totalAccounts--;
        cout << "Account of Mr. " << accountHolderName << " with account no " << accountNumber << " is destroyed with a balance BDT " << balance << endl;
    }

};

void display_stat()
{
    cout << "Total number of accounts: " << BankAccount::totalAccounts() << endl;
    cout << "Total source tax collected: BDT " << BankAccount::totalSourceTax() << endl;
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




