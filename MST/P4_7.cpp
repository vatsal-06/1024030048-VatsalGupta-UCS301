#include <iostream>
using namespace std;

class Rectangle {
    double length;
    double width;
    static int countRect;

    public:
        Rectangle(double l = 1.0, double w = 1.0) {
            this->length = l;
            this->width = w;
            countRect++;
        }

        friend double calculateArea(Rectangle &rect);

        friend double calculatePerimeter(Rectangle &rect);

        static void compareArea(Rectangle &rect1, Rectangle &rect2);

        static int getCount() {
            return countRect;
        }
};

double calculateArea(Rectangle &rect) {
    return rect.length * rect.width;
}

double calculatePerimeter(Rectangle &rect) {
    return 2 * (rect.length + rect.width);
}

void Rectangle::compareArea(Rectangle &rect1, Rectangle &rect2) {
    if (calculateArea(rect1) > calculateArea(rect2)) {
        cout << "Rectangle 1 has larger area" << endl;
    } else if (calculateArea(rect1) < calculateArea(rect2)) {
        cout << "Rectangle 2 has larger area" << endl;
    } else {
        cout << "Both have equal areas" << endl;
    }
}

int Rectangle::countRect = 0;

int main() {
    Rectangle* rects[3];

    for(int i = 0; i < 3; i++) {
        rects[i] = new Rectangle(i+1, i+1);
    }

    cout << "----Rectangle Details----" << endl;
    for(int i = 0; i < 3; i++) {
        cout << "Area: " << calculateArea(*rects[i]) << endl;
        cout << "Perimeter: " << calculatePerimeter(*rects[i]) << endl;
        cout << endl;
    }

    cout << "----Comparing Rectangle 1 and Rectangle 2----" << endl;
    Rectangle::compareArea(*rects[0], *rects[1]);

    cout << "\nTotal Rectangles Created: " << Rectangle::getCount() << endl;

    // Free allocated memory
    for (int i = 0; i < 3; i++) {
        delete rects[i];
    }

    return 0;
}