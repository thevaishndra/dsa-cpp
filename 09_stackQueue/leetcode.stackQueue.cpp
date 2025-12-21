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