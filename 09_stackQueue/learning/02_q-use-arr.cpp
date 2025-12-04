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
//isFull() → Checks if the queue is full (for array)
//Size Operation - To get the current size of the queue

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
    qImpl() {//need to write constructor as otherwise it will have garbage values
        size = 10;
        currSize = 0;
        start = -1;
        end = -1;
    }

    // Enqueue -> push
    void enqueue(int x) {//void as no need to return anything
        if (currSize == size) {//queue is full as its currSize has reached maximum size
            cout << "Queue Overflow" << endl;
            return;
        }

        // First insertion
        if (currSize == 0) {//queue is empty
            start = 0;
            end = 0;
            q[end] = x;//enqueue value at the index of end
        }
        else {
            end = (end + 1) % size;//circular increment -> allows queue to wrap around array
            q[end] = x;//enqueue value
        }
        currSize++;//currSize incremented
    }

    // Dequeue -> pop
    int dequeue() {
        if (currSize == 0) {//if queue is empty
            cout << "Queue Underflow" << endl;
            return -1;
        }

        int ele = q[start];//storing front element to return later

        if (currSize == 1) {//if only one element is present 
            start = -1;
            end = -1;
        }//queue becomes empty
        else {
            start = (start + 1) % size;//circular increment of start index
        }

        currSize--;//decrease currSize
        return ele;//dequeued element
    }

    // Front element
    int front() {
        if (currSize == 0) {
            return -1;//means queue is empty
        }
        return q[start];
    }

    // Check if empty
    bool isEmpty() {
        return currSize == 0;
    }

    //Check if full
    bool isFull() {
        return currSize == size;
    }

    // Get size
    int getSize() {
        return currSize;
    }
};
//tc -> O(1) //sc -> O(n)
