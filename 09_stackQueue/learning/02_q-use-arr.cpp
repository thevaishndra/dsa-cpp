#include <bits/stdc++.h>
using namespace std;

//queue (FIFO) - First In First Out {We do things with first}
//Same operations as stack
//Front → Index of the first element
//Rear → Index of the last element
//Enqueue() → Insert an element at the rear / push
//Dequeue() → Remove an element from the front / pop 
//Front() → Returns the first element / top
//isEmpty() → Checks if the queue is empty
//Size Operation - To get the current size of the queue
//isFull() → Checks if the queue is full (for array)


//push(2); push(1); push(3); push(4); pop(); top() -> 1; pop(); top() -> 3; push(7); top() -> 3; size() -> 3
//queue -> 3 4 7

//Q2. Implement queue using array
class qImpl {
    int size;
    int q[10];
    int currSize;
    int start;
    int end;

public:
    qImpl() {
        size = 10;
        currSize = 0;
        start = -1;
        end = -1;
    }

    // Enqueue
    void enqueue(int x) {
        if (currSize == size) {
            cout << "Queue Overflow" << endl;
            return;
        }

        // First insertion
        if (currSize == 0) {
            start = 0;
            end = 0;
            q[end] = x;
        }
        else {
            end = (end + 1) % size;
            q[end] = x;
        }

        currSize++;
    }

    // Dequeue
    int dequeue() {
        if (currSize == 0) {
            cout << "Queue Underflow" << endl;
            return -1;
        }

        int ele = q[start];

        if (currSize == 1) {
            start = -1;
            end = -1;
        }
        else {
            start = (start + 1) % size;
        }

        currSize--;
        return ele;
    }

    // Front element
    int front() {
        if (currSize == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return q[start];
    }

    // Get size
    int getSize() {
        return currSize;
    }
};
//tc -> O(1) //sc -> O(n)
