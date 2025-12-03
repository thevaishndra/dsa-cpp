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

Node* insertK(Node* head, int ele, int k){
    if(head == nullptr){
        if(k == 1) return new Node(ele);
        else return nullptr;
    }
    if(k == 1) {
        Node* temp = new Node(ele, head);
        return temp;
    }

    int cnt = 0; Node* temp = head;
    while(temp != nullptr) {
        cnt++;
        if(cnt == k - 1){
            Node* n = new Node(ele);
            n->next = temp->next;
            temp->next = n;
            break;
        }
        temp = temp->next;
    }
    return head;
}