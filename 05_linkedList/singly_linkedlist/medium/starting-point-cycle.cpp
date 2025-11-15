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

//Q.4 Find the starting point of cycle in linked list 
Node* startingPointCycle(Node* head) {
    Node* temp = head;
    unordered_map<Node*, int>mpp;

    while(temp != nullptr) {
        //mpp.end() means key not found so if mpp.find(temp) != key not found it means key is found
        if(mpp.find(temp) != mpp.end()) return temp;//It means find the value of temp in map

        mpp[temp] = 1;//mark current node as visited
        temp = temp->next;//moves forward
    }
    return nullptr;//no cycle found
}
//tc -> O(n) //sc -> O(n) -> n is no. of nodes stored in map

//Optimal
Node* startingPointCycle(Node* head) {
    int slow = head;
    int fast = head;

    while(fast != nullptr && fast->next != nullptr) {//1. first we will detect a loop
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {//loop detected
            //2. find the starting point
            slow == head;//either slow or fast any one is at head and other one is in the last node where it was earlier
            while(slow != fast) {
                slow = slow->next;//from head to one - one step further
                fast = fast->next;//from last node to one one step further 
            }
            return slow;//colliding point after taking one one step
            //this colliding point is actually the starting point of the cycle
        }
    }
    return nullptr;
}
//tc -> O(n) //sc -> O(n)