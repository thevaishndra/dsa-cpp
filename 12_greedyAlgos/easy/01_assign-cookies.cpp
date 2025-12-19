#include <bits/stdc++.h>
using namespace std;

//Q1. Assign Cookies
func(greed, size) {
    n = greed.size(); m = size.size();
    l = 0; r = 0;
    sort(greed);
    sort(size);
    while(l < m && r < n) {
        if(greed[r] <= size[l]) {
            r = r + 1;
        }
        l = l + 1;
    }
    return r;
}
//tc -> O(nlogn + mlogm + m)
//sc -> O(1)