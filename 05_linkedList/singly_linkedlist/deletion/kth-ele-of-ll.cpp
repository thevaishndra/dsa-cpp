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

Node* deleteKthElement(Node* head, int k){
    //if linkedlist is empty
    if(head == nullptr) return nullptr;

    //delete first node
    if(k == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int cnt = 0;
    Node* temp = head;
    Node* prev = nullptr;

    while(temp != nullptr) {
        cnt++;
        if(cnt == k) {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}