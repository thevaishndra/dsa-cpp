#include <bits/stdc++.h>
using namespace std;

//Q8. Insert Interval
func(arr[][], newInterval[]) {
    res = [][]; i = 0;
    while(i < n && arr[i][1] < newInterval[0]) {
        res.push_back(arr[i]);
        i++;
    }
    while(i < n && arr[i][0] < = newInterval[1]) {
        newInterval[0] = min(newInterval[0], arr[i][0]);
        newInterval[1] = max(newInterval[1], arr[i][1]);
        i++;
    }
    res.add(newInterval);
    while(i < n) {
        res.add(arr[i]);
        i++;
    }
    return res;
}
//tc -> O(n) //sc -> O(n)