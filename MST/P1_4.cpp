#include <iostream>
using namespace std;

class Tracker {
    private:
        int personId;
        int stepCount;
        int stairCount;
        static int personCount;

    public:
        Tracker(int id = 0, int steps = 0, int stairs = 0) {
            this->personId = id;
            this->stepCount = steps;
            this->stairCount = stairs;
            personCount++;
        }

        static int getCount() {
            return personCount;
        }

        void incrementCount(int n);

        void convertStep();

        void displayCount() {
            cout << "----Details of Person----" << endl;
            cout << "Person ID: " << personId << endl;
            cout << "Number of Steps: " << stepCount << endl;
            cout << "-------------------------" << endl;
        }

        int setId(int n) {
            personId = n;
            return personId;
        }
};

void Tracker::incrementCount(int n) {
    stepCount += n;
    stairCount += n;
}

void Tracker::convertStep() {
    stepCount += (stairCount * 2);
}

int Tracker::personCount = 0;

int main() {

    Tracker* people[3];

    for(int i = 0; i < 3; i++) {
        people[i] = new Tracker;
    }

    for(int i = 0; i < 3; i++) {
        people[i]->setId(i + 1);
    }

    people[0]->incrementCount(100);
    people[1]->incrementCount(50);
    people[2]->incrementCount(200);

    for(int i = 0; i < 3; i++) {
        people[i]->displayCount();
    }

    cout << "Total number of persons tracked: " << Tracker::getCount() << endl;

    return 0;
}