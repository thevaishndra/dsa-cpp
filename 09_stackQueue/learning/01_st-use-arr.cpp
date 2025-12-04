#include <bits/stdc++.h>
using namespace std;

//stack (LIFO) - Last In First Out {We do things with last}
//Push Operation - To push an element onto the stack; If the stack is full (top is equal to the last index of the array), throw a stack overflow exception.
//Pop Operation - To pop an element from the stack; If the stack is empty, throw a stack underflow exception
//Top Operation - To get the top element without removing it
//IsEmpty Operation - To check if the stack is empty
//isFull() → Checks if stack array is full
//Size Operation - To get the current size of the stack

//push(2); push(3); push(4); push(1); pop(); top() -> 4; top() -> 4; pop(); push(5); top() -> 5; size() -> 3;
//stack :- 2 3 4 5

//Q1. Implement stack using array
class stImpl {//class definition
    int topIndex = -1;//stores index of top element, -1 means stack is empty
    int st[10];//arr of size 10 is used 

    public://constructor is optional as I already have initialized topIndex to -1
    stImpl() {
        topIndex = -1;
    }

    //PUSH Operation
    void push(int x) {
        if (topIndex >= 9) { //check if stack is full; why 9? as array indexing starts with 0
            cout << "Stack Overflow" << endl;//then adding more element will lead to overflow
            return;
        }
        topIndex++;//move pointer
        st[topIndex] = x;//add element
    }

    //POP Operation
    int pop() {
        if (topIndex == -1) {//empty stack what more can I pop
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int value = st[topIndex];//storing the current value which we are going to pop
        topIndex--;//move pointer backwards as that will be the new top and previous top is popped
        return value;//returning popped value
    }

     // TOP operation
    int top() {
        if (topIndex == -1) {
            return -1; // empty stack
        }
        return st[topIndex];//current top element
    }

    // Check if empty
    bool isEmpty() {//check if stack is empty by using equality comparison operator ==
        return topIndex == -1;//stack is empty at index -1
    }//bool because returning true false

    //Check if full
    bool isFull() {//check if stack is full
        return topIndex == 9;//stack is full at index 9
    }//bool because returning true false

    // Size operation
    int getSize() {
    return topIndex + 1;//return size
}
};
//tc -> O(1) //sc -> O(n) -> Because the stack stores elements in an array of maximum size N