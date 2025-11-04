#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val, Node* next1){
        data = val;
        next1 = nullptr;
    }
}

int lengthOfLinkedList(Node* head) {
    int cnt = 0
    Node* temp = head;
    while (temp != nullptr) {
        cnt++; //increase the count at every node
        temp = temp->next; // move to the next node
    }
    return cnt;
}
//tc -> O(n)