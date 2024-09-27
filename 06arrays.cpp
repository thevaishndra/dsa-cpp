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
    int largest = arr[n - 1];//ofc, largest element will be in the last
    for(int i = n-2; i >= 0; i++){//Finding the second element which is not equal to the largest element 
        if(arr[i] != largest)//logically the element before largest is slargest but what if ie the same no. as largest
        secondLargest = arr[i];
        break;
    }
    return secondLargest;
}
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
        if(arr[i] > slargest && arr[i] != largest){
            slargest = arr[i];
        }
        return slargest;
    }
}

//optimal
int findSecondLargest3(vector<int> &arr) {
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

//Q3. Check if the array is sorted
int checkSorted(int arr[], int n){
    for(int i = 1; i < n; i++){
        if(arr[i] >= arr[i-1]){//the next no. should be greater than previous 
            //we can leave it blank
        } else {
            return false;
        }
    }
    return true;
}

//Q4. Remove Duplicates from sorted array
//Q5. Left rotate the array by one place
//Q6. Left rotate the array by D places
//Q7. Move all zeroes to the end of array
//Q8. Linear search
//Q9. Union of two sorted array
//Q10. Intersection of two sorted array
//Q11. Find missing no. in an array
//Q12. Max consecutive ones
//Q13. Find the no. that appears once & other numbers twice
//Q14. Longest subarray with sum K [positives]
//Q15. Longest subarray with sum K [positives + negatives]








