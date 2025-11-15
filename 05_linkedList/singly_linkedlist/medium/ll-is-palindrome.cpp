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

//Q.6 Check if the linked list is a palindrome or not
//Brute
bool llisPalindrome(Node* head) {
    stack<int> st;
    Node* temp = head;

    while(temp != nullptr) {//put all the nodes in stack
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;//again temp is head
    while(temp != nullptr) {
        //now, we are trying to check if the nodes matches the reverse or not
        if(temp->data != st.top()) return false;//if even first one doesn't match, it's not a palindrome
        temp = temp->next;
        st.pop();//we are popping as we need next node to be at the top
    }
    return true;
}
//tc -> O(2n) //sc -> O(n)

//Optimal
bool llisPalindrome2(Node* head) {
    //tortoise and hare algo
    int slow = head;
    int fast = head;

    while(fast->next != nullptr && fast->next->next != nullptr) {//in odd cases fast is at second last and in even at last
        slow = slow->next;
        fast = fast->next->next;
    }

    //slow is at the mid of linked list
    Node* newHead = reverse(slow->next);//from slow->next to the end we need to reverse the second half
    Node* first = head;//head of first half
    Node* second = newHead;//head of newly reversed ll
    
    while(second != nullptr) {//now wea re matching the first hhalf nodes to second half
        if(first->data != second->data) {//if it's not equal, but obvio ll is not a palindrome
            reverse(newHead);//we have tampered data so after getting my ans i need to make it as it was originally
            return false;
        }

        //if it's matching then move forward
        first = first->next;
        second = second->next;
    }
    //calling reverse func again
    reverse(newHead);//if we got our ans as true then also we need to untampered the linked list
    return true;
}

//from the previous codes -> reverse a ll
Node* reverse(Node* head) {
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr) {
        Node* front = temp->next//front moves forward 
        temp->next = prev;//change links
        prev = temp;//prev move forwards
        temp = front;//temp moves forward // front and temp on same node
    }
    return prev;
}
//tc ->O(n/2 + n/2 + n/2 + n/2) => O(2n) //sc -> O(1)