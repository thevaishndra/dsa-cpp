#include <bits/stdc++.h>
using namespace std;

//Q5. Valid Parenthesis String
//brute
f(s, ind, cnt) {
    if(cnt < 0) return false;
    if(ind == n) {
        return cnt == 0;
    }
    if(s[ind] == '(') {
        return f(s, ind + 1, cnt + 1);
    }
    if(s[ind] == ')') {
        return f(s, ind + 1, cnt - 1);
    }
    return f(s, ind + 1, cnt + 1) || f(s, ind + 1, cnt - 1) || f(s, ind + 1, cnt);
}
//tc -> O(3^n)
//sc -> O(n)
//if applied dp tc -> O(n^2) sc -> O(n^2)

//optimal
func(s) {
    min = 0; max = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            min = min + 1;
            max = max + 1;
        }
        else if(s[i] == ')') {
            min = min - 1;
            max = max - 1;
        }
        else {
            min = min - 1;
            max = max + 1;
        }
    }
    if(min < 0) min = 0;
    if(max < 0) return false;
    return min == 0;
}
//tc -> O(n) //sc -> O(1)