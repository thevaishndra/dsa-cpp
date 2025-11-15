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

//Q3. Detect a loop or a cycle in a linked list
//Brute
bool detectLoop(Node* head) {//return type is bool
    unordered_map<Node*, int> mpp; //not in order, priority is speed
    Node* temp = head;

    while(temp != nullptr) {
        //it basically means find temp in whole map
        //mpp.end() means key not found, so mpp.find != key not found -> it means we found the key
        if(mpp.find(temp) != mpp.end()) return true;//loop found

        mpp[temp] = 1;
        temp = temp->next;
    }
    return false;
}
//tc -> O(n * logn) traverse once and map operations takes logn //sc -> O(n)

//Optimal :- tortoise and hare algo
bool detectLoop(Node* head) {
    int slow = head;
    int fast = head;

    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) return true;//It means that there is a loop -> no point where fast == X or fast->next == X
    }
    return false;//it means that it's linear and there is no loop -> there will be at some point fast or fast->next == X
}
//tc -> O(n) //sc -> O(1)
