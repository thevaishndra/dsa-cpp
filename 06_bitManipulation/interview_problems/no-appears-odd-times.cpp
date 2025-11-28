#include <bits/stdc++.h>
using namespace std;

//Q2. Find the no. that appears odd no. of times
int noThatAppearsOddTimes(vector<int> &nums) {
    unordered_map <int, int> mpp;

    for(int i = 0; i < nums.size(); i++) {
        mpp[nums[i]]++; 
    }

    for(auto it : mpp) {
        if(it.second == 1) return it.first;
    }
    return -1;
} 
//tc -> (n * logm) + m  //sc -> O(m)

//optimal
int noThatAppearsOddTimes2(vector<int> &nums) {
    int XOR = 0;

    for(int i = 0; i < nums.size(); i++) {
        XOR ^= nums[i];
    }
    return XOR;
}
//tc -> O(n) //sc -> O(1)