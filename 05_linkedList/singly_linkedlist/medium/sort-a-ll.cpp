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