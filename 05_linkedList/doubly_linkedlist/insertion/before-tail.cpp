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

Node* insertBeforeTail(Node* head){
    Node* newTail = head;
    while(tail->next != nullptr){
        tail = tail->next;
        prev = tail->back;
        new Node = new Node(10, tail, prev);
        prev->next = new Node;
        tail->back = newNode;
    }
    return head;
}