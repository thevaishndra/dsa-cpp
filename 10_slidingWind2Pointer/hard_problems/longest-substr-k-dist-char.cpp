#include <bits/stdc++.h>
using namespace std;

//longest substring with atmost k distinct characters
//brute
func(s, k) {
    maxlen = 0; mpp<char, int>
    for(int i = 0; i < n; i++) {
        mpp.clear();
        for(j = i; i < n; i++) {
            mpp[s[j]]++;
            if(mpp.size() <= k) {
                maxlen = max(maxlen, j - i + 1);
            }
            else {
                break;
            }
        }
    }
    return maxlen;
}
//tc -> O(n^2)*log(256) //sc -> O(256)

//better
func(s, k) {
    maxlen = 0; l = 0; r = 0; mpp<char, int>
    while(r < s.size()) {
        mpp[s[r]]++;
    }
    while(mpp.size() > k) {
        hash[s[l]]--;
        if(hash[s[l]] == 0) mpp.erase(mpp[s[l]]);
        l = l + 1;
    }
    if(mpp.size() <= k) {
        maxlen = max(maxlen, r - l + 1);
        r = r + 1;
    }
    return maxlen;
}
//tc -> O(n) + O(n) + O(log256) //sc -> O(256)

//optimal
func(s, k) {
    maxlen = 0; l = 0; r = 0; mpp<char, int>
    while(r < s.size()) {
        mpp[s[r]]++;
    }
    if(mpp.size() > k) {//using if instead of while for optimal sol
        hash[s[l]]--;
        if(hash[s[l]] == 0) mpp.erase(mpp[s[l]]);
        l = l + 1;
    }
    if(mpp.size() <= k) {
        maxlen = max(maxlen, r - l + 1);
        r = r + 1;
    }
    return maxlen;
}