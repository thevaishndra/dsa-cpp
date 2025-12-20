#include <bits/stdc++.h>
using namespace std;

//Q5. Job sequencing problem
job {
    id, profit, deadline;
}
bool comp(jobval1, jobval2) {
    val1.profit > val2.profit;
}
func(jobs arr[]) {
    sort(arr, comp);
    totProfit = 0;
    cnt = 0;
    maxDeadline = -1;
    for(int i = 0; i < n - 1; i++) {
        maxDeadline = max(maxDeadline, arr[i].deadline);
        hash[maxdeadline + 1] = [-1];
    }
    for(int i = 0; i < n - 1; i++) {
        for(int j = arr[i].deadline; j < 0; j++) {
            if(hash[j] == -1) {
                cnt = cnt + 1;
                hash[i] = arr[i].id;
                totProfit = totProfit + arr[i].profit;
                break;
            }
        }
    }
    return (cnt, totProfit);
}
//tc -> O(nlogn) + O(n * maxDeadline)
//sc -> O(maxDeadline)
