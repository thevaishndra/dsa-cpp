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

//Q.12 Sort a linked list of 0s, 1s, 2s
//Brute
Node* sortLLOf0s1s2s(Node* head) {
    Node* temp = head; 
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;

    while(temp != nullptr) {//counting the values of 0, 1, 2
        if(temp->data == 0) cnt0++;
        else if(temp->data == 1) cnt1++;
        else cnt2++;
        temp = temp->next;
    }

    temp = head;
    while(temp != nullptr) {
        if(cnt0 > 0) {//changing values as 0 till the cnt0 becomes 0
            temp->data = 0;
            cnt0--;
        }
        else if(cnt1 > 0) {//changing values as 1 till the cnt1 becomes 0
            temp->data = 1;
            cnt1--;
        }
        else {//changing values as 2 whatever that is left in linkedlist till that
            temp->data = 2;
            cnt2--;
        }
        temp = temp->next;
    }
    return head;
}
//tc -> O(2n) //sc -> O(1)

//optimal :- not a new node but pointing to the nodes existing
Node* sortALLOf0s1s2s(Node* head) {
    if(head == nullptr || head->next == nullptr) return head;

    //creating dummy heads
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);

    Node* zero  = zeroHead;
    Node* one = oneHead;
    Node* two  = twoHead;

    temp = head;
    //seggregating the nodes into list of 0s, 1s, 2s acc to the data
    while(temp != nullptr) {
        if(temp->data == 0) {
            zero->next = temp;//linking zero dummy to nodes of 0
            zero = temp;
        }

        else if(temp->data == 1) {//linking one dummy to nodes of 1
            one->next = temp;
            one = temp;
        }

        else {//linking two dummy to nodes of 2
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }

    //connect the 3 lists
    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;//if 1s list contains any node then connect 0s to 1s otherwise 0s directly to 2s
    one->next = twoHead->next;
    two->next = nullptr;

    Node* newHead = zeroHead->next;

    // Delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;
}
//tc -> O(n) //sc -> O(1)


