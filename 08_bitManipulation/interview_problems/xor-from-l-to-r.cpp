#include <bits/stdc++.h>
using namespace std;

//Q4. Find XOR of nos from L to R (given range)
//brute
int findRangeXOR(int l, int r) {
    int ans = 0;
    for(int i = l; i <= r; i++) {
        ans ^= i;
    }
    return ans;
}
//tc-> O(n) //sc -> O(1)

//optimal
func(n) {
    if (n % 4 == 1) return 1;
    else if (n % 4 == 2) return n + 1;
    else if(n % 4 == 3) return 0;
    else return n;
}
//tc -> O(1) //sc -> O(1)