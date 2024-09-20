#include<bits/stdc++.h>
using namespace std;
//Array -> linear data structure, stores similar elements
// Q1. Largest element in array
//brute
int sortArray(vector<int> &arr){
    sort(arr.begin(), arr.end());//first sort the array in ascending order
    return arr[arr.size()-1];//print [size of array - 1]th index
}
//optimal
int findLargestElement(int arr[], int  n){
    int largest= arr[0];
    for(int i = 0; i < n; i++){//using a for loop to compare largest with elements of array
        if(arr[i] > largest)//if any value is greater than largest 
        largest = arr[i];//update the largest
    }
    return largest;
}

//Q2. Second largest element in array
//brute
int findSecondLargest(int arr[], int n){
    sort(arr, arr+n);//sort the array in ascending order
    int secondLargest = arr[0]; 
    int largest = arr[n - 1];
    for(int i = n-2; i >= 0; i++){//Finding the second element which is not equal to the largest element 
        if(arr[i] != largest)
        secondLargest = arr[i];
        break;
    }
    return secondLargest;
}
//better


//optimal
int findSecondLargest2(vector<int> &arr) {
        int largest = arr[0];
        int slargest = -1;
        
        for (int i = 1; i < arr.size(); i++){
            if(arr[i] > largest){
                slargest = largest;
                largest = arr[i];
            } else if (arr[i] < largest && arr[i] > slargest){
                slargest = arr[i];
            } 
        }
        return slargest;
        
    }

//Q3 Check if the array is sorted
int checkSorted(int arr[], int n){
    for(int i = 1; i < n; i++){
        if(arr[i] >= arr[i-1]){
            //we can leave it blank
        } else {
            return false;
        }
    }
    return true;
}

//Q4 Remove Duplicates from sorted array



