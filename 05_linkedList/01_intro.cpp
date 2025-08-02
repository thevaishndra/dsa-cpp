#include <bits/stdc++.h>
using namespace std;

struct node { //we defined a structure node that contains
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
    
    cout << y->data << endl; //accessing data of node x using pointer y
}
