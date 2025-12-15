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
    stack<char> st;//to temporary store operators and parentheses
    string ans = "";//to store final postfix expression

    for (int i = 0; i < s.length(); i++) {

        // If operand → add to output
        if (isalnum(s[i])) {//isalnum -> checks if its no or alphabet
            ans += s[i];//if it's operand it's added to ans
        }

        // If '(' → push
        else if (s[i] == '(') {//opening bracket goes to stack
            st.push(s[i]);
        }

        // If ')' → pop until '('
        else if (s[i] == ')') {//when it's closing bracket
            while (!st.empty() && st.top() != '(') {//till the top is not empty and not equal to (
                ans += st.top();//adding to ans
                st.pop();//and popping
            }
            st.pop(); // after everything closing bracket is left so pop '('
        }

        // Operator
        else {//add according to priority
            while (!st.empty() && priority(s[i]) <= priority(st.top())) {//till stack is not empty
                ans += st.top();//if priority is less in compare to the top, add top in ans
                st.pop();//and is popped from the stack
            }
            st.push(s[i]);//some will still be there add them too
        }
    }

    // Pop all remaining operators
    while (!st.empty()) {
        ans += st.top();//add to ans 
        st.pop();//pop them till it gets empty
    }

    return ans;
}
//a + b * ( c ^ d - e )
//ans : a; st : empty
//ans : a; st : +
//ans : ab; st : +
//ans : ab; st : +*
//ans : ab; st : +*(
//ans : abc; st : +*(^
//ans : abcd^; st: +*(-       - is low than ^, hence ^ goes in ans
//ans : abcd^e; st: +*(-)     add everything to ans which is between the brackets
//ans : abcd^e-; st: +*       whatever that is left is added to ans
//ans : abcd^e-*+; st: empty

//tc -> O(n) + O(n) => O(n) //sc -> O(n) + O(n) => O(n)


