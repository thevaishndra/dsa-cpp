#include <bits/stdc++.h>
using namespace std;

//Q3. Jump Game II
//brute
f(ind, jumps) {
    if(ind >= n - 1) return jumps;
    int mini = INT_MAX;
    for(int i = 1; i < arr[ind]; i++) {
        mini = min(mini, f(ind + i, jump + 1));
    }
    return mini;
}
//tc -> O(n^n) //sc -> O(n)
//if applied dp -> O(n^2) //sc -> O(n^2)
//if(dp[ind][jumps] -1) return dp[ind]jump

//optimal
func(Arr) {
    jumps = 0; l = 0; r = 0;
    while(r < n -1) {
        farthest = 0;
        for(ind = l; ind <= r; ind++) {
            farthest = max(i + arr[ind], farthest);
            l = r + 1; jumps = jumps + 1;
            r = farthest;
        }
    }
    return jumps;
}
//tc -> O(n) //sc -> O(1)