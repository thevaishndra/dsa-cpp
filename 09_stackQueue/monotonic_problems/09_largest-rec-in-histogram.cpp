#include <bits/stdc++.h>
using namespace std;

// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1 return the area of the largest rectangle in histogram
//Brute
func(arr) {
    nse = findNSE(arr);
    pre = findNSE(Arr);
    maxi = 0;

    for(int i = 0; i < n - 1; i++) {
        maxi = max(maxi, arr[i] * (nse[i] - pse[i] - 1))
    }
    return maxi;
}
//tc -> O(5n) //sc -> O(2n)


//Optimal
func(Arr) {
    stack st;
    maxArea = 0;

    for(int i = 0; i < n - 1; i++) {
        while(st.empty() && arr[st.top] > arr[i]) {
            element = st.top();
            st.pop();
            nse = i;
            pse = st.empty() ? - 1 : st.top();
            maxArea = max(arr[element] * (nse - pse - 1), maxArea);
        }
        st.push[i];
    }

    while(!st.empty()) {
        nse = n;
        element = st.top(); st.pop();
        pse = st.empty() ? - 1 : st.top;
        maxArea = max(maxArea, (nse - pse - 1) * arr[ele])
    }
    return maxArea;
}
//tc -> O(n) + O(n) //sc -> O(n)