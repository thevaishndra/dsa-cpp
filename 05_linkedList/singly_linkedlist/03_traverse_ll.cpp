#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val, Node* next1 = nullptr){
        data = val;
        next = next1;
    }
};

void traversalInLinkedList(Node* head) {
    Node* temp = head; //pointer temp is pointing to head
    while (temp != nullptr) {//until node not points to nullptr
        cout << temp->data << " -> ";//print data and arrow
        temp = temp->next;//temp is now pointing at the next of temp
    }
    cout << "NULL" << endl;
}

//tc -> O(n)