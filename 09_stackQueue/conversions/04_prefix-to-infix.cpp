#include <bits/stdc++.h>
using namespace std;

//Q4. Prefix to Infix Conversion
string prefixToInfix(string s) {
    stack<string> st;

    int i = s.length() - 1;  // start from rightmost character -> not reverse as it will increase tc

    while (i >= 0) {//starting from last

        // If operand → push to stack
        if (isalnum(s[i])) {
            st.push(string(1, s[i]));//Converts a single character into a string
        }

        // If operator
        else {//previously, postfix to infix we were doing t2 operator t1 but not here
            string t1 = st.top(); st.pop();//ab- -> t1 = b
            string t2 = st.top(); st.pop();//t2 = a

            string con = "(" + t1 + s[i] + t2 + ")";//it's t1 operator t2
            st.push(con);//b - a
        }

        i--;//going back till i = 0
    }

    return st.top();//stack contains only one element which is the con and that is our converted infix
}
//we are starting from last and going back
//here we are doing con reverse t1 operator t2 and not t2 first
//otherwise same process
//tc -> O(n) + O(n) => O(2n) => O(n) //sc -> O(n)