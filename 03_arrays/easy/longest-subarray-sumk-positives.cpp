#include<bits/stdc++.h>
using namespace std;

//Q14. Longest subarray with sum K [positives]
//Brute
int longestSubarraySumKPos(vector<int> &arr, long long K) {
    int len = 0;
    for(int i = 0; i < arr.size(); i++){//first pointer
        for(int j = i; j < arr.size(); j++){//second pointer now this will move forward 
            int s = 0;
            for(int k = j; k <= j; k++){//we will calculate sum from arr[i] to arr[j]
                s += arr[k];
            }

            if(s == K){//we will get the length of the subarray whose sum is equal to given K
                len = max(len, j - 1 + 1);
            }
        }
    }
    return len;
}
//tc -> O(n * n^2) => O(n^3) //sc -> O(1)

//Better
int longestSubarraySumKPos2(vector<int> &arr, long long K){
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;

    for(int i = 0; i < arr.size(); i++){
        sum += arr[i];//prefix sum calculation

        if(sum == K) {//case 1 -> if 0 to i has sum k
            maxLen = max(maxLen, i + 1); 
        }

        long long rem = sum - K; //case 2
        if(preSumMap.find(rem) != preSumMap.end()){//find if rem exists in the hashmap as stored as previous prefix sum
            int len = i - preSumMap[rem];//i - index of rem in map
            maxLen = max (maxLen, len);
        }

        if(preSumMap.find(sum) == preSumMap.end()){//to store the prefix sum if seeing for the first time
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}
//tc -> O(n) //sc -> O(1)