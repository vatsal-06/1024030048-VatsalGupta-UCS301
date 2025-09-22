#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int size = arr.size();
        for(int i = 0; i < size - 1; i++) {
            if(arr[i] == 0) {
                for(int k = size - 1; k > i; k--) {
                    arr[k] = arr[k-1];
                }
                if (i + 1 < size) {
                    arr[i + 1] = 0;
                }
                i++;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1,0,2,3,0,4,5,0};
    sol.duplicateZeros(arr);
    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

