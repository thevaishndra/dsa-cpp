#include<bits/stdc++.h>
using namespace std;

//Q3. Check if the array is sorted
int checkSorted(int arr[], int n){
    for(int i = 1; i < n; i++){
        if(arr[i] <= arr[i-1]){//the next no. should be greater than previous 
            return false;
        } 
    }
    return true;
}
//tc -> O(n) //sc -> O(1)