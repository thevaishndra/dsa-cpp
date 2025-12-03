#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
    Node* front;  // front of queue
    Node* rear;   // rear of queue

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue (Insert at rear)
    void enqueue(int x) {
        Node* newNode = new Node(x);

        if (rear == nullptr) {  // Queue empty
            front = rear = newNode;
            cout << x << " enqueued\n";
            return;
        }

        rear->next = newNode;
        rear = newNode;
        cout << x << " enqueued\n";
    }

    // Dequeue (Remove from front)
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        // If queue becomes empty
        if (front == nullptr)
            rear = nullptr;

        cout << temp->data << " dequeued\n";
        delete temp;
    }

    // Get front element
    int peek() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    // Check if empty
    bool isEmpty() {
        return front == nullptr;
    }
};
//tc -> O(1) //sc -> O(n)
