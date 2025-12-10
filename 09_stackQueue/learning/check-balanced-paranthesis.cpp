#include <bits/stdc++.h>
using namespace std;

//Q.7 Check for balanced paranthesis
bool isBalanced(string s) {
    stack<char> st;

    for (int i = 0; i < s.length(); i++) {//loop through each character
        char ch = s[i];

        // If opening bracket, push into stack
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        else {
            // Closing bracket found but stack empty -> unbalanced
            if (st.empty()) return false;//means there is no opening bracket for this closing bracket

            //This top element must match the type of closing bracket.
            char top = st.top();//get the top element of stack 
            st.pop();//pop the top element

            // Check matching pair
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }//if anycase its not matching return false
        }
    }

    // At the end, stack must be empty
    return st.empty();
}
//{[(])}
//push {, [, ( -> we are pushing opening brackets
//now comes ] //when comes a closing bracket we will not push
//stack is not empty
//top = ( and it's popped //we will store the top element and pop it from stack
//now check matching pair of top element to current ch
//top = ( and ch = ] -> not matching => return false
//if it matches we will continue checking other characters 
//and in the end if stack is empty return true else false
//tc -> O(n) //sc -> O(n)