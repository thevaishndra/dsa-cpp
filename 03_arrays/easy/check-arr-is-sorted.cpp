#include<bits/stdc++.h>
using namespace std;

//Q3. Check if the array is sorted
int checkSorted(int arr[], int n){
    for(int i = 1; i < n - 1; i++){//we do i = 1; i < n; as i-1 => 1-1 => 0 and we will check 0th index in next line
        if(arr[i] <= arr[i-1]){//the next no. should be greater than previous 
            return false;
        } 
    }
    return true;
}
//tc -> O(n) //sc -> O(1)

//if ques is sorted and rotated
bool checkSortedAndRotated(int arr[], int n){
    int count = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > arr[(i + 1) % n]){//if current no. is greater than next no. then it is not sorted eg [5,4]
            count++; //%n is used to wrap around the array, when we reach the end of the array, we need to compare to first element
        }
    }
    if(count > 1){
        return false;//if count is more than 1 then it is not sorted and rotated
    }
    return true;
    
}