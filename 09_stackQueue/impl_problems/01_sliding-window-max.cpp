#include <bits/stdc++.h>
using namespace std;

//Given an array of integers arr, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window
//Brute
list =[];
for(int i = 0; i < n -k; i++) {
    maxi = arr[i];
    for(int j = i; j < i + k - 1; j++) {
        maxi = max(maxi, arr[j]);
        list.odd(maxi);
    }
    return list;
}
//tc -> O(n - k) * k //sc -> O(n - k)


//Optimal
func(arr, k) {
    list[]; dq
    for(int i = 0; i < n - 1; i++) {
        if(!dq.empty() && dq.front() <= i -k) dq.pop.front;

        while(!dq.empty() && arr[dq.back] <= arr[i]) {
            dq.pop_back;
            dq.push(i);
            if(i >= k - 1) list.add(arr[dq.front])
        }
    }
    return list;
}
//tc -> O(2n) //sc -> O(k) + O(n - k)