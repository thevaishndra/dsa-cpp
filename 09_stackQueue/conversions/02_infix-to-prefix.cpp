#include <bits/stdc++.h>
using namespace std;

//Q2. Infix to Prefix Conversion
int priority(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

string reverseString(string s) {
    reverse(s.begin(), s.end());
    return s;
}

string infixToPrefix(string s) {
    // Step 1: Reverse the string
    s = reverseString(s);

    // Step 2: Swap brackets
    for (int i = 0; i < s.length(); i++) {//as when we reverse this ( becomes this )
        if (s[i] == '(') s[i] = ')';//but we don't want that 
        else if (s[i] == ')') s[i] = '(';//(a+b) -> )b+a( -> not appropriate
    }//(b+a) -> we want this

    stack<char> st;//a temporary stack to store
    string ans = "";//resultant string

    for (int i = 0; i < s.length(); i++) {

        // If operand → add to result
        if (isalnum(s[i])) {//if it's a bo or alphabet add to ans
            ans += s[i];
        }

        else if (s[i] == '(') {//if its opening bracket add to stack
            st.push(s[i]);
        }

        else if (s[i] == ')') {//if it's closing bracket we need to add everything between the brackets
            while (!st.empty() && st.top() != '(') {//till the top is not opening bracket we are adding in ans
                ans += st.top();
                st.pop();//and meanwhile also popping them after adding to ans
            }
            st.pop(); // opening bracket we need to pop '('
        }

        // Operator
        else {
            // '^' is right associative
            if (s[i] == '^') {
                //as we don't want to pop operator of same priority
                //in infix to postfix we would have popped out
                while (!st.empty() && priority(s[i]) < priority(st.top())) {//we want < and not <=
                    ans += st.top();//Pop only if stack top has higher precedence
                    st.pop();
                }
            }
            // other operators left associative -> +-*/
            else {
                while (!st.empty() && priority(s[i]) <= priority(st.top())) {//pop if higher precedence or equal precedence
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
    }

    // Pop remaining operators
    while (!st.empty()) {//and them to the ans
        ans += st.top();
        st.pop();
    }

    // Final reverse to get prefix
    ans = reverseString(ans);
    return ans;
}
//basically 3steps -> reverse, convert from infix to postfix, reverse -> we converted infix to prefix
//when we do reverse we dont reverse the opening and closing brackets
//^ -> right associative; we do not pop when one more ^ comes
//+-*/ -> left associative; we pop when something of same precedence comes
//sometimes if we got ans as ^^abc -> we change it to ^a^bc -> this is due to expression tree and is correct than the ans we got
//tc -> O(n/2) + O(n/2) + O(2n) => O(3n) => O(n) //sc -> O(n)