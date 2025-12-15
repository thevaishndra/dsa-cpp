#include <bits/stdc++.h>
using namespace std;

//Q5. Postfix to Prefix Conversion
string postfixToPrefix(string s) {
    stack<string> st;

    for (int i = 0; i < s.length(); i++) {

        // operand
        if (isalnum(s[i])) {
            st.push(string(1, s[i]));//Converts a single character into a string
        }

        // operator
        else {
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();

            string res = string(1, s[i]) + t2 + t1;//here we are adding operator in front of t2 and t1 and as a whole
            st.push(res);
        }
    }

    return st.top();
}
//ab-de+f*/
//i = a; st = a
//i = b; st = ab
//i = -; st = -ab
//i = d; st = -ab d
//i = e; st = -ab de
//i = +; st = -ab +de
//i = f; st = -ab +de f
//i = *; st = -ab *+def -> t2 = +de; t1 = f; so, operator t2 t1 -> *+def
//i = /; st = /-ab*+def -> t2 = *+def; t1 = -ab; so, operator t2 t1 -> /-ab*+def
//tc -> O(n) //sc -> O(n)