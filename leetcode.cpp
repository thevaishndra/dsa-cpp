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