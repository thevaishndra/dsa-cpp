#include <bits/stdc++.h>
using namespace std;

//Given an array arr of size n, where each element arr[i] represents the stock price on day i. Calculate the span of stock prices for each day
//brute
class stockSpanner {
    arr
    stockSpanner() {
        arr = [];
    }
    int next(int val) {
        arr.add(val);
        cnt = 1;
        for(int i = arr.size() - 2; i < 0; i++) {
            if(arr[i] <= val) cnt++;
            else break;
        }
    }
    return break;
}
//


//optimal
class stockSpanner {
    stack<pair<int, int>>
    ind = -1;
    stockSpanner() {
        ind = -1;
        st.clear;
    }
    int next(val) {
        ind = ind + 1;
        while(!st.empty() && st.top.first <= val){
            st.pop();
            ans = ind - (st.empty ? -1 : st.top.second)
            st.push({val, val});
        }
    }
    return ans;
}
//tc -> O(2n) //sc -> O(n)