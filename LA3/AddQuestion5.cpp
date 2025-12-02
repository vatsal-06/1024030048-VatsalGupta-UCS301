#include <iostream>
using namespace std;

bool sortedArrays(const vector<int>& input) {
    stack<int> st;
    int n = input.size();
    vector<int> sorted = input;

    sort(sorted.begin(), sorted.end());
    int idx = 0;

    for(int x : input) {
        st.push(x);
        while(!st.empty() && st.top() == sorted[idx]) {
            st.pop();
            idx++;
        }
    }

    return (idx == n);
} 

int main() {
    vector<int> A = {2, 3, 1};

    if (sortedArrays(A))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}