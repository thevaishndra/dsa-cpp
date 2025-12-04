#include <bits/stdc++.h>
using namespace std;

//Q.7 Check for balanced paranthesis
bool isBalanced(string s) {
    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        // If opening bracket, push into stack
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        else {
            // Closing bracket found but stack empty -> unbalanced
            if (st.empty()) return false;

            char top = st.top();
            st.pop();

            // Check matching pair
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    // At the end, stack must be empty
    return st.empty();
}

//tc -> O(n) //sc -> O(n)