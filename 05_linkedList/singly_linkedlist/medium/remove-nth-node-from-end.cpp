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

//Q.8 Remove nth node from the end of linked list
//brute
Node* removeNthNodeFromEnd(Node* head, int n) {
    if (head == nullptr) {// If list is empty, return NULL
        return nullptr;
    }

    int cnt = 0;
    Node* temp = head;

    while(temp != nullptr) {//count no of nodes in ll
        cnt++;
        temp = temp->next;
    }

    if(cnt == n) {//if the cnt == n means we have to delete head
        Node* newHead = head->next;//change the head
        delete head;//delete n
        return newHead;
    }

    int res = cnt - n;
    temp = head;
    while(temp != nullptr) {
        res--;//in this way, we will go till, one node before that node
        if(res == 0) break;//it means we are at one node before the node to be deleted
        temp = temp->next;
    }

    //deleting the target node
    Node* deleteNode = temp->next;//as we are one node before so next node is to be deleted
    temp->next = temp->next->next;//we are linking the prev and next node, leaving deleteNode
    delete deleteNode;//node is deleted
    return head;
}
//tc -> O(l) + O(l - n) //sc -> O(1)


///////can't understand
//optimal
Node* deleteNthNodeFromEnd2(Node* head, int n) {
    // Dummy node before head
    //No need to separately handle deleting the head
    Node* dummy = new Node(0, head);

    Node* slow = dummy;
    Node* fast = dummy;

    //creates a gap of n nodes between fast and slow
    for (int i = 0; i <= n; i++) {
        if (fast == nullptr) {
            // N > length, invalid deletion → return original head
            Node* result = dummy->next;
            delete dummy;
            return result;
        }
        fast = fast->next;
    }

    // Move both pointers
    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    // Delete the target node
    Node* deleteNode = slow->next;
    slow->next = slow->next->next;
    delete deleteNode;

    // Store updated head
    Node* newHead = dummy->next;

    // Delete dummy node
    delete dummy;

    return newHead;
}
