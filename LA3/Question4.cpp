#include <iostream>
#include <stack>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string convert(string s) {
    stack<char> st;
    string output;
    for (char c : s) {
        if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9') {
            output += c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (st.empty() == false && st.top() != '(') {
                output += st.top();
                st.pop();
            }
            if (st.empty() == false) {
                st.pop();
            }
        } else {
            while (st.empty() == false && precedence(st.top()) >= precedence(c)) {
                output += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        output += st.top();
        st.pop();
    }
    return output;
}

int main() {
    string s = "A+B*C/D-(E-F)";
    string result = convert(s);
    cout << "Postfix: " << result << endl;
    return 0;
}
