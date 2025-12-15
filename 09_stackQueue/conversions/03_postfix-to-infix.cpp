#include <bits/stdc++.h>
using namespace std;

//Q3. Postfix to Infix Conversion
string postfixToInfix(string s) {
    stack<string> st;//stores string

    for (int i = 0; i < s.length(); i++) {

        // If operand → push as string
        if (isalnum(s[i])) {
            st.push(string(1, s[i]));//Converts a single character into a string
        }
        else {//When the character is an operator (+ - * / ^)
            // Operator → pop two operands
            string t1 = st.top(); st.pop();//ab- -> t1 = b
            string t2 = st.top(); st.pop();//t2 = a

            //as we popped t2 last which means it will come first then operator then t1
            string con = "(" + t2 + s[i] + t1 + ")";//a-b
            st.push(con);
        }
    }

    return st.top();//stack contains only one element which is the con and that is our converted infix
}
//we push operand
//if an operator comes, we pop last 2 operands
//we make a con with opening and closing brackets and in between the operands with a operator in between
//tc -> O(n) + O(n) => O(2n) => O(n) //sc -> O(n)