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

Node* insertHead(Node* head, int val){
    Node* temp = new Node(head, val);
    return temp;
}

int main() {
    head = insertHead(head, val);
}