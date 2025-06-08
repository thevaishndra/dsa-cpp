#include<bits/stdc++.h>
using namespace std;

//Q3. 3Sum -> unique triplets that add up to give a sum of zero
//Brute
vector<vector<int>> threeSum(int n, vector<int> &arr) {
    set<vector<int>> st;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {//start from the next element to avoid duplicates
            for(int k = j + 1; k < n; k++) {
                if(arr[i] + arr[j] + arr[k] == 0) {//check if the sum of the triplet is zero
                    vector<int> triplet = {arr[i], arr[j], arr[k]};
                    sort(triplet.begin(), triplet.end());//sort the triplet to ensure uniqueness
                    st.insert(triplet); 
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
//tc -> O(n^3 . log(no. of unique triplets) //sc -> O(2 * no. of unique triplets)

//Better -> optimize it to 2 loops
vector<vector<int>> threeSum2(int n, vector<int> &arr) {
    set<vector<int>> st;

    for(int i = 0; i < n; i++) {
        set<int> hashset;//we need empty set after i changes
        for(int j = i + 1; j < n; j++) {
            int k = -(arr[i] + arr[j]);// i + j + k = 0 => k = -(i + j)

            if(hashset.find(k) != hashset.end()) {//if k is present in the hashset, then we have found a triplet
                vector<int> triplet = {arr[i], arr[j], k};//create a triplet
                sort(triplet.begin(), triplet.end());//sort to maintain ascending order
                st.insert(triplet);//inserting into set to remove duplicates
            }
            hashset.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
//tc -> O(n^2 . log(no. of unique triplets) //sc -> O(2 * no. of unique triplets) + O(n)

//Optimal -> sort the array and use 2 pointers
vector<vector<int>> threeSum3(int n, vector<int> &arr) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; i++) {
        if(i != 0 && arr[i] == arr[i - 1]) continue;

        int j = i + 1;
        int k = n - 1;//k is in the end
        while(j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if(sum < 0) {//doing in sorted array so, sum < 0 means we need to increase the sum
                j++;
            }
            else if(sum > 0) {//sum > 0 means we need to decrease the sum
                k--;
            }
            else {
                vector<int> triplet = {arr[i], arr[j], arr[k]};//valid triplet is found
                ans.push_back(triplet);
                //after storing triplet we move j and k to the next unique elements
                j++;
                k--;
                
                //to avoid storing duplicates
                while(j < k && arr[j] == arr[j - 1]) j++;//if the next j is same as previous one skip it
                while(j < k && arr[k] == arr[k + 1]) k--;//if the next k is same as previous one skip it
            }
        }
    }
    return ans;
}
//tc -> O(n log n) + O(n^2) //sc -> O(no. of quadruplets)