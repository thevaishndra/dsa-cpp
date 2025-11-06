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

Node* deleteKthEle(Node* head, int k){
    Node* temp = head;
    int cnt = 0;

    while(temp != nullptr){
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }

    Node* prev = temp->back;
    Node* front = temp->next;

    if(prev == nullptr && front == nullptr){
        delete temp;
        return nullptr;
    }

    else if(prev == nullptr) {
        deleteHead(head);
        return head;
    }

    else if(front == null){
        deleteTail(head);
        return head;
    }
    
    else {
        prev->next = front;
        front->back = prev;
        temp->next = nullptr;
        temp->back = nullptr;
        delete(temp);
    }
    
    return head;
}