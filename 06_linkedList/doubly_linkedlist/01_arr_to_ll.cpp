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

Node* arrToLinkedList(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i <= arr.size() - 1; i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}