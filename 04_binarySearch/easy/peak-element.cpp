#include<bits/stdc++.h>
using namespace std;

//Q.10 Find peak element arr[i - 1] < arr[i] > arr[i + 1]
//Brute 
int findPeakElement(vector<int> &arr) {
    for(int i = 0; i <= arr.size() - 1; i++){
        if((i == 0 || (arr[i] > arr[i - 1])) && (i == arr.size() - 1 || (arr[i] > arr[i + 1]))){
            return i;
        }
    }
}
//tc -> O(n) //sc -> O(1)

//Optimal
int findPeakElement(vector<int>& arr) {
    int n = arr.size();
    if(n == 1) return 0;
    if(arr[0] > arr[1]) return 0;
    if(arr[n - 1] > arr[n - 2]) return n - 1;

    int low = 1, high = n - 2;
    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) 
            return mid;

        if(arr[mid] < arr[mid + 1]) 
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return -1; 
}
//tc -> O(logn) //sc -> O(1)
