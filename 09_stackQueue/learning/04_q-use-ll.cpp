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
        front = nullptr;//first element of queue
        rear = nullptr;//last element of queue
    }

    // Enqueue (Insert at rear)
    void enqueue(int x) {
        Node* newNode = new Node(x);//create a new node

        if (rear == nullptr) {  // Queue is empty
            front = rear = newNode; // both front and rear point to the new node
            cout << x << " enqueued\n";
            return;
        }

        //if queue is not empty
        rear->next = newNode; //next of rear is new node
        rear = newNode;//update rear to new node
        cout << x << " enqueued\n";
    }

    // Dequeue (Remove from front)
    void dequeue() {
        if (front == nullptr) {//if queue is empty it's case of underflow
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = front;//temp stores the front node which is going to be dequeued
        front = front->next;//move the front forward

        // If queue becomes empty after deleting then rear should also be nullptr
        if (front == nullptr)
            rear = nullptr;

        cout << temp->data << " dequeued\n";//the data of dequeued node
        delete temp;//free memory
    }

    // Get front element
    int getFront() {
        if (front == nullptr) {//if queue is empty front is nullptr
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;//if not then return data
    }

    // Check if empty
    bool isEmpty() {
        return front == nullptr;//if front is nullptr then queue is empty
    }
};
//tc -> O(1) //sc -> O(n)
