#include<bits/stdc++.h>
using namespace std;

//Q6. Count no. of subarrays with given xor k
//Brute
int subarrayWithGivenXorK(vector<int> arr, int k) {
    int n = arr.size();
    int cnt = 0; 

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int xorr = 0;

            for(int k = i; k <= j; k++) {
                xorr = xorr ^ arr[k];
            }

            if(xorr = k) {
                cnt++;
            }
        }
    }
    return cnt;
}
//tc -> O(n^3) //sc -> O(1)

//Better
int subarrayWithGivenXorK(vector<int> arr, int k) {
    int n = arr.size();
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        int xorr = 0;
        for(int j = i; j <= n; j++) {
            xorr = xorr ^ arr[j];

            if(xorr == k) {
                cnt++;
            }
        }
    }
    return cnt;
}
//O(n^2) //O(1)

//Optimal
int subarrayWithGivenXorK(vector<int> arr, int k) {
    int n = arr.size();
    int xr = 0;

    map<int, int> mpp;
    mpp[xr]++;
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        xr = xr ^ arr[i];

        int x = xr ^ k;
        cnt += mpp[x];
        mpp[xr]++;
    }
    return cnt;
}
//tc -> O(n) or O(n log n) //sc -> O(n) 

