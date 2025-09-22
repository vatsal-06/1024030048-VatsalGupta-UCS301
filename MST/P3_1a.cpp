#include <iostream>
using namespace std;

class Triangle {
    int base;
    int height;

    public:
        Triangle() : base(0), height(0) {}

        Triangle(int b, int h) {
            base = b;
            height = h;
        }

        bool compareArea(Triangle &t1, Triangle &t2) {
            return (0.5 * t1.base * t1.height) > (0.5 * t2.base * t2.height);
        }

    };



int main() {
    Triangle t1, t2;
    t1 = Triangle(10, 20);
    t2 = Triangle(10, 15);
    if (t1.compareArea(t1, t2)) {
        cout << "Triangle 1 is larger." << endl;
    } else {
        cout << "Triangle 2 is larger." << endl;
    }
    return 0;
}