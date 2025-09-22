#include <iostream>
using namespace std;

class Number {
    private:
        int var1, var2, var3, var4; 

    public:
        Number(int v1 = 0, int v2 = 0, int v3 = 0, int v4 = 0) {
            var1 = v1;
            var2 = v2;
            var3 = v3;
            var4 = v4;
        }

        void showData() {
            cout << "Variables: " << var1 << ", " << var2 << ", " << var3 << ", " << var4 << endl;
        }
};

int main() {

    Number n1;
    Number n2(10, 20);
    Number n3(30, 40, 50, 60);
    Number n4(n2);
    Number n5 = n1;

    n1.showData();
    n2.showData();
    n3.showData();
    n4.showData();
    n5.showData();

    return 0;
}