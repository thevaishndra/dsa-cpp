#include<bits/stdc++.h>
using namespace std;

//Q4. Find the first and last occurence of x
// Brute -> Without using binary search
int findFirstAndLastOccurrence(vector<int> &arr, int x){
    int first = -1; int last = - 1;
    for(int i = 0; i <= arr.size() - 1; i++){
        while(arr[i] == x){
            if(first == -1) {
                first = i;
            }
            last = i;
        }
    }
    return {first, last};
}
//tc -> O(n) //sc -> O(1)

//Optimal -> using binary search
int findFirst(vector<int>&arr, int x){
    int low = 0; int high = arr.size() - 1; int first = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == x){
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] < x){
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return first;
}

int findLast(vector<int>&arr, int x){
    int low = 0; int high = arr.size() - 1; int last = -1
    while(Low <= high) {
        int mid = (low + high)/ 2;
        if(arr[mid] == x){
            last = mid;
            low = mid + 1;
        }
        else if(arr[mid] < x){
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return last;
}

int findFirstAndLast(vector<int> &arr, int x){
    int first = findFirst(arr, x);
    // if first == -1 return {-1, -1}; //element not found
    int last = findLast(arr, x);
    return {first, last};
    // return last- first + 1; //if the ques is to find count no of occurrences
}
