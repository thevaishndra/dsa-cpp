#include <bits/stdc++.h>
using namespace std;

//method 1 :- costly push using 2 queue
class Stack {
    //q1 → main queue (always stores elements in stack order)
    //q2 → temporary queue (used while pushing)
    queue<int> q1, q2;

public:
    // Push operation
    void push(int x) {
        q2.push(x);//add new element to q2

        // Move all elements of q1 → q2 if it's not empty
        //This reverses the order so that newest element is at front of q1
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap names (q1 has newest at front)
        //and rest of elements behind it in stack order and q2 is empty for next push
        swap(q1, q2);

        cout << x << " pushed\n";
    }
    //push(10) -> q2: 10
    //q1 is empty so no move
    //swap q1 and q2
    //q1: 10, q2: empty
    //push(20) -> q2: 20
    //q1 is not empty, move 10 from q1 to q2
    //q2: 20,10; q1: empty
    //swap q1 and q2
    //q1: 20,10; q2: empty

    // Pop operation
    void pop() {
        if (q1.empty()) {//if q1 is empty, stack underflow
            cout << "Stack Underflow\n";
            return;
        }
        cout << q1.front() << " popped\n";
        q1.pop();//pop front of q1 which is top of stack as queue has pop function
    }

    // Top element
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q1.front();//front of q1 is the top of stack
    }

    // Check empty
    bool isEmpty() {
        return q1.empty();//return true if q1 is empty
    }
};
//tc -> push: O(n), pop: O(1), top: O(1) //sc -> O(n)


//method 2:- costly push using single queue
//To implement a stack using only one queue, we use a trick:
//Whenever we push a new element, rotate the queue so that the new element comes to the front.
//This makes the queue behave like a stack.
class Stack {
    queue<int> q;

public:
    // Push Operation
    void push(int x) {
        q.push(x);
        int size = q.size();

        // Rotate all elements except the new one
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());//eg q -> 10, 20 ,so we again push 10 -> 10, 20, 10
            q.pop();//then pop front 10 -> 20, 10
        }//so basically it got reversed and we have to do reverse size-1 times coz that much elements we have

        cout << x << " pushed\n";
    }
    //push(10) -> q: 10
    //size = 1
    //0 < 1 - 1 = 0 (no rotation)
    //q: 10
    //push(20) -> q: 10, 20
    //size = 2
    //0 < 2 - 1 = 1 (one rotation)
    //q: 10, 20, 10 (push front at back)
    //q: 20, 10 (pop front)
    //it got reversed to have newest element at front

    // Pop Operation
    void pop() {
        if (q.empty()) {//if queue is empty, stack underflow
            cout << "Stack Underflow\n";
            return;
        }

        cout << q.front() << " popped\n";
        q.pop();//the newest element is at front due to rotation during push, we just pop that
    }

    // Top element
    int top() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q.front();//front of queue is top of stack
    }

    // Check if empty
    bool isEmpty() {
        return q.empty();//return true if queue is empty
    }
};
//tc -> push: O(n), pop: O(1), top: O(1) //sc -> O(n)
