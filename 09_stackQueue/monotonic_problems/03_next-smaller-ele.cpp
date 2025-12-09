#include <bits/stdc++.h>
using namespace std;

//Q3. Given an array of integers arr, your task is to find the Next Smaller Element (NSE) for every element in the array
//The Next Smaller Element for an element x is defined as the first element to the right of x that is smaller than x.
//If there is no smaller element to the right, then the NSE is -1

//Brute
vector<int> nextSmallerElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> nse(n, -1);

    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {   // FIX: look to the RIGHT

            if (arr[j] < arr[i]) {
                nse[i] = arr[j];
                break;
            }
        }
    }

    return nse;
}
//tc -> O(n^2) //sc -> O(1)

//optimal
vector<int> findNSE(vector<int> &arr) {
    int n = arr.size();
    vector<int> nse(n, -1);
    stack<int> st;

    // Traverse from RIGHT to LEFT
    for (int i = n - 1; i >= 0; i--) {

        // Pop elements greater or equal → want next SMALLER
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        // Answer
        nse[i] = st.empty() ? -1 : st.top();

        // Push current element
        st.push(arr[i]);
    }

    return nse;
}
//tc -> O(n^2) //sc -> O(n)
