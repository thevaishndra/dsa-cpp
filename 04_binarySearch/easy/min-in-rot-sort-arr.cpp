#include<bits/stdc++.h>
using namespace std;

//Q.7 Find minimum in rotated sorted array
//Brute - linear search

//Better 
int findMinInRotSortArr(vector<int> &arr){
    int low = 0; int high = arr.size() - 1; int ans = INT_MAX;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[low] <= arr[mid]){//find the minimum
            ans = min(ans, arr[low]);//store it
            low = mid + 1;//eliminate the remaining part of that side
        }
        else {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}
//tc -> O(logn) //sc -> O(1)

//Optimal
int findMinInRotSortArr2(vector<int> &arr) {
    int low = 0; int high = aarr.size() - 1; int ans = INT_MAX;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[low] <= arr[high]) {//edge case -> if search space is already sorted means rotated 0 times
            ans = min(ans, arr[low]);//no need to search low is the smallest
            break;
        }
        if(arr[low] <= arr[mid]) {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}