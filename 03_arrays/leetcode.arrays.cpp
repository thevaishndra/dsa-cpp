//Array leetcode ques

// 1752. Check if Array Is Sorted and Rotated
// int count = 0;
//         int n = nums.size();
//         for (int i = 0; i < n; i++){
//             if(nums[i] > nums[(i + 1) % n]){
//                 count ++;
//             } 
//             if(count > 1){
//                 return false;
//             }
//         } return true;


//26. Remove Duplicates from Sorted Array
// int i = 0; int n = nums.size();
//         for(int j = 1; j < n; j++){
//             if (nums[j] != nums[i]){
//                 nums[i + 1] = nums[j];
//                 i++;
//             }
//         }
//         return i + 1;


//189. Rotate Array
//  k = k % nums.size();
//         reverse(nums.begin(), nums.end());
//         reverse(nums.begin(), nums.begin() + k);
//         reverse(nums.begin() + k, nums.end());


//283. Move Zeroes
// int j = -1;
//         for(int i = 0; i < nums.size(); i++){
//             if(nums[i] == 0){
//                 j = i;
//                 break;
//             }
//         }
//         if (j == -1) return;
//         for(int i = j + 1; i < nums.size(); i++){
//             if(nums[i] != 0){
//                 swap(nums[i], nums[j]);
//                 j++;
//             }
//         }
//         return;

// 268. Missing Number
// int xor1 = 0; int xor2 = 0;
//         int n = nums.size();
//         for(int i = 0; i < n; i++){
//             xor2 = xor2 ^ nums[i];
//             xor1 = xor1 ^ i;
//         }
//         xor1 = xor1 ^ n;
//         return xor1 ^ xor2;

// 485. Max Consecutive Ones
// int cnt = 0; int maxi = 0;
//         for(int i = 0; i < nums.size(); i++){
//             if(nums[i] == 1){
//                 cnt++;
//                 maxi = max(maxi, cnt);
//             } else{
//                 cnt = 0;
//             }
//         }
//         return maxi;

// 136. Single Number
// int xorr = 0;
//         for(int i = 0; i < nums.size(); i++){
//             xorr = xorr ^ nums[i];
//         }
//         return xorr;

//------------------------------------------------------------------------------------------------------

//1. Two Sum
//  map <int, int> mpp;
//         for(int i = 0; i < nums.size(); i++){
//             int a = nums[i]; int more = target - a;
//             if(mpp.find(more) != mpp.end()){
//                 return {mpp[more], i};
//             }
//             mpp[a] = i;
//         }
//         return {-1, -1};

// 75. Sort Colors
// int low = 0; int mid = 0; int high = nums.size() - 1;
//         while(mid <= high){
//             if(nums[mid] == 0){
//                 swap(nums[low], nums[mid]);
//                 low++;
//                 mid++;
//             }
//             else if(nums[mid] == 1){
//                 mid++;
//             }
//             else{
//                 swap(nums[mid], nums[high]);
//                 high--;
//             }
//         }

// 169. Majority Element
// int cnt = 0; int el;
//         for(int i = 0; i < nums.size(); i++){
//             if(cnt == 0){
//                 cnt = 1;
//                 el = nums[i];
//             }
//             else if(nums[i] == el){
//                 cnt++;
//             }
//             else {
//                 cnt--;
//             }
//         }
//         int cnt1 = 0;
//         for(int i = 0; i < nums.size(); i++){
//             if(nums[i] == el) cnt1++;
//         }
//         if(cnt1 > (nums.size()/2)){
//                 return el;
//             }
//             return -1;

// 53. Maximum Subarray
// int sum = 0; int maxi = INT_MIN;
//         for(int i = 0; i < nums.size(); i++){
//             sum = sum + nums[i];
//             if(sum > maxi){
//                 maxi = sum;
//             }
//             if(sum < 0){
//                 sum = 0;
//             }
//         }
//         return maxi;

