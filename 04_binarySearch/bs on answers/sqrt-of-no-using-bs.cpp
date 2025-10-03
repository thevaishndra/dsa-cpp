#include<bits/stdc++.h>
using namespace std;

//Q1. Find sqrt of a no using binary search
//brute
int findSqrt(int n){
    int ans = 0
    for(int i = 1; i <= n; i++){
        long long val = i * i;
        if(val <= n){
            ans = i;
        }
        else {
            break;
        }
    }
}
//tc -> O(n) //sc -> O(1)

//better
int findSqrt2(int n){
    int ans = sqrt(n);
    return ans;
}
//tc -> O(logn) //sc -> O(1)

//optimal
int findSqrt3(int n){
    int low = 1; int high = n;
    while(low <= high) {
        long long mid = (low + high) / 2;
        long long val = mid * mid;
        if(val <= (long long)(n)){
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return high;
}
//tc -> O(logn) //sc -> O(1)