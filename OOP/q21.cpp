#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>

#define numaccounts 100
#define min_bal 1000
#define interest_rate 0.04

using namespace std;

class SavingsAccount {
public:
    string name;
    int accountNumber;
    double balance;

    SavingsAccount() : accountNumber(0), balance(0.0) {}

    void createAccount(int index) {
        name = "AccountHolder" + to_string(index + 1);
        accountNumber = index + 1;
        balance = min_bal + (rand() % 99001); 
    }

    void addInterest() {
        balance += balance * interest_rate;
    }

    void displayAccount() const {
        cout << "Account Number: " << accountNumber 
             << ", Name: " << name 
             << ", Balance: Rs. " << fixed << setprecision(2) << balance << endl;
    }
};

void createAccounts(SavingsAccount* accounts) {
    srand(time(0));
    for (int i = 0; i < numaccounts; ++i) {
        accounts[i].createAccount(i);
    }
}

void calculateInterest(SavingsAccount* accounts) {
    double totalInterest = 0.0;
    for (int i = 0; i < numaccounts; ++i) {
        double interest = accounts[i].balance * interest_rate;
        totalInterest += interest;
        accounts[i].addInterest();
    }
    cout << "Total interest paid to all accounts in one year: Rs. " << fixed << setprecision(2) << totalInterest << endl;
}

void printAccounts(const SavingsAccount* accounts) {
    for (int i = 0; i < numaccounts; ++i) {
        accounts[i].displayAccount();
    }
}

int main() {
    SavingsAccount accounts[numaccounts];

    createAccounts(accounts);

    cout << "Initial Account Balances:\n";
    printAccounts(accounts);

    calculateInterest(accounts);

    cout << "\nUpdated Account Balances after adding interest:\n";
    printAccounts(accounts);

    return 0;
}
