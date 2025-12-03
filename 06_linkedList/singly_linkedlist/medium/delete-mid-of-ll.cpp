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

//Q.9 Delete middle node of linked list
//brute
Node* deleteMidNode(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* temp = head;
    int n = 0;
    while(temp != nullptr) {//counting all the nodes
        n++;
        temp = temp->next;
    }

    int res = n/2;//finding the half -> it will give one node before to be deleted
    temp = head;
    while(temp != nullptr) {
        res--;//taking temp to one node before
        if(res == 0) {
            middle = temp->next;//mid is ofc next of temp
            temp->next = temp->next->next;//linking that to next node and leaving mid in between
            delete middle;
            break;
        }
        temp = temp->next;
    }
    return head;
}
//tc -> O(n + n/2) //sc -> O(1)

//optimal :- tortoise and hare method
Node* deleteMidNode2(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return nullptr; // delete single node

    Node* slow = head;
    Node* fast = head;
    Node* prev = nullptr;

    while (fast != nullptr && fast->next != nullptr) {
        prev = slow;//one step behind slow
        slow = slow->next;//goes one one step forward
        fast = fast->next->next;//goes 2 steps forward
    }

    prev->next = slow->next;//linking prev node to next of slow node
    delete slow;//slow is middle node

    return head;
}
//tc -> O(n/2) //sc -> O(1)