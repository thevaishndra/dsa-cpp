#include <bits/stdc++.h>
using namespace std;

//Q2. Infix to Prefix Conversion
int priority(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

string reverseString(string s) {
    reverse(s.begin(), s.end());
    return s;
}

string infixToPrefix(string s) {
    // Step 1: Reverse the string
    s = reverseString(s);

    // Step 2: Swap brackets
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }

    stack<char> st;
    string ans = "";

    for (int i = 0; i < s.length(); i++) {

        // If operand → add to result
        if (isalnum(s[i])) {
            ans += s[i];
        }

        else if (s[i] == '(') {
            st.push(s[i]);
        }

        else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop(); // pop '('
        }

        // Operator
        else {
            // '^' is right associative
            if (s[i] == '^') {
                while (!st.empty() && priority(s[i]) < priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
            }
            // other operators left associative
            else {
                while (!st.empty() && priority(s[i]) <= priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
    }

    // Pop remaining operators
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    // Final reverse to get prefix
    ans = reverseString(ans);
    return ans;
}

//tc -> O(n/2) + O(n/2) + O(2n) => O(3n) => O(n) //sc -> O(n)