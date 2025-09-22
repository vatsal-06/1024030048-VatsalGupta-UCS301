#include <iostream>
using namespace std;

class Vehicle {
    protected:
        string make;
        string model;
        int year;
        static int count;
    public:
        Vehicle(string make = "Unknown", string model = "Unknown", int year = 0) {
            this->make = make;
            this->model = model;
            this->year = year;
            count++;
        }

        static int getVehicleCount() {
            return count;
        }
};

class Car : public Vehicle {
    private:
        int numberOfDoors;
    public:
        Car(string make, string model, int year, int doors) : Vehicle(make, model, year) {
            this->numberOfDoors = doors;
        }

        void showDetails() {
            cout << "Make: " << make << endl;
            cout << "Model: " << model << endl;
            cout << "Year: " << year << endl;
            cout << "Number of Doors: " << numberOfDoors << endl;
        }
};

class Bike : public Vehicle {
    private:
        string type;
    public:
        Bike(string make, string model, int year, string type) : Vehicle(make, model, year) {
            this->type = type;
        }

        void showDetails() {
            cout << "Make: " << make << endl;
            cout << "Model: " << model << endl;
            cout << "Year: " << year << endl;
            cout << "Type: " << type << endl;
        }
};

class Truck : public Vehicle {
    private:
        double loadCapacity;
    public:
        Truck(string make, string model, int year, double loadCapacity) : Vehicle(make, model, year) {
            this->loadCapacity = loadCapacity;
        }

        void showDetails() {
            cout << "Make: " << make << endl;
            cout << "Model: " << model << endl;
            cout << "Year: " << year << endl;
            cout << "Load Capacity: " << loadCapacity << endl;
        }
};

int Vehicle::count = 0;

int main() {
    Car c1("Toyota", "Corolla", 2022, 4);
    Car c2("Honda", "Civic", 2021, 2);

    Bike b1("Yamaha", "R15", 2020, "Petrol");
    Bike b2("Hero", "Photon", 2023, "EV");

    Truck t1("Volvo", "FH16", 2019, 25.5);

    cout << "Vehicle Details:\n";
    c1.showDetails();
    cout << endl;
    c2.showDetails();
    cout << endl;
    b1.showDetails();
    cout << endl;
    b2.showDetails();
    cout << endl;
    t1.showDetails();

    cout << "\nTotal Vehicles Created: " << Vehicle::getVehicleCount() << endl;


    return 0;
}