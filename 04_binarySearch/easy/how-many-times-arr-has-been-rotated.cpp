#include<bits/stc++.h>
using namespace std;

//Q.8 Find out how many times array has been rotated
//Brute
int findHowManyTimesArrRotated(vector<int> &arr){
    int ans = INT_MAX; int index = -1;
    for(int i = 0; i <= arr.size(); i++){//traversal throughout
        if(arr[i] <= ans) {//compare it with ans
            ans = arr[i];//if it is smaller then update ans
            index = i;//in the end the index we get will be of the smallest index
        }
    }
    return index;
}
//tc -> O(n) //sc -> O(1)

//Optimal 
int findHowManyTimesArrRotated(vector<int> &arr){
    int low = 0; int high = arr.size() - 1; int ans = INT_MAX; int index = -1;
    while(low <= high){
        int mid = (low + high) /2;

        if(arr[low] <= arr[high]){
            if(arr[low] <= ans){
                index = low;
                ans = arr[low];
            }
            break;
        }

        //if left is sorted
        if(arr[low] <= arr[mid]){
            if(arr[low] <= ans){
                index = low;
                ans = arr[low];
            }
            low = mid + 1;
        }

        else{
            if(arr[mid] <= ans){
                index = mid;
                ans = arr[mid];
            }
            high = mid - 1;
        }
    } 
    return index;
}
//tc -> O(logn) //sc -> O(1)