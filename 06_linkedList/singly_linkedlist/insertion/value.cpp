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

Node* insertVal(Node* head, int ele, int x){
    if(head == nullptr) return nullptr;
    if(head->data == val){
        return new Node(ele, head);
    }

    Node* temp = head;
    while(temp->next != nullptr){
        if(temp->next->data == val) {
            Node* x = new Node(el, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next
    }
    return head;
}