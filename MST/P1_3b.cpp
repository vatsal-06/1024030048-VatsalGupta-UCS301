#include <iostream>
using namespace std;

class A {
    int var1;
    int var2;

    public:
    A() {
        var1 = 0;
        var2 = 0;
    }

    void setData(int v1, int v2) {
        var1 = v1;
        var2 = v2;
    }

    void updateData() {
        var1++;
        var2++;
    }

    void output() {
        cout << "var1: " << var1 << ", var2: " << var2 << endl;
    }

    ~A() {
        cout << "Destructor called for var1: " << var1 << ", var2: " << var2 << endl;
    }
};

int main() {
    A* a = new A[5];
    for (int i = 1; i < 6; i++) {
        a[i].setData(i, i*10);
        a[i].updateData();
        a[i].output();
    }
    delete[] a;

    return 0;
}