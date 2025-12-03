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

Node* deleteNode(Node* head, int k) {
    Node* temp = head
    Node* prev = temp->back;
    Node* front = temp->next;

    if(front == nullptr) {
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return head;
    }

    else {
        prev->next = front;
        front->back= prev;
        temp->next = temp->back = nullptr;
        delete temp;
    }
    return head;
}