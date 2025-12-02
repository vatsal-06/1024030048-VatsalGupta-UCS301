#include <iostream>
#include <queue>
using namespace std;

void firstNonRepeating(string s) {
    queue<char> q;
    int freq[26] = {0};

    for(char c : s) {
        freq[c - 'a']++; 
        q.push(c);             

        // remove repeating characters from front
        while(!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        // output current non-repeating char
        if(q.empty())
            cout << "-1 ";
        else
            cout << q.front() << " ";
    }
}

int main() {
    string s = "aabc";
    firstNonRepeating(s);
    return 0;
}
