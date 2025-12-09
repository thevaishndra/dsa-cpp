#include <bits/stdc++.h>
using namespace std;

//Q1. Find the next greater element for each element in an array
//Brute
vector<int> nextGreaterElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> nge(n, -1);  // initialize all with -1

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                nge[i] = arr[j];
                break;  // found the next greater
            }
        }
    }

    return nge;
}
//tc -> O(n^2) //sc -> O(n)

//optimal
vector<int> findNGE(vector<int> &arr) {
    int n = arr.size();
    vector<int> nge(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {   // FIX: i >= 0 (not i <= 0)
        
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();                    // pop smaller elements
        }

        if (st.empty())
            nge[i] = -1;
        else
            nge[i] = st.top();

        st.push(arr[i]);                 // push current element
    }

    return nge;
}
//tc -> O(2n) //sc -> O(n) -> stack + O(n) -> inorder to store answer