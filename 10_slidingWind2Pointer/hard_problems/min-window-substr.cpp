#include <bits/stdc++.h>
using namespace std;

//minimum window substring
//brute
mixlen = 10^9; sindex = -1;
for(i = 0; i < n; i++) {
    hash[256] = {0};
    for(j = 0; j < m; j++) {
        hasht[t[j]]++;
    }
    for(j = 0; j < n; j++) {
        if(hash[s[j]] > 0) cnt = cnt + 1;
        hash[s[j]]--;
    }
    if(cnt == m) {
        if(j - i + 1 < minlen) {
            minlen = j - i + 1;
            sIndex = i;
            break;
        }
    }
}
s.substr(sindex, minlen);
//tc -> O(n^2) //sc -> O(256)


//better
func(s,t) {
    hash[256] = [0];
    n = s.size();
    m = t.size();
    i = 0; r = 0; minlen = 10^9; sindex = -1; cnt = 0;
    for(int i = 0; i < n; i++) {
        hash[t[i]]++;
        while(r < size()) {
            if(hash[s[r]] > 0) cnt = cnt + 1;
            hash[s[r]]--;
        }
        while(cnt == m) {
            if(r - l + 1 < minlen) {
                minlen = r - l + 1;
                sindex = l;
            }
            hash[s[i]]--
            if(hash[s[i]] > 0) cnt = cnt - 1;
        }
        r = r + 1;
    }
    return sindex == -1 ? "" : s.substr(sindex, minlen);
}
//tc -> O(2n) + O(m) //sc -> O(256)