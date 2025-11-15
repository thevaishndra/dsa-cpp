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

//Q.10 Sort a linked list
//brute
Node* sortAll(Node* head) {
    vector<int> arr;
    Node* temp = head;
    while(temp != nullptr) {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    sort(arr.begin(), arr.end());

    int i = 0; 
    temp = head;
    for (int i = 0; i < arr.size(); i++) {
        temp->data = arr[i];
        temp = temp->next;
    }

    return head;
}
//tc -> O(n + nlogn + n) //sc -> O(n)

///////can't understand
//optimal
Node* sortAll2(Node* head) { 
    if(head == nullptr || head->next == nullptr) return head;

    // find mid
    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* mid = slow->next;
    slow->next = nullptr;

    Node* leftHead = head;
    Node* rightHead = middle->next;

    leftHead = ms(leftHead);
    rightHead = ms(rightHead);

    return merge2(leftHead, rightHead);
}
//tc -> O(logn)