#include <iostream>
using namespace std;

class Complex {
    private:
        int real;
        int imaginary;
    public:
        void set(int r = 0, int i = 0) {
            real = r;
            imaginary = i;
        }

        void display() {
            cout << real << " + " << imaginary << "i" << endl;
        }

        void sum(Complex &c1, Complex &c2) {
            Complex c3;
            c3.real = c1.real + c2.real;
            c3.imaginary = c1.imaginary + c2.imaginary;
            c3.display();
        }
};

int main() {
    Complex c1, c2, c3;
    c1.set(2, 2);
    c2.set(3, 4);
    c3.sum(c1, c2);
    return 0;
}