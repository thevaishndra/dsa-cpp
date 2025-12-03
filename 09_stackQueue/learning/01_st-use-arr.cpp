#include <bits/stdc++.h>
using namespace std;

//stack (LIFO) - Last In First Out {We do things with last}
//Push Operation - To push an element onto the stack; If the stack is full (top is equal to the last index of the array), throw a stack overflow exception.
//Pop Operation - To pop an element from the stack; If the stack is empty, throw a stack underflow exception
//Top Operation - To get the top element without removing it
//IsEmpty Operation - To check if the stack is empty
//Size Operation - To get the current size of the stack
//isFull() → Checks if stack array is full

//push(2); push(3); push(4); push(1); pop(); top() -> 4; top() -> 4; pop(); push(5); top() -> 5; size() -> 3;
//stack :- 2 3 4 5

//Q1. Implement stack using array
class stImpl {
    int topIndex = -1;
    int st[10];

    public:
    stImpl() {
        topIndex = -1;
    }

    //PUSH Operation
    void push(nt x) {
        if (topIndex >= 9) { // last index = 9 (size 10)
            cout << "Stack Overflow" << endl;
            return;
        }
        topIndex++;
        st[topIndex] = x;
    }

    //POP Operation
    int pop() {
        if (topIndex == -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int value = st[topIndex];
        topIndex--;
        return value;
    }

     // TOP operation
    int top() {
        if (topIndex == -1) {
            return -1; // empty stack
        }
        return st[topIndex];
    }

    // Check if empty
    bool isEmpty() {
        return topIndex == -1;
    }
};
//tc -> O(1) //sc -> O(n) -> Because the stack stores elements in an array of maximum size N