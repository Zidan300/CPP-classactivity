#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class MenuItem {
public:
    string name;
    double price;

    MenuItem(string n, double p) {
        name = n;
        price = p;
    }
};

class Order {
private:
    vector<MenuItem> items;

public:
    void addItem(MenuItem item) {
        items.push_back(item);
    }

    void showBill() {
        double total = 0;

        cout << "\n------ BILL ------\n";
        for (auto &item : items) {
            cout << setw(15) << left << item.name 
                 << " $ " << item.price << endl;
            total += item.price;
        }

        cout << "------------------\n";
        cout << "Total: $" << total << endl;
    }
};

int main() {
    vector<MenuItem> menu = {
        MenuItem("Burger", 5.99),
        MenuItem("Pizza", 8.49),
        MenuItem("Pasta", 6.75),
        MenuItem("Coffee", 2.50),
        MenuItem("Cake", 4.20)
    };

    Order order;
    int choice;

    do {
        cout << "\n--- Restaurant Menu ---\n";
        for (int i = 0; i < menu.size(); i++) {
            cout << i + 1 << ". " << menu[i].name 
                 << " - $" << menu[i].price << endl;
        }

        cout << "0. Finish Order\n";
        cout << "Select item: ";
        cin >> choice;

        if (choice > 0 && choice <= menu.size()) {
            order.addItem(menu[choice - 1]);
            cout << "Item added to order.\n";
        }

    } while (choice != 0);

    order.showBill();

    return 0;
}
