#include <iostream>
#include <string>
using namespace std;

string checkAnagram(string str1, string str2) {
    if(str1.length() != str2.length()) {
        return "NO";
    }
    
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    
    if(str1 == str2) {
        return "YES";
    }
    return "NO";
}

int main() {
    string str1, str2;
    str1 = "listen";
    str2 = "silent";

    cout << checkAnagram(str1, str2) << endl;

    return 0;
}