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

Node* insertHead(Node* head) {
    Node* newHead = new Node(val, head, nullptr);
    head->back = new head;
    return newHead;
}