#include <iostream>
using namespace std;

class Recipient;

class Donor {
    private:
        string donor_name;
        double balance;

    public:
        void set_details(string name, double bal) {
            this->donor_name = name;
            this->balance = bal;
        }

        void display(Donor &donor) {
            cout << "Donor details: " << endl;
            cout << "Name: " << donor.donor_name << endl;
            cout << "Balance: " << donor.balance << endl;
        }

        double getBalance(Donor &donor) {
            return donor.balance;
        }

        friend void transfer(Donor &donor, Recipient &recipient, double amount);
};

class Recipient {
    private:
        string recipient_name;
        double balance;

    public:

        void set_details(string name, double bal) {
            this->recipient_name = name;
            this->balance = bal;
        }

        void display(Recipient &recipient) {
            cout << "Donor details: " << endl;
            cout << "Name: " << recipient.recipient_name << endl;
            cout << "Balance: " << recipient.balance << endl;
        }

        double getBalance(Recipient &recipient) {
            return recipient.balance;
        }

        friend void transfer(Donor &donor, Recipient &recipient, double amount);
};

void transfer(Donor &donor, Recipient &recipient, double amount) {
    donor.balance -= amount;
    recipient.balance += amount;
    cout << "Amount Transfer: " << amount << endl;
}

int main() {

    Donor donor;
    Recipient recipient;
    string donor_name, recipient_name;
    double donor_balance, recipient_balance, amount;
    cout << "Enter donor name and balance: ";
    cin >> donor_name >> donor_balance;
    donor.set_details(donor_name, donor_balance);
    cout << "Enter recipient name and balance: ";
    cin >> recipient_name >> recipient_balance;
    recipient.set_details(recipient_name, recipient_balance);   
    cout << "Enter amount to be transferred: ";
    cin >> amount;
    cout << endl;
    donor.display(donor);
    recipient.display(recipient);
    cout << endl;

    transfer(donor, recipient, amount);
    cout << endl;

    donor.display(donor);
    recipient.display(recipient);
    cout << endl;

    return 0;
}
