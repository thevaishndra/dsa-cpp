#include <bits/stdc++.h>
using namespace std;

//Q6. Prefix to Postfix Conversion
string prefixToPostfix(string s) {
    stack<string> st;
    int i = s.length() - 1;

    while (i >= 0) {

        // If operand
        if (isalnum(s[i])) {
            st.push(string(1, s[i]));
        }

        // If operator
        else {
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();

            string res = t1 + t2 + s[i];
            st.push(res);
        }

        i--;
    }

    return st.top();
}
//tc -> O(n) + O(n) => O(2n) => O(n) //sc -> O(n)