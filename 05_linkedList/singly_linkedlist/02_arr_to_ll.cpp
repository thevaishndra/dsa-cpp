#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val, node* next) {
        data = val;
        next = nullptr;
    }
};

Node* arrayToLinkedList(vector<int>& arr) {
    if (arr.empty()) return nullptr;//if array is empty return null

    Node* head = new Node(arr[0]);//head pointer points to arr[0]
    Node* mover = head;//mover pointer points to head

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);//temp is pointer which is now pointing to arr[i]
        mover->next = temp;//next of mover is temp which links the prev node where mover is pointing to next node
        mover = temp;//now mover pointer is pointing to temp
    }
    return head;
}
