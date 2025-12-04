#include <bits/stdc++.h>
using namespace std;

//Q3. Implement queue using linked list
class Node {//linked list definition
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {//stack class using linked list
    Node* topNode;  // Pointer to the top of stack
    int currSize;

public:// Constructor
    Stack() {
        topNode = nullptr;
        currSize = 0;
    }

    // Push Operation
    void push(int x) {
        Node* newNode = new Node(x);// Create a new node
        newNode->next = topNode;  // next of new node points to current top
        topNode = newNode;// Update top to new node
        cout << x;
        currSize++;
    }

    // Pop Operation
    void pop() {
        if (topNode == nullptr) {//stack is empty
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = topNode;//tempporary to store top node so we can delete it later
        topNode = topNode->next;//top node is updated to the last node
        cout << temp->data;
        delete temp;
        currSize--;
    }

    // Top Operation
    int top() {
        if (topNode == nullptr) {
            return -1;
        }
        return topNode->data;
    }

    // Check if Empty
    bool isEmpty() {
        return topNode == nullptr;
    }

    // Get Size
    int size() {
        return currSize;//we maintain currSize variable to keep track of size
    }

//In a linked list, nodes are allocated dynamically from the heap.
//The stack/queue can grow until the system memory is exhausted.
//There is no fixed capacity, so you cannot know in advance if it is “full” like an array.
};
//tc -> O(1) //sc -> O(n) space grows linearly with no of nodes you store

