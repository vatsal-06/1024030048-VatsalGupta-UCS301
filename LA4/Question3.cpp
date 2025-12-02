#include <iostream>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    queue<int> firstHalf;
    queue<int> secondHalf;

    for(int i = 0; i < n / 2; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    for(int i = n / 2; i < n; i++) {
        secondHalf.push(q.front());
        q.pop();
    }

    while(!firstHalf.empty() && !secondHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(secondHalf.front());
        secondHalf.pop();
    }
}

int main() {

    queue<int> q;
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);

    interleaveQueue(q);

    // Print result
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}