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

Node* deleteTail(Node* head) {
    if(head == NULL || head->next == NULL) {
        delete head;
        return NULL;
    }

    Node* temp = head;
    //traverse to second last node
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    delete the last node
    delete temp->next;
    temp->next = nullptr;

    return head;
}

int main() {
    //convert arr to linkedlist
    head = deleteTail(head);
    //again traverse and cout linkedlist
}