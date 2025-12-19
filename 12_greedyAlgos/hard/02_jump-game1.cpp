#include <bits/stdc++.h>
using namespace std;

//Q2. Jump game 1
func(arr) {
    maxInd = 0;
    for(int i = 0; i < n - 1; i++) {
        if(i > maxInd) return false;
        maxInd = max(maxInd, i + arr[i]);
    }
    return true;
}
//tc -> O(n) //sc -> O(1)