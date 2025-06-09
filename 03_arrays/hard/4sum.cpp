#include<bits/stdc++.h>
using namespace std;

// Q4. 4Sum -> unique quadruplets that add up to give a sum of target, where i != j != k != l
//Brute
vector<vector<int>> fourSum(int target, vector<int> &arr) {
    int n = arr.size();
    set<vector<int>> st;//for unique quadruplets

    for(int i = 0; i < n; i++) {//4 loops to check every possible combination of 4 elements
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                for(int l = k + 1; l < n; l++) {
                    long long sum = arr[i] + arr[j];//calculating sum
                    sum += arr[k];
                    sum += arr[l];

                    if(sum == target) {
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
//tc -> O(n^4) //sc -> O(2 * no. of quadsruplets)

//Better -> l = target - (i + j + k) 
vector<vector<int>> fourSum2(int target, vector<int> &arr) {
    int  n = arr.size();
    set<vector<int>> st;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            set<long, long> hashset;
            for(int k = j + 1; k < n; k++){
                long long sum = arr[i] + arr[j];
                sum += arr[k];
                long long l = target - sum;
                if(hashset.find(l) != hashset.end()) {//if l is present in the hashset, then we have found a quadruplet
                    vector<int> temp = {arr[i], arr[j], arr[k], (int) (l)};//typecasting l to int
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
//tc -> O(n^3*log(m)) //sc -> O(2 * no. of quadruplets) + O(n)

//Optimal -> 
vector<vector<int>> fourSum3(int target, vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> ans;

    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; i++){
        if(i > 0 && arr[i] == arr[i - 1]) continue;//skip duplicate values of i to ensure we dont repeat same no. combinations
        for(int j = i + 1; j < n; j++) {
            if(j > i + 1 && arr[j] == arr[j - 1]) continue;//skip duplicate values of j

            int k = j + 1;//k starts after j
            int l = n - 1;//l starts from the end of the array

            while(k < l) {
                long long sum = arr[i];//to prevent overflow we use long long
                sum += arr[j];//sum of i + j + k + l
                sum += arr[k];
                sum += arr[l];

                if(sum == target) {
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    //move both pointeres inward to check for other combinations
                    k++;//move k forward
                    l--;//move l backward

                    while(k < l && arr[k] == arr[k - 1]) k++;//skip duplicate values of arr[k]
                    while(k < l && arr[l] == arr[l + 1]) l--;//skip duplicate values of arr[l]
                }
                else if(sum < target) {
                    k++;//if sum is less move k to right to try a larger value
                }
                else {
                    l--;//move l to left to try a smaller value
                }
            }
        }
    }
    return ans;
}
//tc -> O(n^3) //sc -> O(2 * no of quadruplets) 