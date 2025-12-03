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

//Q.5 Find the length of loop in linked list 
//Brute :- no of all node - the nth node at which loops starts
int lengthOfLoop(Node* head) {
    Node* temp = head;
    int timer = 1;
    unordered_map<Node*, int> mpp;

    while(temp != nullptr) {
        if(mpp.find(temp) != mpp.end()){//if temp is inside the map
            int value = mpp[temp];//it means loop is found and the starting point of the loop is value node
            return (timer - value);//timer is no of all nodes we gotwhile traversing - value node  
        }//basically if no of nodes are 10 and loop starts at node 3rd -> so, length of loop is 10 - 3 = 7

        mpp[temp] = timer;//marking all the nodes as timer
        timer++;//moving timer forward
        temp = temp->next;//going forward
    }
    return 0;//that's why func is not Node* as it returns 0
}
//tc -> O(n) //sc -> O(n)

bool lengthOfLoop2(Node* head) {
    int slow =  head;
    int fast= head;

    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        //finding if there exists a loop if yes then another func to find the length
        if(slow == fast) {
            return findLength(slow, fast);//tortoise and hare algo
        }//fast and slow is at same point
    }
    return false;//boolean as return value
}

Node* findLength(slow, fast) {
    int cnt = 1;

    while(slow != fast) {//it's a loop so slow is at one point anf fast is going forward and at one point it will come again to slow
        cnt++;//till then we are counting
        fast = fast->next;
    }
    return cnt;//length of loop
}
//tc -> O(n) //sc -> O(n)
