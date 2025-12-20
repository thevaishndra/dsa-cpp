#include <bits/stdc++.h>
using namespace std;

//Q10. Non-overlapping Intervals
bool comp(val1[], val2[]) {
    return val1[1] < val2[1];
}
func(arr[][]) {
    sort(arr, comp); 
    cnt = 1;
    lastendtime = arr[0][1];

    for(int i = 1; i < n - 1; i++) {
        if(arr[i][0] >= lastendtime) {
            cnt++;
            lastendtime = arr[i][1];
        }
    }
    return n - cnt;
}
//tc -> O(nlogn) + O(n) sc -> O(1)