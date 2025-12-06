#include <bits/stdc++.h>
using namespace std;

//Q4. Prefix to Infix Conversion
string prefixToInfix(string s) {
    stack<string> st;

    int i = s.length() - 1;  // start from rightmost character

    while (i >= 0) {

        // If operand → push to stack
        if (isalnum(s[i])) {
            st.push(string(1, s[i]));
        }

        // If operator
        else {
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();

            string con = "(" + t1 + s[i] + t2 + ")";
            st.push(con);
        }

        i--;
    }

    return st.top();
}
//tc -> O(n) + O(n) => O(2n) => O(n) //sc -> O(n)