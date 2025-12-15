#include <bits/stdc++.h>
using namespace std;

//subarrays with 'k' diff integers
//brute
for(int i = 0; i < n; i++) {
    mpp;
    for(int j = i; i < n; i++) {
        mpp[nums[j]]++;
        if(mpp.size() == k) cnt = cnt+1;
        else if (mpp.size() > k) break;
    }
}
return cnt;
//tc -> O(n^2) //sc -> O(n)


//better
func(nums, k) {
    l = 0; r = 0; cnt = 0; mpp;
    while(r < nums.size()) {
        mpp[nums[r]]++;
    }
    while(mpp.size() <= k) {
        mpp[nums[l]]--;
        if(mpp[nums[l]] == 0) {
            mpp.erase(nums[i]);
            l = l - 1;
        }
        cnt = cnt + (r - l + 1);
        r = r + 1;
    }
    return cnt;
}
// == k
// [<= k] - [<= k - 1]
// func(nums, k) - func(nums, k - 1)

//tc -> O(2n) //sc -> O(n)