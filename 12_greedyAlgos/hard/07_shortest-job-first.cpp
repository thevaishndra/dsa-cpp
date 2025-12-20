#include <bits/stdc++.h>
using namespace std;

//Q7. Shortest Job First (SJF) Scheduling Algorithm (Non-preemptive)
func(arr) {
    sort(arr)
    t = 0; wttime = 0;
    for(int i = 0; i < n - 1; i++) {
        wttime = wttime + t;
        t = t + arr[i];
    }
    return wttime;
}
//tc -> O(n) + O(nlogn) //sc -> O(1)