#include <bits/stdc++.h>
using namespace std;

//Q6. Prefix to Postfix Conversion
string prefixToPostfix(string s) {
    stack<string> st;
    int i = s.length() - 1;

    while (i >= 0) {////starting from last

        // If operand
        if (isalnum(s[i])) {
            st.push(string(1, s[i]));////Converts a single character into a string
        }

        // If operator
        else {
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();

            string res = t1 + t2 + s[i];//here the operator comes in last and t1 is in the start not t2
            st.push(res);
        }

        i--;
    }

    return st.top();
}
///-ab*+def
//start from last i = f; st = f
//i = e; st = f e
//i = d; st = f e d -> t1 = d; t2 = e
//i = +; st = f de+ -> t1 t2 operator = de+
//i = *; st = def+* -> t1 = de+; t2 = f
//i = b; st = def+* b
//i = a; st = def+* b a -> t1 = a; t2 = b
//i = -; st = def+* ab- 
//i = /; st = ab-def+*/ -> t1 = ab-; t2 = def+*
//tc -> O(n) + O(n) => O(2n) => O(n) //sc -> O(n)