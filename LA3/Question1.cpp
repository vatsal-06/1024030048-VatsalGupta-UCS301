#include <iostream>
using namespace std;

const int MAX = 100;

class Stack {
    public: 
        typedef struct {
        int element[MAX];
        int top;
        } stack;

        stack init() {
            stack s;
            s.top = -1;
            return s;
        }

        int isEmpty(stack s) {
            return s.top == -1;
        }

        int isFull(stack s) {
            return s.top == MAX - 1;
        }

        int top(stack s) {
            if (!isEmpty(s)) {
                return s.element[s.top];
            }
            return -1;  // Meaningful value indicating stack is empty
        }

        stack push(stack s, int val) {
            if (isFull(s)) {
                cout << "OVERFLOW" << endl;
                return s;
            } else {
                ++s.top;
                s.element[s.top] = val;
            }
            return s;
        }

        stack pop(stack s) {
            if (isEmpty(s)) {
                cout << "UNDERFLOW" << endl;
                return s;
            } else {
                --s.top;
            }
            return s;
        }

        void print (stack s) {
            for (int i = s.top; i >= 0; --i) {
                cout << s.element[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    Stack stack;
    Stack::stack s = stack.init();

    s = stack.push(s, 10);
    s = stack.push(s, 20);
    s = stack.push(s, 30);

    stack.print(s);

    s = stack.pop(s);
    stack.print(s);

    return 0;
}
