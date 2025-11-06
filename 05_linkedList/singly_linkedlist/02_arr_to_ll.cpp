#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val, Node* next1 = nullptr){
        data = val;
        next = next1;
    }
};

Node* arrayToLinkedList(vector<int>& arr) {
    if (arr.empty()) return nullptr;//if array is empty return null

    Node* head = new Node(arr[0]);//head pointer points to arr[0]
    Node* mover = head;//mover pointer points to head

    for (int i = 1; i < arr.size(); i++) {//traversal starting from arr[1]
        Node* temp = new Node(arr[i]);//temp pointer points to arr[1]
        mover->next = temp;//next of mover is temp which links the mover node to temp node
        mover = temp;//now mover pointer is pointing to temp
    }
    return head;
}
//whenever we create new Node the next is nullptr, in this when we link the nodes, nullptr automatically gets removed

//tc -> O(n)

