#include<bits/stdc++.h>
using namespace std;

//Q5. Largest subarray with sum 0
//Brute
int largestSubarrayWithSumZero(vector<int>& arr) {
    int maxLen = 0;
    unordered_map<int, int> mpp;
    int sum = 0;

    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        if(sum == 0) {
            maxLen = i + 1;
        }
        else if(mpp.find(sum) != mpp.end()) {
            maxLen = max(maxLen, i - mpp[sum]);
        }
        else {
            mpp[sum] = i;
        }
    } 
    return maxLen;
}
//tc -> O(n^2) //sc -> O(1)

//Optimal
int largestSubarrayWithSumZero2(vector<int>& arr) {
    unordered_map<int, int> mpp;
    int maxi = 0;
    int sum = 0;

    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        if(sum == 0) {
            maxi = i + 1;
        }
        else {
            if(mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum]);
            }
            else {
                mpp[sum] = i;
            }
        }
    }
    return maxi;
}
//tc -> O(n) //sc -> O(n)
