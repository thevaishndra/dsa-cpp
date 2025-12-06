#include <bits/stdc++.h>
using namespace std;

//Q5. Postfix to Prefix Conversion
string postfixToPrefix(string s) {
    stack<string> st;

    for (int i = 0; i < s.length(); i++) {

        // operand
        if (isalnum(s[i])) {
            st.push(string(1, s[i]));
        }

        // operator
        else {
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();

            string res = string(1, s[i]) + t2 + t1;
            st.push(res);
        }
    }

    return st.top();
}
//tc -> O(n) //sc -> O(n)