class BankAccount {
    int accountNumber;
    float balance;
    String ownerName;

    BankAccount(int accountNumber, float balance, String ownerName) {
        this.accountNumber = accountNumber;
        this.balance = balance;
        this.ownerName = ownerName;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    float getBalance() {
        return balance;
    }

    String getOwnerName() {
        return ownerName;
    }

    void displayBalance() {
        System.out.println("Account Number: " + accountNumber + ", Balance: " + balance);
    }

    void add(float amount) {
        balance += amount;
        System.out.println("Deposited " + amount + ". New Balance: " + balance);
    }

    void subtract(float amount) {
        balance -= amount;
        System.out.println("Withdrew " + amount + ". New Balance: " + balance);
    }

    void details() {
        System.out.println("Account Number: " + accountNumber + ", Owner: " + ownerName + ", Balance: " + balance);
    }
}
class AccountManager {
    BankAccount[] accounts;
    int count;

    AccountManager(int maxAccounts) {
        accounts = new BankAccount[maxAccounts];
        count = 0;
    }

    void create(int accountNumber, float balance, String ownerName) {
        if (count < accounts.length) {
            accounts[count++] = new BankAccount(accountNumber, balance, ownerName);
            System.out.println("Account created: " + accountNumber);
        } else {
            System.out.println("Maximum account limit reached.");
        }
    }

    void delete(int accountNumber) {
    for (int i = 0; i < count; i++) {
        if (accounts[i].getAccountNumber() == accountNumber) {
            System.out.println("Account " + accountNumber + " deleted.");
            for (int j = i; j < count - 1; j++) {
                accounts[j] = accounts[j + 1];
            }
            accounts[--count] = null;
            return;
            }
        }
        System.out.println("Account not found: " + accountNumber);
    }

    void deposit(int accountNumber, float amount) {
        for (int i = 0; i < count; i++) {
            if (accounts[i].getAccountNumber() == accountNumber) {
                accounts[i].add(amount);
                return;
            }
        }
        System.out.println("Account not found: " + accountNumber);
    }

    void withdraw(int accountNumber, float amount) {
        for (int i = 0; i < count; i++) {
            if (accounts[i].getAccountNumber() == accountNumber) {
                accounts[i].subtract(amount);
                return;
            }
        }
        System.out.println("Account not found: " + accountNumber);
    }

    void allAccounts() {
        System.out.println("All Accounts:");
        for (int i = 0; i < count; i++) {
            accounts[i].details();
        }
    }
}
class Bank {
    public static void main(String[] args) {
        AccountManager manager = new AccountManager(10);

        manager.create(101, 5000.0f, "Mehendi");
        manager.create(102, 3500.0f, "Debodit");
        manager.create(103, 8000.0f, "Arnob");
        manager.create(104, 4000.0f, "Touseef");
        manager.create(105, 9000.0f, "Aritra");

        System.out.println("\nInitial Account Details:");
        manager.allAccounts();

        System.out.println("\nTransactions:");
        manager.deposit(103, 500.0f);
        manager.withdraw(104, 500.0f);

        manager.delete(101);

        System.out.println("\nFinal Account Details:");
        manager.allAccounts();
    }
}
