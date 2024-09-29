// 7. Reverse Integer
// int reverseN = 0;
//         while (x != 0) {
//             int lastDigit = x % 10;
//             if ((reverseN > INT_MAX / 10) || (reverseN < INT_MIN / 10)) {
//                 return 0;
//             }
//             reverseN = (reverseN * 10) + lastDigit;
//             x = x / 10;
//         }
//         return reverseN;

// 9. Palindrome Number
// int duplicate = x; long long reverseN = 0;
//         while ( x > 0){
//             int lastDigit = x % 10;
//             reverseN = (reverseN * 10) + lastDigit;
//             x = x/10;
//         }
//         if (duplicate == reverseN){
//             return true;
//         } else return false;

// 125. Valid Palindrome
// int start = 0;
//         int end = s.length() - 1;

//         while (start < end) {
//             while (start < end && !isalnum(s[start])) {
//                 start++;
//             }

//             while (start < end && !isalnum(s[end])) {
//                 end--;
//             }

//             if (tolower(s[start]) != tolower(s[end])) {
//                 return false;
//             }
//             start++;
//             end--;
//         }
//         return true;

// 509. Fibonacci Number
// if (n<=1) return n;
//         int last= fib(n-1);
//         int slast= fib(n-2);
//         return last+slast;


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
