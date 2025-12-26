#include <bits/stdc++.h>
using namespace std;

//Q. Remove K Digits
//Given a string nums representing a non-negative integer, and an integer k, 
//find the smallest possible integer after removing k digits from num
string function(string s, int k) {
    stack<char> st;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        while (!st.empty() && k > 0 && st.top() > s[i]) {//add smaller nos in start
            st.pop();//if top is greater than current char, remove it
            k--;
        }
        st.push(s[i]);//add current char
    }

    //after loop If k still > 0, remove from end
    while (k > 0 && !st.empty()) {//in start there is small nos, so remove from last
        st.pop();
        k--;
    }

    // Build result from stack
    string res = "";
    while (!st.empty()) {
        res.push_back(st.top());//storing stack in res 
        st.pop();
    }

    // Stack gives reverse order
    reverse(res.begin(), res.end());//so reverse it

    //Edge case 1: Remove leading zeros
    while (!res.empty() && res[0] == '0') {
        res.erase(res.begin());
    }

    //Edge case 2: if res is empty, return "0" eg:- k = n, no condition will ever work
    if (res.empty()) return "0";//simply return 0

    return res;
}
//s = "1432219", k = 3
//i = 0; st is empty -> push 1; st = [1]
//i = 1; k-> 3 > 0; 1 > 4 no -> push 4; st = [1, 4]
//i = 2; k -> 3 > 0; 4 > 3 yes -> pop 4; k = 2; push 3; st = [1, 3]
//i = 3; k -> 2 > 0; 3 > 2 yes -> pop 3; k = 1; push 2; st = [1, 2]
//i = 4; k -> 1 > 0; 2 > 2 no -> push 2; st = [1, 2, 2]
//i = 5; k -> 1 > 0; 2 > 1 yes -> pop 2; k = 0; push 1; st = [1, 2, 1]
//i = 6; k -> 0; push 9; st = [1, 2, 1, 9]
//k > 0 no -> skip while loop
//res = "9121" st = empty
//reverse res -> "1219"
//no zeroes at start -> skip
//res is not empty -> skip
//return "1219"
//tc -> O(3n) + O(k) //sc -> O(n) + O(n)