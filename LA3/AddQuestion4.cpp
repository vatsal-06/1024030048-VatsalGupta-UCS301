#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> stk;

        for (int i = n - 1; i >= 0; i--) {

            while (!stk.empty() && temperatures[stk.top()] <= temperatures[i]) {
                stk.pop();
            }

            if (!stk.empty()) {
                result[i] = stk.top() - i;
            }

            stk.push(i);

        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = sol.dailyTemperatures(temperatures);

    for (int days : result) {
        cout << days << " ";
    }
    cout << endl;

    return 0;
}