// 121. Best Time to Buy and Sell Stock
// int maxProfit(vector<int>& prices) {
//         int mini = prices[0]; int profit = 0;
//         for(int i = 1; i < prices.size(); i++){
//             int cost = prices[i] - mini;
//             profit = max(profit, cost);
//             mini = min(mini, prices[i]);
//         }
//         return profit;
//     }

// 2149. Rearrange Array Elements by Sign
// int n = nums.size();
//         vector<int> ans(n,0);
//         int pIndex = 0; int nIndex = 1;
//         for(int i = 0; i < n; i++){
//             if(nums[i] < 0){
//                 ans[nIndex] = nums[i];
//                 nIndex +=2;
//             }
//             else{
//                 ans[pIndex] = nums[i];
//                 pIndex += 2;
//             }
//         }
//         return ans;

// 31. Next Permutation
// int index = -1; int n = nums.size();
//         for(int i = n - 2; i >= 0; i--){
//             if(nums[i] < nums[i + 1]){
//                 index = i;
//                 break;
//             }
//         }
//         if(index == -1){
//             reverse(nums.begin(), nums.end());
//             return;
//         }
//         for(int i = n - 1; i > index; i--){
//             if(nums[i] > nums[index]){
//                 swap(nums[i], nums[index]);
//                 break;
//             }
//         }
//         reverse(nums.begin() + index + 1, nums.end());

// 73. Set Matrix Zeroes
// int col0 = 1;
//         int n = matrix.size();
//         int m = matrix[0].size();

//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 if(matrix[i][j] == 0){
//                     matrix[i][0] = 0;

//                    if(j != 0){
//                     matrix[0][j] = 0;
//                     }
//                     else{
//                     col0 = 0;
//                     }
//                 }
//             }
//         }
//         for(int i = 1; i < n; i++){
//             for(int j = 1; j < m; j++){
//                 if(matrix[i][j] != 0){
//                     if(matrix[0][j] == 0 || matrix[i][0] == 0){
//                         matrix[i][j] = 0;
//                     }
//                 }
//             }
//         }
//         if(matrix[0][0] == 0){
//             for(int j = 0; j <m; j++){
//                 matrix[0][j] = 0;
//             }
//         }
//         if(col0 == 0){
//             for(int i = 0; i < n; i++){
//                 matrix[i][0] = 0;
//             }
//         }

// 48. Rotate Image
// int n = matrix.size();
//         for(int i = 0; i < n - 1; i++){
//             for(int j = i + 1; j < n; j++){
//                 swap(matrix[i][j], matrix[j][i]);
//             }
//         }
//         for(int i = 0; i < n; i++){
//             reverse(matrix[i].begin(), matrix[i].end());
//         }

// 54. Spiral Matrix
// if (matrix.empty() || matrix[0].empty()) return {};

//     int m = matrix.size();
//     int n = matrix[0].size();
//     int left = 0, right = n - 1, top = 0, bottom = m - 1;
//     vector<int> ans;

//     while (top <= bottom && left <= right) {
//         for (int i = left; i <= right; i++) {
//             ans.push_back(matrix[top][i]);
//         }
//         top++;
//         for (int i = top; i <= bottom; i++) {
//             ans.push_back(matrix[i][right]);
//         }
//         right--;
//         if (top <= bottom) {
//             for (int i = right; i >= left; i--) {
//                 ans.push_back(matrix[bottom][i]);
//             }
//             bottom--;
//         }
//         if (left <= right) {
//             for (int i = bottom; i >= top; i--) {
//                 ans.push_back(matrix[i][left]);
//             }
//             left++;
//         }
//     }
//     return ans;

// 560. Subarray Sum Equals K
// map<int,int>mpp;
//         mpp[0] = 1;
//         int preSum = 0; int cnt = 0;
//         for(int i = 0; i < nums.size(); i++){
//             preSum += nums[i];
//             int remove = preSum - k;
//             cnt += mpp[remove];
//             mpp[preSum] += 1;
//         }
//         return cnt;