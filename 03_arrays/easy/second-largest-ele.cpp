#include<bits/stdc++.h>
using namespace std;

//Q2. Second largest element in array
//brute
int findSecondLargest(int arr[], int n){
    sort(arr, arr+n);//sort the array in ascending order
    int secondLargest = arr[0]; 
    int largest = arr[n - 1];//ofc, largest element will be in the last
    for(int i = n-2; i >= 0; i--){//Finding the second element which is not equal to the largest element 
        if(arr[i] != largest)//logically the element before largest is slargest but what if ie the same no. as largest
        secondLargest = arr[i];
        break;
    }
    return secondLargest;
}
//tc -> O(n log n) //sc -> O(1)

//better
int findSecondLargest2(vector<int> &arr){
    int largest = arr[0];//first pass: finding largest 
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
        return largest;
    }
    int slargest = -1;//if there are negatives in the array then we will take INT_MIN
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > slargest && arr[i] != largest){//element should be greater than slargest and not equal to largest
            slargest = arr[i];
        }
        return slargest;
    }
}
//tc -> O(n) + O(n) = O(n) //sc -> O(1)

//optimal
int findSecondLargest3(vector<int> &arr) {
    int largest = arr[0];
    int slargest = -1;
        
    for (int i = 1; i < arr.size(); i++){//finding largest & slargest both in one pass
        if(arr[i] > largest){
            slargest = largest;
            largest = arr[i];
        } else if (arr[i] < largest && arr[i] > slargest){
            slargest = arr[i];
        } 
    }
        return slargest; 
}
//tc -> O(n) //sc -> O(1)