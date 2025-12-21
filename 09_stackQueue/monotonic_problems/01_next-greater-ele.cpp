#include <bits/stdc++.h>
using namespace std;

//A monotonic stack is a stack that always keeps its elements in a specific order — either increasing or decreasing.

//Q1. Find the next greater element for each element in an array
//Nge arr[i] = the first element to the right of arr[i] that is greater than it.
//If no such element exists, NGE = -1
//arr = [6, 0, 8, 1, 3] -> nge = [8, 8, -1, 3, -1]
//Brute
vector<int> nextGreaterElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> nge(n, -1);  //Creates a vector nge of size n and initialize all with -1

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {//2 pointer, i is in back and j is in front
                nge[i] = arr[j];//if found greater element, store it
                break;  //next greater is found
            }
        }
    }
    return nge;
}
//tc -> O(n^2) //sc -> O(n)

//optimal
vector<int> findNGE(vector<int> &arr) {
    int n = arr.size();
    vector<int> nge(n);//vector of nge of size n
    stack<int> st;//stores elements not indices

    for (int i = n - 1; i >= 0; i--) { //traverse from right to left
        while (!st.empty() && st.top() <= arr[i]) {//if stack is not empty
            st.pop();//and top of stack is smaller than the i, pop it 
        }//because it cant be nge for any element on left of i

        if (st.empty())//if stack is empty, no greater element
            nge[i] = -1;
        else{//if stack is not empty and top is greater than arr[i], nge is top
            nge[i] = st.top();
        }
        st.push(arr[i]); // push ith element in stack
    }
    return nge;
}
//[4, 5, 2, 10, 8]
//i = 4; stack is empty nge[4] = -1; push 8
//i = 3; stack top is 8 < 10; pop 8; stack is empty nge[3] = -1; push 10
//i = 2; stack top is 10 > 2; nge[2] = 10; push 2
//i = 1; stack top is 2 < 5; pop 2; stack top is 10 > 5; nge[1] = 10; push 5
//i = 0; stack top is 5 > 4; nge[0] = 5; push 4
//nge = [5, 10, 10, -1, -1 ]
//tc -> O(2n) -> for push and pop -> O(n) //sc -> O(n) + O(n) -> stack + in order to store answer