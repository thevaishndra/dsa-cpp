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

//Q.7 Seggregate odd & even nodes in a linked list
//brute
Node* segOddAndEven(Node* head) {
    if(head == nullptr || head->next == nullptr) return head;

    vector<int> arr;
    Node* temp = head;

    //store data of odd positioned nodes
    while(temp != nullptr && temp->next != nullptr) {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }

    //start from head->next, store data of even positioned nodes
    temp = head->next;
    while(temp != nullptr && temp->next != nullptr) {
        arr.push_back(temp->data);
        if (temp->next == nullptr) break;
        temp = temp->next->next;
    }

    //data replacement from arr to ll
    int i = 0; 
    temp = head;
    while(temp != nullptr) {
        temp->data = arr[i];
        i++;
        temp = temp->next;
    } 
    return head;
}
//tc -> O(n/2 + n/2 + n) => O(2n) //sc -> O(n)

//optimal
Node* segOddAndEven2(Node* head) {
    if(head == nullptr || head->next == nullptr) return head;//if list is empty

    Node* odd = head;//first node is odd
    Node* even = head->next;//second node is even
    Node* evenHead = head->next;//and that is even head

    while(even != nullptr && even->next != nullptr) {
        odd->next = odd->next->next;//we are linking odd nodes
        even->next = even->next->next;//we are linking even nodes
        odd = odd->next;//we move forward odd to recently linked node
        even = even->next;//we move forward even to recently linked node
    }

    odd->next = evenHead;//last node of odd list is linked to even head
    return head;//now both odd list and even list gets connected
}
//first of all list can be any order coz we are seggregating on the basis of odd nodes and even nodes not values
//tc -> O(n/2 + n/2) => O(n) //sc -> O(1)