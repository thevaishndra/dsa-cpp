#include<bits/stdc++.h>
using namespace std;

//Q5. Search an element in a sorted and rotated array 
//Brute -> linear search -> O(n)

//Optimal ->
int searchEleInRotatedSortedArr(vector<int> & arr, int target) {
    int low = 0; int high = arr.size() - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == target) return mid;

        if(arr[low] <= arr[mid]) {//left part is sorted
            if(arr[low] <= target && target <= arr[mid]){// if target is in right
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }

        else {//otherwise right part is sorted
            if(arr[mid] <= target <= arr[high]) {//if target is in left
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }
    return -1;
}
//tc -> O(logn) //sc ->O(1)