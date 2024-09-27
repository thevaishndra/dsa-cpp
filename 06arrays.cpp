#include<bits/stdc++.h>
using namespace std;
//Array -> linear data structure, stores similar elements
//EASY QUES

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
//Brute
int removeDuplicates(int arr[], int n){
    set <int> set;
    for(int i = 0; i < n; i++){
        set.insert(arr[i]);
    }
    int index = 0;
    for (auto it : set) {
        arr[index] = it;
        index++;
    }
    
    return set.size();
}
//Optimal
int removeDuplicates2(int arr[], int n){
    int i = 0;
    for(int j = 0; j < n; j++){
        if(arr[j] != arr[i]){
            arr[i + 1] = arr[j];
            i++;
        }
    }
    return i + 1;
}


//Q5. Left rotate the array by one place
int leftRotateOne(int arr[], int n){
    int temp = arr[0];
    for(int i = 1; i < n; i++){
        arr[i-1] = arr[i];
    }
    arr[n - 1] = temp;
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}


//Q6. Left rotate the array by D places
//Brute
int leftRotateByD(int arr[], int n, int d){
    d = d % n;
    int temp[d];
    for(int i = d; i < n; i++){
        arr[i - d] = arr[i];
    }
    // int j = 0;
    // for(int i = n - d; i < n; i++){
    //     arr[i] = temp[j];
    //     j++;
    // } But instead of writing j we can do
    for(int i = n - d; i < n; i++){
        arr[i] = temp[i - (n - d)];//for ex: n-d = 4 so, i = 4, 4 - 4 = 0; which is the first index of temp
    }//then i = 5, 5 - 4 = 1; which is the second index of temp and so on
    //so, instaed of creating another pointer j we can print elements from temp by doing this
}
//Optimal
void reverse(int arr[], int start, int end){//Function to reverse elements if not using stl otherwise cpp stl has in-built reverse func
    while(start <= end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start ++; 
        end--;
    }
}
int leftRotateArrayByD2(int arr[], int n, int d){
  // Reverse first k elements
  reverse(arr, 0, d - 1);
  // Reverse last n-k elements
  reverse(arr, d, n - 1);
  // Reverse whole array
  reverse(arr, 0, n - 1);
}


//Q7. Move all zeroes to the end of array

//Q8. Linear search
//Q9. Union of two sorted array
//Q10. Intersection of two sorted array
//Q11. Find missing no. in an array
//Q12. Max consecutive ones
//Q13. Find the no. that appears once & other numbers twice
//Q14. Longest subarray with sum K [positives]
//Q15. Longest subarray with sum K [positives + negatives]








