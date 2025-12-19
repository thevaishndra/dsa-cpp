#include <bits/stdc++.h>
using namespace std;

//Q1. N meetings in one room
data {
    start, end, pos;
}

bool comp(data val1, data val2) {
    return val1.end < val2.end
}

func(start, end, N) {
    data arr[n];
    for(int i = 0; i < n; i++) {
        arr[i].start = start[i];
        arr[i].end = end[i];
        arr[i].pos = i + 1;
    }
    sort(arr, comp);
    cnt = 1; freetime = arr[0].end; ds = arr[0].pos;
    for(int i = 1; i < n - 1; i++) {
        if(arr[i].start > freetime) {
            cnt = cnt + 1;
            freetime = arr[i].end;
            ds.add(arr[i].pos);
        }
    }
}
//tc -> O(2n + nlogn) //sc -> O(3n + n)