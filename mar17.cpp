#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Account {
public:
    string name;
    int accountNumber;
    int pin;
    double balance;

    Account(string n, int accNum, int p, double bal) {
        name = n;
        accountNumber = accNum;
        pin = p;
        balance = bal;
    }

    bool verifyPin(int enteredPin) {
        return pin == enteredPin;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: $" << amount << endl;
    }

    bool withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
            return false;
        }
        balance -= amount;
        cout << "Withdrawn: $" << amount << endl;
        return true;
    }

    void displayBalance() {
        cout << "Current balance: $" << balance << endl;
    }
};

class ATM {
private:
    vector<Account> accounts;

public:
    void addAccount(Account acc) {
        accounts.push_back(acc);
    }

    Account* findAccount(int accNum) {
        for (auto &acc : accounts) {
            if (acc.accountNumber == accNum) return &acc;
        }
        return nullptr;
    }

    void start() {
        int accNum, enteredPin;
        cout << "Enter Account Number: ";
        cin >> accNum;
        Account* user = findAccount(accNum);
        if (!user) {
            cout << "Account not found!" << endl;
            return;
        }

        cout << "Enter PIN: ";
        cin >> enteredPin;
        if (!user->verifyPin(enteredPin)) {
            cout << "Wrong PIN!" << endl;
            return;
        }

        int choice;
        do {
            cout << "\n--- ATM Menu ---\n";
            cout << "1. Check Balance\n";
            cout << "2. Deposit\n";
            cout << "3. Withdraw\n";
            cout << "4. Transfer\n";
            cout << "5. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch(choice) {
                case 1:
                    user->displayBalance();
                    break;
                case 2: {
                    double amt;
                    cout << "Enter amount to deposit: ";
                    cin >> amt;
                    user->deposit(amt);
                    break;
                }
                case 3: {
                    double amt;
                    cout << "Enter amount to withdraw: ";
                    cin >> amt;
                    user->withdraw(amt);
                    break;
                }
                case 4: {
                    int targetAcc;
                    double amt;
                    cout << "Enter target account number: ";
                    cin >> targetAcc;
                    Account* target = findAccount(targetAcc);
                    if (!target) {
                        cout << "Target account not found!" << endl;
                        break;
                    }
                    cout << "Enter amount to transfer: ";
                    cin >> amt;
                    if (user->withdraw(amt)) {
                        target->deposit(amt);
                        cout << "Transferred $" << amt << " to " << target->name << endl;
                    }
                    break;
                }
                case 5:
                    cout << "Exiting ATM. Thank you!\n";
                    break;
                default:
                    cout << "Invalid choice!\n";
            }
        } while(choice != 5);
    }
};

int main() {
    ATM atm;

    // Add sample accounts
    atm.addAccount(Account("Alice", 1001, 1234, 5000.0));
    atm.addAccount(Account("Bob", 1002, 2345, 3000.0));
    atm.addAccount(Account("Charlie", 1003, 3456, 7000.0));

    atm.start();

    return 0;
}
