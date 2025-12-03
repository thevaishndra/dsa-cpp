#include <bits/stdc++.h>
using namespace std;

//method 1
class Stack {
    queue<int> q1, q2;

public:
    // Push operation
    void push(int x) {
        q2.push(x);

        // Move all elements of q1 → q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap names (q1 has newest at front)
        swap(q1, q2);

        cout << x << " pushed\n";
    }

    // Pop operation
    void pop() {
        if (q1.empty()) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << q1.front() << " popped\n";
        q1.pop();
    }

    // Top element
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q1.front();
    }

    // Check empty
    bool isEmpty() {
        return q1.empty();
    }
};


//method 2
class Stack {
    queue<int> q;

public:
    // Push Operation
    void push(int x) {
        q.push(x);
        int size = q.size();

        // Rotate all elements except the new one
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }

        cout << x << " pushed\n";
    }

    // Pop Operation
    void pop() {
        if (q.empty()) {
            cout << "Stack Underflow\n";
            return;
        }

        cout << q.front() << " popped\n";
        q.pop();
    }

    // Top element
    int top() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q.front();
    }

    // Check if empty
    bool isEmpty() {
        return q.empty();
    }
};
