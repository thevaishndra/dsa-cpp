#include <bits/stdc++.h>
using namespace std;

//Q3. Postfix to Infix Conversion
string postfixToInfix(string s) {
    stack<string> st;

    for (int i = 0; i < s.length(); i++) {

        // If operand → push as string
        if (isalnum(s[i])) {
            st.push(string(1, s[i]));
        }
        else {
            // Operator → pop two operands
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();

            string con = "(" + t2 + s[i] + t1 + ")";
            st.push(con);
        }
    }

    return st.top();
}
//tc -> O(n) + O(n) => O(2n) => O(n) //sc -> O(n)