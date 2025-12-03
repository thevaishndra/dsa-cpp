#include <bits/stdc++.h>
using namespace std;

//SINGLY LINKED LIST
struct Node { //we defined a structure / class node that contains
    int data; //data -> integer
    Node* next; //next -> pointer to the next node in the linked list

    //constructor -> special func inside class/struct that runs automatically when an object is created
    Node(int val, Node* next1 = nullptr){//initialising a node, if not passed any next1 then it is assigned nullptr
        data = val;//data of this node is val
        next = next1;//next pointer of this node is next1
    }
};

int main () {
    Node x = Node(2, nullptr); //create node x , calls const node, passing data1 as 2 and next1 as nullptr (no next node)
    Node* y = &x; //y pointer points to x node
    
    cout << y->data << endl; //y pointer goes to the address of x and access data of node x
}// y -> x -> nullptr / X
//2 -> X

//linear data structure
//starting node is head and ending node is tail
//It is used in stack / queue in the browser
//1D linked list just k ows the next location
//It is not in contiguous locations whereas arrays are stored in contiguous locations
//Size can be increased by adding and decreased by removing


//for multiple nodes in a linked list
struct Node {
    int data;
    Node* next;

   Node(int val, Node* next1 = nullptr){
        data = val;
        next = next1;
    }
};

int main () {
    Node* head = new Node(10, second);//value in head and next pointer
    Node* second = new Node(20, third);
    Node* third = new Node(30, nullptr);//next pointer is nullptr here

    Node* temp = head; //temporary pointer points to head
    while(temp != nullptr){//if linkedlist is not empty
        cout<<temp->data<<" -> ";//print data of head
        temp = temp->next;// then make temp points to next
    }
    cout<<"NULL";
}//temp -> head -> second -> third -> nullptr/X
//10 -> 20 -> 30 -> X