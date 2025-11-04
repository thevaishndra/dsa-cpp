#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val, Node* next1 = nullptr){
        data = val;
        next = next1;
    }
}

int searchInll(Node* head, int key){
    Node* temp = head;
    while(temp != nullptr) {
        if(temp->data == key) return 1; //if the node pointed by temp = key, key is found
        temp = temp->next//else move temp to next
    }
    return 0;//if the key is not found after traversal
}