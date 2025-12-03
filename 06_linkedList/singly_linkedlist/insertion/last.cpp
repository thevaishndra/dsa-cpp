#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next

    Node(int val, Node* next1 = nullptr){
        data = val;
        next = next1;
    }
};

Node* insertLast(Node* head, int val){
    if(head == nullptr) {
        return new Node(val);
    }

    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }

    Node* new Node = new Node(val);
    temp->next = new Node;
    return head;
}