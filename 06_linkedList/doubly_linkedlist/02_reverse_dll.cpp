#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* back;

    Node(int val, Node* next1 = nullptr, Node* back1 = nullptr){
        data = val;
        next = next1;
        back = back1;
    }
};

//Q1. Reverse a doubly linked list
//Brute -> changing the values
Node* reverseDll(Node* head) {
    if(head == nullptr || head->next == nullptr) return head;//cheeck if list is not empty or it contains just the head

    Node* temp = head; //temp pointer points to head
    stack <int> st;//create a stack st

    while(temp != nullptr) {//traversal through the list
        st.push(temp->data);//add data into the stack
        temp = temp->data;//move temp to next node
    }

    temp = head;//again
    while(temp != nullptr) {//traverse again
        temp->data = st.top();//change the data to the value which is at the top of stack
        st.pop();//remove the value at the top of stack
        temp = temp->next;//temp moves to next
    }
    return head;
}
//tc -> O(2n) -> 2 traversals //sc -> O(n) -> using stack as extra space

//Optimal -> modifying liinks instead odf 2 traversals
Node* reverseDll2(Node* head) {
    if(head == nullptr || head->next == nullptr) return head;

    Node* prev = nullptr;
    Node* current = head;

    while(current != nullptr) {
        //swapping using third variable prev -> we want current->back = next; current->next = back
        prev = current->back;
        current->back = current->next;
        current->next = prev;

        //moving current to next node
        current = current->back;
    }
    return prev->back;//as its reversed so new head will be back of prev
}
//tc->O(n) //sc->O(1)
