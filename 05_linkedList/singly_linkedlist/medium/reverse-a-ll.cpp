#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

   Node(int val, Node* next1 = nullptr){
        data = val;
        next = next1;
    }
};

//Q1. Reverse a linked list
//brute
Node* reversell(Node* head) {
    Node* temp = head;
    stack <int> st;
    while(temp != nullptr) {//traversal 1 :- put data in stack
        st.push(temp -> data)
        temp = temp->next;
    }

    Node* temp = head;
    while(temp != nullptr) {//traversal 2 :- change the data of nodes and remove the values in stack
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    } 
    return head;
}
//tc -> O(n) + O(n) = O(2n) //sc -> O(n)

//Optimal 1 :- Changing links -> Iterative
Node* reversell2(Node* head) {
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr) {
        Node* front = temp->next//front moves forward 
        temp->next = prev;//change links
        prev = temp;//prev move forwards
        temp = front;//temp moves forward // front and temp on same node
    }
    return prev;
}
//1->2->3->->X
//temp = head; prev is pointing to some nullptr
//front is at 2
//next of temp should be prev -> 1->X as prev was X/nullptr
//prev is at 1 as prev = temp
//temp is at 2 as temp = front
//tc -> O(n) //sc -> O(1)


//Optimal 2 :- Changing links Recursive
//problem statement -> smaller problem -> smaller problem -> best case
//                  <-                 <-                 <-
Node * reversell3(Node* head) {
    if (head == nullptr || head->next == nullptr) {//base case
        return head;
    }

    Node* newHead = reversell3(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}
//tc -> O(n) //sc -> O(n) recursive stack space

//linked list :- 1 -> 2 -> 3 -> 4 -> X
//first we are going down
//head = 1; head->next = 2 calling reversell3(2)
//head = 2; head->next = 3 calling reversell3(3)
//head = 3; head->next = 4 calling reversell3(4)
//head = 4; head->next = nullptr //base condition gets true as head->next = nullptr; so, we return 4

//now, going up
//head = 3, newHead = 4, front = 4 as head->next; then we change links and return newHead
//head = 2, newHead = 4, front = 3 as head->next; then we change the links and return newHead
//head = 1, newHead = 4, front = 2 as head->next; then we change the links and return newHead ie 4
//linked list :- X <- 1 <- 2 <- 3 <- 4 ; here 4 is head
