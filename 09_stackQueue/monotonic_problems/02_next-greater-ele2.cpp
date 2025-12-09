#include <bits/stdc++.h>
using namespace std;

//Q2. Given a circular integer array arr, return the next greater element for every element in arr
//brute
vector<int> nextGreaterCircular(vector<int> &arr) {
    int n = arr.size();
    vector<int> nge(n, -1);
    
    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < i + n; j++) {   // FIX: go full circle (n steps)
            int ind = j % n;

            if (arr[ind] > arr[i]) {
                nge[i] = arr[ind];
                break;
            }
        }
    }

    return nge;
}
//tc -> O(n^2) //sc -> O(n)

//optimal
vector<int> findNGE(vector<int> &arr) {
    int n = arr.size();
    vector<int> nge(n, -1);
    stack<int> st;

    // Loop from 2n - 1 down to 0
    for (int i = 2 * n - 1; i >= 0; i--) {

        int idx = i % n;

        // Maintain decreasing monotonic stack
        while (!st.empty() && st.top() <= arr[idx]) {
            st.pop();
        }

        // Fill answer only during the first pass (i < n)
        if (i < n) {
            nge[idx] = st.empty() ? -1 : st.top();
        }

        st.push(arr[idx]);
    }

    return nge;
}
//tc -> O(4n) => O(n) //sc -> O(2n) + O(n) => O(n)
