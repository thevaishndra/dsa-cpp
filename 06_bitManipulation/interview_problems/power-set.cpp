#include <bits/stdc++.h>
using namespace std;

//Q3. Power set (Print all the subsets -> portion of the elements in the same order)
int powerSet(vector<int> &arr){
    int subsets = 1 << n;
    vector <int> ans;

    for(int num = 0; num < subset; num++) {
        vector<int> subset;
        for(int i = 0; i < n; i++) {
            if(num & (1 << i)) {
                subset.push_back(nums[i]);
            }
        }
        ans.push_back(subset);
    }
    return ans;
}
//tc -> n * 2^n //sc -> 2^n * n

