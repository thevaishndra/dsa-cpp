#include <bits/stdc++.h>
using namespace std;

//Given a string nums representing a non-negative integer, and an integer k, find the smallest possible integer after removing k digits from num.
function (string s) {
    stack <char> st;
    for(int i = 0; i < n - 1; i++) {
        while(!st.empty() && k > 0 && (st.top() - '0') > s[i] - '0') {
            st.pop();
            k = k - 1;
        }
        st.push(s[i]);
    }
    while(k > 0) {
        st.pop();
        k--;
    }
    if(st.empty()) return "0";
    res = "";

    while(!st.empty()) {
        res = res + st.top();
        st.pop();
    }

    while(res.size != 0 && res.back() == '0') {
        res.pop.back
        reverse(Res);
        if(res.empty()) return 0;
        return res;
    }
}
//tc -> O(3n) + O(k) //sc -> O(n) + O(n)