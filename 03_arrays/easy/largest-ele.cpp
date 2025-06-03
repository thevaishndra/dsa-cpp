#include<bits/stdc++.h>
using namespace std;
//Array -> linear data structure, stores similar elements

// Q1. Largest element in array
//brute
int sortArray(vector<int> &arr){
    sort(arr.begin(), arr.end());//first sort the array in ascending order
    return arr[arr.size()-1];//print [size of array - 1]th index
}
//tc -> O(n log n) //sc -> O(1)

//optimal
int findLargestElement(int arr[], int  n){
    int largest= arr[0];
    for(int i = 0; i < n; i++){//using a for loop to compare largest with elements of array
        if(arr[i] > largest)//if any value is greater than largest 
        largest = arr[i];//update the largest
    }
    return largest;
}
//tc -> O(n) //sc -> O(1)