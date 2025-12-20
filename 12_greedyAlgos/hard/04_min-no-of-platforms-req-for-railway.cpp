#include <bits/stdc++.h>
using namespace std;

//Q4. Minimum number of platforms required for railway
func(arr, dep) {
    maxcnt = 0;
    for(int i = 0; i < n - 1; i++) {
        cnt = 1;
        for(int j = i + 1; j < n - 1; j++) {
            if(arr[i] dep[i] arr[j] dep[j]) {
                cnt++;
            }
            max cnt = max(maxcnt, cnt);
        }
    }
}
//tc -> O(n*2) //sc -> O(1)

//optimal
func(arr, dep) {
    sort(arr); sort(dep);
    int i = 0; int j = 0; int cnt = 0; int maxcnt = 0;
    while(i < n) {
        if(arr[i] <= dep[j]) {
            cnt = cnt + 1;
            i = i + 1;
        }
        else {
            cnt = cnt - 1;
            j = j + 1;
        }
        maxcnt = max(maxcnt, cnt);
    }
    return maxcnt;
}
//tc -> O(2nlogn + n) //sc -> O(1)