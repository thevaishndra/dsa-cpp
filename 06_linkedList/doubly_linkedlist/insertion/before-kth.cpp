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


Node* insertBeforeKthEle(Node* head) {
    Node* temp = head; int cnt = 0;
    while(temp != nullptr) {
        cnt = cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }

    Node* prev = temp->back;
    Node* newNode = newNode(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head; 
}