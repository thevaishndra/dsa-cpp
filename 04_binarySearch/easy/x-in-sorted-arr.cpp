#include <bits/stdc++.h>
using namespace std;

//Q1. Find x in sorted array
int findXInSortedArr(vector<int> &arr, int target){
    int low = 0; int high = arr.size() - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target) return mid;
        else if (target >= arr[mid]) low = mid + 1;
        else high = mid - 1;        
    }
    return -1
}
//tc -> O(logn) //sc -> O(1)