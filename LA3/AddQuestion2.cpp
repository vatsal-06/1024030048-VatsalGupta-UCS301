#include <iostream>
using namespace std;
#include<stack>

class SpecialStack {
    stack<int> mainStack;
    stack<int> minStack;

    public:
    void push(int value) {
        mainStack.push(value);
        if (minStack.empty() || value <= minStack.top()) {
            minStack.push(value);
        }
    }

    int pop() {
        if (mainStack.empty()) {
            cout << "Stack is empty" << endl;
            return -1; 
        }
        int topValue = mainStack.top();
        mainStack.pop();
        if (topValue == minStack.top()) {
            minStack.pop();
        }
        return topValue;
    }

    int getMin() {
        if (minStack.empty()) {
            cout << "Stack is empty" << endl;
            return -1; 
        }
        return minStack.top();
    }
};

int main() {
    SpecialStack s;
    s.push(10);
    s.push(20);
    s.push(5);
    s.push(30);

    cout << "Minimum element: " << s.getMin() << endl;

    return 0;
}
