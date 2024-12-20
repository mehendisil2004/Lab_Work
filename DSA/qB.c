#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define forn(i, n) for (int i = 0; i < n; ++i)

#define interest 0.05
#define db double

int id = 0;

struct SavingsAccount
{
    int id;
    db balance;
    char name[30];
};

struct SavingsAccount createAccount(char *name, db balance)
{
    struct SavingsAccount *account = (struct SavingsAccount *)malloc(sizeof(struct SavingsAccount));
    account->id = ++id;
    strcpy(account->name, name);
    if (balance < 1000)
    {
        printf("Minimum balance should be 1000\n");
        return createAccount(name, 1000);
    }
    account->balance = balance;
    return *account;
}

void deposit(struct SavingsAccount *account, db amount)
{
    account->balance += amount;
    printf("Amount deposited successfully\n");
}

void withdraw(struct SavingsAccount *account, db amount)
{
    if (account->balance - amount < 1000)
    {
        printf("Insufficient balance\n");
        return;
    }
    account->balance -= amount;
    printf("Amount withdrawn successfully\n");
}

int main()
{
    int n;
    printf("Enter number of accounts: ");
    scanf("%d", &n);
    struct SavingsAccount *accounts = (struct SavingsAccount *)malloc(n * sizeof(struct SavingsAccount));
    srand(time(0));
    db total_interest = 0;
    forn(i, n)
    {
        db balance = (rand() % (100000 - 1000)) + 1000;
        char name[30];
        sprintf(name, "Account %d", i + 1);
        accounts[i] = createAccount(name, balance);
        total_interest += accounts[i].balance * interest;
        accounts[i].balance += accounts[i].balance * interest;
        // printf("Account %s has been created with balance: %lf\n", accounts[i].name, accounts[i].balance);
        printf("Interest to %s is: %lf\n", accounts[i].name, accounts[i].balance * interest);
    }
    printf("Total interest: %lf\n", total_interest);

    return 0;
}