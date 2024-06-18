// bank.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
using namespace std;
#include <iostream>
class Bank {
    friend bool Transfer(Bank& fromAccount, Bank& toAccount, double amount) {
        if (fromAccount.Getbalance() >= amount) {
            fromAccount.Withdraw(amount);
            toAccount.Deposit(amount);
            return true;
        }
        else {
            return false;
        }
    }
private:
    int accountNumber;
    double balance;
    double interestRate;
    

public:
    Bank(int accountNumber, double balance, double interestRate) {
        this->accountNumber = accountNumber;
        this->balance = balance;
        this->interestRate = interestRate;
    }
    double Getbalance() {
        return balance;
    }
    int GetAccountNumber() {
        return accountNumber;
    }
    double GetInterest() {
        return balance * interestRate * 12.0;
    }

    void Deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
        else {
            throw invalid_argument("Сумма для внесения должна быть положительной");
        }
    }
    void Withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        }
        else {
            throw invalid_argument("Недостаточно средств на счете");
        }
    }
    double SetInterestRate(double newInterestRate) {
        if (newInterestRate >= 0) {
            interestRate = newInterestRate;
        }
        else {
            throw invalid_argument("Процентная ставка не может быть отрицательной");
        }
    }

};
int main()
{
    Bank account1(12345, 2000,0);
    Bank account2(12345, 0,0);

    account1.Deposit(500);
    account1.Withdraw(200);
    account1.SetInterestRate(0.5);

    cout << "Account1  1 balance: " << account1.Getbalance() << endl;
    cout << "Account 1 interest: " << account1.GetInterest() << endl;

    if (Transfer(account1, account2, 300)) {
        cout<< "Transfer successful" << endl;
    }
    else {
        cout << "Transfer failed" << endl;
    }
    cout << "Account2 balance: " << account2.Getbalance() << endl;
}


