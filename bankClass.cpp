#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

class BankAccount
{
private:
    string accountNumber;
    double balance;

public:
    BankAccount(string accountNumber, double balance)
    {
        this->accountNumber = accountNumber;
        this->balance = balance;
    }

    void deposit(double amount)
    {
        this->balance += amount;
    }

    void withdraw(double amount)
    {
        if (this->balance >= amount)
        {
            this->balance -= amount;
        }
        else
        {
            cout << "Insufficient funds!" << endl;
        }
    }

    void displayDetails()
    {
        cout << "Account Number : " << this->accountNumber << endl;
        cout << "Balance : " << this->balance << endl;
    }
};

int main()
{
    BankAccount newCustomer("123456", 5000.00);
    newCustomer.displayDetails();
    newCustomer.deposit(1500.00);
    newCustomer.displayDetails();
    newCustomer.withdraw(2000.00);
    newCustomer.displayDetails();
    newCustomer.withdraw(5000.00); // Attempt to withdraw more than the balance
    return 0;
}