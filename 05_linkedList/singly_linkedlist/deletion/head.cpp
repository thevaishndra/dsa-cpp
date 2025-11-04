#include <bits/stdc++.h>
using namespace std;

struct Node {//definition of singly linkedlist
    int data;
    Node* next;

    Node(int val, Node* next1 = nullptr){
        data = val;
        next = next1;
    }
};

Node* deleteHead(Node* head){
    if(head == nullptr) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

int main(){
    //convert array to linkedlist
    head = deleteHead(head);
    //again traverse and cout the linkedlist
}