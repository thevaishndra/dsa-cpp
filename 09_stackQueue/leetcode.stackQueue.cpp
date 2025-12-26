//496. Next Greater Element I
// vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         unordered_map<int, int> mp;
//         stack<int> st;
//         for(int i = nums2.size() - 1; i >= 0; i--) {
//             while(!st.empty() && st.top() <= nums2[i]) {
//                 st.pop();
//             }
//             if(st.empty()) {
//                 mp[nums2[i]] = -1;
//             }
//             else {
//                 mp[nums2[i]] = st.top();
//             }
//             st.push(nums2[i]);
//         }
//         vector<int> ans;
//         for(int x : nums1) {
//             ans.push_back(mp[x]);
//         }
//         return ans;
//     }


//503. Next Greater Element II
// vector<int> nextGreaterElements(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> nge(n, -1);
//         stack<int> st;
//         for(int i = 2 * n - 1; i >= 0; i--) {
//             int idx = i % n;
//             while(!st.empty() && st.top() <= nums[idx]) {
//                 st.pop();
//             }
//             if(i < n) {
//                 nge[idx] = st.empty() ? -1 : st.top();
//             }
//             st.push(nums[idx]);
//         }
//         return nge;
//     }


//42. Trapping Rain Water
// int trap(vector<int>& height) {
//         if (height.size() <= 2) return 0;
//         int left = 0; int right = height.size() - 1; 
//         int leftMax = 0; int rightMax = 0; int total = 0;
//         while(left <= right) {
//             if(height[left] <= height[right]) {
//                 if(height[left] >= leftMax) {
//                     leftMax = height[left];
//                 }
//                 else {
//                     total += leftMax - height[left];
//                 }
//                 left++;
//             }
//             else {
//                 if(height[right] >= rightMax) {
//                     rightMax = height[right];
//                 }
//                 else {
//                     total += rightMax - height[right];
//                 }
//                 right--;
//             }
//         }
//         return total;
//     }


// 735. Asteroid Collision
// vector<int> asteroidCollision(vector<int>& asteroids) {
//         list<int> st;
//         for(int i = 0; i < asteroids.size(); i++) {
//             if(asteroids[i] > 0) {
//                 st.push_back(asteroids[i]);
//             }
//             else {
//                 while(!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])){
//                     st.pop_back();
//                 }
//                 if(!st.empty() && st.back() == abs(asteroids[i])) {
//                     st.pop_back();
//                 }
//                 else if (st.empty() || st.back() < 0) {
//                     st.push_back(asteroids[i]);
//                 }
//             }
//         }
//         return vector<int>(st.begin(), st.end());
//     }


// 402. Remove K Digits
// string removeKdigits(string num, int k) {
//         stack<char> st;
//         for (int i = 0; i < num.size(); i++) {
//         while (!st.empty() && k > 0 && st.top() > num[i]) {
//             st.pop();
//             k--;
//         }
//         st.push(num[i]);
//         }
//         while (k > 0 && !st.empty()) {
//         st.pop();
//         k--;
//         }
//         string res = "";
//         while (!st.empty()) {
//         res.push_back(st.top());
//         st.pop();
//         }
//         reverse(res.begin(), res.end());
//         while (!res.empty() && res[0] == '0') {
//         res.erase(res.begin());
//         }
//         if (res.empty()) return "0";
//         return res;
//     }