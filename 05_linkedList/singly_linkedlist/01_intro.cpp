#include <bits/stdc++.h>
using namespace std;

struct node { //we defined a structure / class node that contains
    int data; //data -> integer
    node* next; //next -> pointer to the next node in the linked list

    //constructor -> special func inside class/struct that runs automatically when an object is created
    node(int data1, node* next1){//initialising a node
        data = data1;//data of this node is data1
        next = next1;//next pointer of this node is next1
    }
};

int main () {
    node x = node(2, nullptr); //create node x , calls const node, passing data1 as 2 and next1 as nullptr (no next node)
    node* y = &x; //y pointer points to x node
    
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
struct node {
    int data;
    node* next;

    node(int data1, node* next1){
        data = data1;
        next = next1;
    }
};

int main () {
    node* head = new node(10, second);
    node* second = new node(20, third);
    node* third = new node(30, nullptr);

    node* temp = head; //temporary pointer points to head
    while(temp != nullptr){//if linkedlist is not empty
        cout<<temp->data<<" -> ";//print data of head
        temp = temp->next;// then make temp points to next
    }
    cout<<"NULL";
}//temp -> head -> second -> third -> nullptr/X
//10 -> 20 -> 30 -> X