#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

void concatenateStrings(string str1, string str2) {
    string result = str1 + str2;
    cout << "Concatenated String: " << result << endl;
}

void reverseString(string str) {
    string reversed = string(str.rbegin(), str.rend());
    cout << "Reversed String: " << reversed << endl;
}

void toUpperCase(string str) {
    for (char &c : str) {
        c = toupper(c);
    }
    cout << "Uppercase String: " << str << endl;
}

void deleteVowels(string str) {
    string result;
    for (char c : str) {
        if (!isVowel(c)) {
            result += c;
        }
    }
    cout << "String without Vowels: " << result << endl;
}

void sortString(string &str) {
    sort(str.begin(), str.end());
    cout << "Sorted String: " << str << endl;
}

int main() {
    concatenateStrings("Hello, ", "World!");
    reverseString("Hello, World!");
    toUpperCase("Hello, World!");
    deleteVowels("Hello, World!");
    return 0;
}
