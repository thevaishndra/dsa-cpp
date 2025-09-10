#include<bits/stdc++.h>
using namespace std;

//Q6. Search element in rotated sorted arr [duplicates]
// Brute -> linear search -> O(n)

//Optimal
int searchEleInRotatedSortedArr(vector<int> &arr, int target) {
    int low = 0; int high = arr.size() - 1;
    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == target) return true;

        if (arr[low] == arr[mid] && arr[mid] == arr[high]){
            low = low + 1;
            high = high - 1;
            continue;
        }
        if(arr[low] <= arr[mid]) {
            if(arr[low] <= target && target <= arr[mid]){
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        else {
            if(arr[mid] <= target && target <= arr[high]){
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }
}
//tc -> O(logn) for best and avg case O(n/2) for worst case //sc -> O(1)