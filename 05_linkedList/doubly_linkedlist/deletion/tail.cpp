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

Node* deleteTail(Node* head) {
    if(head == nullptr || head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }

    Node*prev = tail->back;
    prev->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}