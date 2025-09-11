//Binary search leetcode ques

//704. Binary Search
// int search(vector<int>& nums, int target) {
//         int low = 0; int high = nums.size() - 1;
//         while(low <= high){
//            int mid = (low + high) / 2;
//            if (nums[mid] == target) return mid;
//            else if (target >= nums[mid]) low = mid + 1;
//            else high = mid - 1;
//         }
//         return -1;
// }


//35. Search Insert Position
//  int searchInsert(vector<int>& nums, int target) {
//         int low = 0; int high = nums.size() - 1; int ans = nums.size();
//         while(low <= high) {
//             int mid = (low + high) / 2;
//             if (nums[mid] >= target){
//                 ans = mid;
//                 high = mid - 1;
//             }
//             else low = mid + 1;
//         }
//         return ans;
//     }


// 34. Find First and Last Position of Element in Sorted Array
// int findFirst(vector<int>& nums, int target){
//             int low = 0; int high = nums.size() - 1; int first = -1;
//             while(low <= high){
//                 int mid = (low + high) / 2;
//                 if(nums[mid] == target){
//                     first = mid;
//                     high = mid - 1;
//                 }
//                 else if (nums[mid] < target){
//                     low = mid + 1;
//                 }
//                 else {
//                     high = mid - 1;
//                 }
//             }
//             return first;
//         }

//         int findLast(vector<int>& nums, int target){
//             int low = 0; int high = nums.size() - 1; int last = -1;
//             while(low <= high) {
//                int mid = (low + high)/ 2;
//                if(nums[mid] == target){
//                 last = mid;
//                 low = mid + 1;
//                }
//                else if(nums[mid] < target){
//                 low = mid + 1;
//                }
//                else {
//                 high = mid - 1;
//                }
//             }
//             return last;
//         }
//     vector<int> searchRange(vector<int>& nums, int target) {
//          int first = findFirst(nums, target);
//         int last = findLast(nums, target);
//         return {first, last};
//     }


// 33. Search in Rotated Sorted Array
// int search(vector<int>& nums, int target) {
//         int low = 0; int high = nums.size() - 1;
//         while(low <= high){
//             int mid = (low + high) / 2;
//             if(nums[mid] == target) return mid;

//             if(nums[low] <= nums[mid]){
//                 if(nums[low] <= target && target <= nums[mid]){
//                     high = mid - 1;
//                 }
//                 else {
//                     low = mid + 1;
//                 }
//             }

//             else {
//                 if(nums[mid] <= target && target <= nums[high]){
//                     low = mid + 1;
//                 } 
//                 else{
//                     high = mid - 1;
//                 }
//             }
//         }
//         return -1;
//     }


// 81. Search in Rotated Sorted Array II
//  bool search(vector<int>& nums, int target) {
//         int low = 0; int high = nums.size() - 1;

//         while(low <= high){
//              int mid = (low + high) /2;
//             if(nums[mid] == target) return true;

//         if(nums[low] == nums[mid] && nums[mid] == nums[high]){
//             low = low + 1;
//             high = high - 1;
//             continue;
//         }

//         if(nums[low] <= nums[mid]){
//             if(nums[low] <= target && target <= nums[mid]) {
//                 high = mid - 1;
//             }
//             else {
//                 low = mid + 1;
//             }
//         }

//         else{
//             if(nums[mid] <= target && target <= nums[high]){
//             low = mid + 1;
//             }
//             else {
//                 high = mid - 1;
//             }
//         }
//         }
//         return false;
//     }


// 153. Find Minimum in Rotated Sorted Array
// int findMin(vector<int>& nums) {
//         int low = 0; int high = nums.size() - 1; int ans = INT_MAX;
//         while(low <= high){
//             int mid = (low + high)/2;
//             if(nums[low] <= nums[high]){
//                 ans = min(ans, nums[low]);
//                 break;
//             }
//             if(nums[low] <= nums[mid]){
//                 ans = min(ans, nums[low]);
//                 low = mid + 1;
//             }
//             else {
//                 ans = min(ans, nums[mid]);
//                 high = mid - 1;
//             }
//         }
//         return ans;
//     }


// 540. Single Element in a Sorted Array
// int singleNonDuplicate(vector<int>& nums) {
//         if(nums.size() == 1) return nums[0];
//         if(nums[0] != nums[1]) return nums[0];
//         if (nums[nums.size() - 1] != nums[nums.size() - 2]) 
//         return nums[nums.size() - 1];

//         int low = 1; int high = nums.size() - 2;
//         while(low <= high){
//             int mid = (low + high) / 2;

//             if(nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
//             return nums[mid];

//             if((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
//               (mid % 2 == 0 && nums[mid] == nums[mid + 1])){
//                 low = mid + 1;
//               }
//               else {
//                 high = mid - 1;
//               }
//         } 
//         return -1;
//     }


// 162. Find Peak Element
// int findPeakElement(vector<int>& nums) {
//     int n = nums.size();
//     if(n == 1) return 0;
//     if(nums[0] > nums[1]) return 0;
//     if(nums[n - 1] > nums[n - 2]) return n - 1;

//     int low = 1, high = n - 2;
//     while(low <= high) {
//         int mid = (low + high) / 2;

//         if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) 
//             return mid;

//         if(nums[mid] < nums[mid + 1]) 
//             low = mid + 1;
//         else 
//             high = mid - 1;
//     }
//     return -1; 
// }