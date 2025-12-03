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

Node* deleteValue(Node* head, int ele){
    if(head == nullptr) return nullptr;

    if(head->data == ele){
        Node* temp = head;
        head = head->next;
        delete(temp);
        return head;
    }

    Node*temp = head;
    Node*prev = nullptr;

    while(temp != nullptr) {
        if(temp->data == ele){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}