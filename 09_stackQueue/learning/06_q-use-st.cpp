#include <bits/stdc++.h>
using namespace std;

//method 1 :- enqueue is costly
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
    //push(4)
    //s1 is empty
    //s1: 4
    //s2 is empty
    //push(2)
    //s1 is not empty so, move top of s1 to s2, s1: empty, s2:4
    //s1: 2
    //s2 is not empty so, move top of s2 to s1, s1:2 4, s2: empty
    //push(3)
    //s1 is not empty so, move top of s1 to s2, s1: empty, s2:4 2
    //s1: 3
    //s2 is not empty so, move top of s2 to s1, s1:3 2 4, s2: empty

    // Dequeue Operation
    void dequeue() {
        if (s1.empty()) {//if queue is empty case of underflow
            cout << "Queue Underflow\n";
            return;
        }
        cout << s1.top() << " dequeued\n";//element that needs to be popped
        s1.pop();
    }

    // Get front
    int front() {
        if (s1.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return s1.top();//to get the front element , which is at the top of s1
    }

    bool isEmpty() {//check if the stack is empty
        return s1.empty();
    }
};
//tc -> O(n) for enqueue and O(1) for dequeue //sc -> O(n)


//method 2
class Queue {
    stack<int> s1, s2;

public:
    // Enqueue Operation: O(1)
    void enqueue(int x) {
        s1.push(x);//no shifting, no reversing, just push into s1
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
            while (!s1.empty()) {//when s1 is not empty
                s2.push(s1.top());//push top of s1 to s2
                s1.pop();//pop s1
            }
        }

        cout << s2.top() << " dequeued\n";//element that needs to be popped
        s2.pop();
    }

    // Get Front element
    int front() {
        if (s1.empty() && s2.empty()) {//if both stacks are empty then queue is empty
            cout << "Queue is empty\n";
            return -1;
        }

        // Move only when s2 is empty
        if (s2.empty()) {//s2 is empty
            while (!s1.empty()) {//s1 is not empty
                s2.push(s1.top());//push top of s1 to s2
                s1.pop();//pop s1
            }
        }
        return s2.top();//otherwise return top of s2
    }

    // Check empty
    bool isEmpty() {
        return (s1.empty() && s2.empty());
    }
};
//tc -> O(1) for enqueue O(n) for dequeue -> when shifting happens //sc -> O(n)