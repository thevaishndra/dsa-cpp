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

Node* insertBeforeNode(Node* head) {
    Node* prev = node->back;
    Node* newNode = newNode(val, node, prev);
    prev->next = newNode;
    node->back = newNode;
}