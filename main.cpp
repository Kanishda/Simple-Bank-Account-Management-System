#include <iostream>
using namespace std;
class Account {
protected:
    int accountNumber;
    string name;
    double balance;

public:
    Account(int accNo, string accName, double bal) {
        accountNumber = accNo;
        name = accName;
        balance = bal;
    }
    void deposit(double amount) {
        balance += amount;
        cout << "Amount Deposited Successfully!\n";
    }
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient Balance!\n";
        } else {
            balance -= amount;
            cout << "Amount Withdrawn Successfully!\n";
        }
    }
    void display() {
        cout << "\nAccount Number: " << accountNumber << endl;
        cout << "Account Holder: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
};
class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(int accNo, string accName, double bal, double rate)
        : Account(accNo, accName, bal)   // Calling Base Class Constructor
    {
        interestRate = rate;
    }
    void addInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Interest Added Successfully!\n";
    }
};
int main() {
    SavingsAccount acc1(101, "Rahul", 5000, 5);

    acc1.display();

    acc1.deposit(2000);
    acc1.withdraw(1000);
    acc1.addInterest();

    acc1.display();

    return 0;
}
