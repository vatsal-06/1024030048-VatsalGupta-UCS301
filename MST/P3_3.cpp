#include <iostream>
using namespace std;

class ShoppingCart {
    private:
        int cart_id;
        string customer_name;
        int item_count;

    public:
        ShoppingCart(int id, string name, int count) {
            cart_id = id;
            customer_name = name;
            item_count = count;
        }

        ~ShoppingCart() {
            cout << "Thank you for shopping with us!" << endl;
        }

        void displayCart() {
            cout << "Cart ID: " << cart_id << endl;
            cout << "Customer Name: " << customer_name << endl;
            cout << "Item Count: " << item_count << endl;
        }
};

int main() {
    int n;
    cout << "Enter number of shopping carts: ";
    cin >> n;

    ShoppingCart* carts[n];

    for (int i = 0; i < n; i++) {
        int id, count;
        string name;
        cout << "Enter details for cart " << (i + 1) << " (ID, Name, Item Count): ";
        cin >> id >> name >> count;
        carts[i] = new ShoppingCart(id, name, count);
    }

    for (int i = 0; i < n; i++) {
        cout << "\nDetails of cart " << (i + 1) << ":\n";
        carts[i]->displayCart();
    }

    cout << "\nExiting program..." << endl;

    for (int i = 0; i < n; i++) {
        delete carts[i];
    }
    return 0;
}