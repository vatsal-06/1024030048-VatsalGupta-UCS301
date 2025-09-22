#include <iostream>
using namespace std;

class Appliance {
    private:
        string name;
        double power;

    public:
        Appliance(string n = "Unknown", double p = 0.0) {
            this->name = n;
            this->power = p;
        }

        double getPower() {
            return power;
        }

        friend double getAppliancePower(const Appliance &a);

        void display() {
            cout << "\nAppliance: " << name << endl;
            cout << "Power: " << power << "kW" << endl;
        }
};

class House {
    private:
        int houseId;
        Appliance appliances[5];

    public:
        House(int id, Appliance appList[5]) {
            this->houseId = id;
            for(int i = 0; i < 5; i++) {
                this->appliances[i] = appList[i];
            }
        }

        double totalConsumption() {
            double sum = 0;
            for(int i = 0; i < 5; i++) {
                sum += appliances[i].getPower();
            }
            return sum;
        }

        friend class Grid;

        void display() {
            cout << "\nHouse " << houseId << " Consumption:" << endl;
            for(int i = 0; i < 5; i++) {
                appliances[i].display();
            }
            cout << "\nTotal Consumption for House: " << totalConsumption() << " kW" << endl;
        }
};

class Grid {
    private: 
        House* houses[2];
    
    public:
        Grid(House* h[2]) {
            for(int i = 0; i < 2; i++) {
                houses[i] = h[i];
            }
        }

        double cityConsumption() {
            double total;
            for(int i = 0; i < 2; i++) {
                total += houses[i]->totalConsumption();
            }
            return total;
        }

        void displayReport() {
            cout << "\n----Town Power Consumption Report----\n";
            for(int i = 0; i < 2; i++) {
                houses[i]->display();
            }
            cout << "\n----Total Power Consumption---\n";
            cout << cityConsumption() << " kW" << endl; 
        }
};

double getAppliancePower(const Appliance &a) {
    return a.power;
}

int main() {
    Appliance appliances[5] = {
        Appliance("Fan", 0.1), 
        Appliance("TV", 0.2),
        Appliance("Fridge", 0.8),
        Appliance("Heater", 1.5),
        Appliance("Light", 0.05)
    };

    House* houses[2];
    for(int i = 0; i < 2; i++) {
        houses[i] = new House(i + 1, appliances);
    }

    Grid grid(houses);
    grid.displayReport();

    return 0;
}