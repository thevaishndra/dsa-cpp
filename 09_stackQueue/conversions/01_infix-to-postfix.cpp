#include <bits/stdc++.h>
using namespace std;

//very limited chance to come in interviews

//operator :- ^ * / + -
//operands :- A-Z, a-z, 0-9
//priority :- ^    -> 3
//            * /  -> 2
//            + -  -> 1

//prefix :- * + pq - mn -> operators are before the operand
//infix :- (p + q) * (m - n) -> operators are in between operand
//postfix :- pq + mn - * -> operators are after the operand

//Q1. Infix to Postfix Conversion
int priority(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}
string infixToPostfix(string s) {
    stack<char> st;
    string ans = "";

    for (int i = 0; i < s.length(); i++) {

        // If operand → add to output
        if (isalnum(s[i])) {
            ans += s[i];
        }

        // If '(' → push
        else if (s[i] == '(') {
            st.push(s[i]);
        }

        // If ')' → pop until '('
        else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop(); // pop '('
        }

        // Operator
        else {
            while (!st.empty() && priority(s[i]) <= priority(st.top())) {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    // Pop all remaining operators
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}
//tc -> O(n) + O(n) => O(n) //sc -> O(n) + O(n) => O(n)
