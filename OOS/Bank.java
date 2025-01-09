class BankAccount {
    private int accountNumber;
    private double balance;
    private String ownerName;

    public BankAccount(int accountNumber, double initialBalance, String ownerName) {
        this.accountNumber = accountNumber;
        this.balance = initialBalance;
        this.ownerName = ownerName;
    }

    public double getBalance() {
        return balance;
    }

    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            System.out.println("Invalid deposit amount.");
        }
    }

    public void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        } else {
            System.out.println("Invalid or insufficient funds for withdrawal.");
        }
    }

    public void displayDetails() {
        System.out.println("Account Number: " + accountNumber);
        System.out.println("Owner Name: " + ownerName);
        System.out.println("Balance: " + balance);
        System.out.println("-----------------------");
    }

    public int getAccountNumber() {
        return accountNumber;
    }
}

class AccountManager {
    private BankAccount[] accounts;
    private int count;

    public AccountManager(int capacity) {
        accounts = new BankAccount[capacity];
        count = 0;
    }

    public void create(int accountNumber, double initialBalance, String ownerName) {
        if (count < accounts.length) {
            accounts[count++] = new BankAccount(accountNumber, initialBalance, ownerName);
        } else {
            System.out.println("Maximum account limit reached. Cannot create new account.");
        }
    }

    public void delete(int accountNumber) {
        for (int i = 0; i < count; i++) {
            if (accounts[i].getAccountNumber() == accountNumber) {
                accounts[i] = accounts[--count];
                accounts[count] = null;
                System.out.println("Account " + accountNumber + " has been deleted.");
                return;
            }
        }
        System.out.println("Account number " + accountNumber + " not found.");
    }

    public void deposit(int accountNumber, double amount) {
        for (BankAccount account : accounts) {
            if (account != null && account.getAccountNumber() == accountNumber) {
                account.deposit(amount);
                return;
            }
        }
        System.out.println("Account number " + accountNumber + " not found.");
    }

    public void withdraw(int accountNumber, double amount) {
        for (BankAccount account : accounts) {
            if (account != null && account.getAccountNumber() == accountNumber) {
                account.withdraw(amount);
                return;
            }
        }
        System.out.println("Account number " + accountNumber + " not found.");
    }

    public void displayAllAccounts() {
        if (count == 0) {
            System.out.println("No accounts available.");
        } else {
            for (int i = 0; i < count; i++) {
                accounts[i].displayDetails();
            }
        }
    }
}

public class Bank {
    public static void main(String[] args) {
        AccountManager manager = new AccountManager(10);

        manager.create(101, 1000.50, "Mehendi");
        manager.create(102, 2500.75, "Debodit");
        manager.create(103, 1500.00, "Touseef");
        manager.create(104, 500.25, "Arnob");
        manager.create(105, 3000.10, "Aritra");

        System.out.println("Initial account details:");
        manager.displayAllAccounts();

        manager.deposit(101, 500);
        manager.withdraw(102, 300);
        manager.delete(104);

        System.out.println("Updated account details:");
        manager.displayAllAccounts();
    }
}
