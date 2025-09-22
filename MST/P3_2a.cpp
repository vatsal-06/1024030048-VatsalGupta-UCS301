#include <iostream>
using namespace std;

class Car {
    int speed;
    int fuel;

    public:
        Car(int s, int f) {
            this->speed = s;
            this->fuel = f;
        }

        void display() {
            cout << "Speed: " << speed << ", Fuel: " << fuel << endl;
        }
};

int main() {
    Car car(100, 50);
    car.display();
    return 0;
}