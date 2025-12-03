#include <bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> s1, s2;

public:
    // Enqueue Operation
    void enqueue(int x) {
        // Move all elements from s1 -> s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push new element into s1
        s1.push(x);

        // Move everything back s2 -> s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

        cout << x << " enqueued\n";
    }

    // Dequeue Operation
    void dequeue() {
        if (s1.empty()) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << s1.top() << " dequeued\n";
        s1.pop();
    }

    // Get front
    int front() {
        if (s1.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return s1.top();
    }

    bool isEmpty() {
        return s1.empty();
    }
};

//method 2
class Queue {
    stack<int> s1, s2;

public:
    // Enqueue Operation: O(1)
    void enqueue(int x) {
        s1.push(x);
        cout << x << " enqueued\n";
    }

    // Dequeue Operation: O(n)
    void dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue Underflow\n";
            return;
        }

        // Move elements only when s2 is empty
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << s2.top() << " dequeued\n";
        s2.pop();
    }

    // Get Front element
    int front() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        // Move only when s2 is empty
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    // Check empty
    bool isEmpty() {
        return (s1.empty() && s2.empty());
    }
};