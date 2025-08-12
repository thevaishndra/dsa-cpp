#include<bits/stdc++.h>
using namespace std;

//Q15. Longest subarray with sum K [positives + negatives]
//Brute - same code when we used for longest subarray sum k positives
int getLongestSubarray(vector<int>& arr, int k) {
    int len = 0;
    for (int i = 0; i < arr.size(); i++) { // starting index
        for (int j = i; j < arr.size(); j++) { // ending index
            // add all the elements of
            // subarray = a[i...j]:
            int s = 0;
            for (int K = i; K <= j; K++) {
                s += arr[K];
            }

            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}

//Optimal -> the better sol of longest subarray sum k positives
int getLongestSubarray(vector<int>& a, int k) {
    int n = a.size(); // size of the array.

    map<int, int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        //calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        int rem = sum - k;

        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}
//tc -> O(n*1) unordered map -> O(n*n) in worst case if it has collisions //sc -> O(n) worst case