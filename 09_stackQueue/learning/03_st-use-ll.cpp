#include <bits/stdc++.h>
using namespace std;

//Q3. Implement queue using linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
    Node* topNode;  // Pointer to the top of stack

public:
    Stack() {
        topNode = nullptr;
    }

    // Push Operation
    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = topNode;  // Insert at top
        topNode = newNode;
        cout << x << " pushed to stack\n";
    }

    // Pop Operation
    void pop() {
        if (topNode == nullptr) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        cout << temp->data << " popped from stack\n";
        delete temp;
    }

    // Top Operation
    int top() {
        if (topNode == nullptr) {
            cout << "Stack is empty\n";
            return -1;
        }
        return topNode->data;
    }

    // Check if Empty
    bool isEmpty() {
        return topNode == nullptr;
    }
};
//tc -> O(1) //sc -> O(n) space grows linearly with no of nodes you store

