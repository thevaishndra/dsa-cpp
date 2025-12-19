#include <bits/stdc++.h>
using namespace std;

//Q3. Find minimum number of coins using Greedy Algorithm
int deno[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
int n = 9;
vector<int> ans;
for(int i = n - 1; i >= 0; i--) {
    //find denomination
    while(v >= deno[i]) {
        v -= deno[i];
        ans.push_back(deno[i]);
    }
}
for(int i = 0; i < ans.size(); i++) {
    cout<< ans[i]<<" ";
}
//tc -> O(v)
//sc -> O(1)