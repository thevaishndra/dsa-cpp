#include <bits/stdc++.h>
using namespace std;

//Q. Largest Rectangle in histogram
// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1 return the area of the largest rectangle in histogram
//Brute
vector<int> findPSE(vector<int>& arr) {
    int n = arr.size();
    vector<int> pse(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pse;
}

vector<int> findNSE(vector<int>& arr) {
    int n = arr.size();
    vector<int> nse(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nse;
}

int largestRectangleArea(vector<int>& arr) {
    int n = arr.size();
    vector<int> pse = findPSE(arr);
    vector<int> nse = findNSE(arr);

    int maxi = 0;

    for (int i = 0; i < n; i++) {
        int width = nse[i] - pse[i] - 1;
        maxi = max(maxi, arr[i] * width);
    }
    return maxi;
}

//tc -> O(5n) //sc -> O(2n)


//Optimal
int largestRectangleArea(vector<int>& arr) {
    int n = arr.size();
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            int element = st.top();
            st.pop();

            int nse = i;
            int pse = st.empty() ? -1 : st.top();

            maxArea = max(maxArea, arr[element] * (nse - pse - 1));
        }
        st.push(i);
    }

    while (!st.empty()) {
        int element = st.top();
        st.pop();

        int nse = n;
        int pse = st.empty() ? -1 : st.top();

        maxArea = max(maxArea, arr[element] * (nse - pse - 1));
    }

    return maxArea;
}

//tc -> O(n) + O(n) //sc -> O(n)