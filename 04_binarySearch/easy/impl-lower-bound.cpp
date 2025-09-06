#include <bits/stdc++.h>
using namespace std;

//Q2. Find the lower bound of a given no in sorted array
//lower bound -> smallest element where arr[ind] >= x {x is the given key i n ques}
int lowerBound(vector<int> &arr, int x){
    int low = 0; int high = n -1; int ans = x;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}
//tc -> O(logn) //sc -> O(1)
//Search insert position -> this is same as lower bound

//Q3. Find the lower bound of a given no in sorted array
//upper bound -> smallest element where arr[ind] > x {x is the given key i n ques}
int lower_bound(vector<int> &arr, int x){
    int low = 0; int high = arr.size() - 1;
    while(low <= high){
        int mid = (low + high) /2;
        if(arr[mid] > x){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}
//tc -> O(logn) //sc -> O(1)