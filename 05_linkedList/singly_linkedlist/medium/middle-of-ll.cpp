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

//Q2. Find the middle of linked list
// 1->2->3->4->5->X ; here middle is 3 as it's easy to find in odd no
// 1->2->3->4->5->6->X ; problem in even, we will return the second node ie, 4
//middle -> (n/2 + 1)

//Brute
Node* middleOfll(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* temp = head;
    int cnt = 0;
    while(temp != nullptr) {//finding n to apply formula n/2 + 1, here n is no nodes
        cnt++;
        temp = temp->next;
    };

    int midNode = (cnt/2) + 1;
    temp = head;
    while(temp != nullptr) {//mid no of times temp need to come
        midNode = midNode - 1;
        if(midNode == 0) break;
        temp = temp->next;
    }
    //eg-> midNode = 3
    //in loop it becomes 3-1 = 2
    //!=0
    //temp moves forward
    //then again 2 - 1 = 1
    //!=0
    //temp moves forward
    //this time 1 - 1 = 0
    //== 0, break 
    return temp;//this is returned which is midNode
}
//tc -> O(n + n/2) //sc -> O(1)

//Optimal -> Tortoise and hare method
//slow -> it goes one step
//fast -> it goes two step 
Node* middleofll2(Node* head) {
    Node* slow = head;
    Node* fast = head;
    //in odd cases fast will go till last node ; fast->next = nullptr
    //in even cases fast will go till the nullptr ; fast == nullptr
    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;//one step
        fast = fast->next->next;// two step
    }
    return slow;//slow will be at the middle
}
//tc -> O(n/2) //sc -> O(1)