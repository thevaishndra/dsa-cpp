#include <bits/stdc++.h>
using namespace std;

//Selection sort -> select minimum and swap
void selectionSort(int arr[], int n){
    for(int i = 0; i <= n - 2; i++){
        int min = i;
        for(int j = i; j <= n-1; j++){
            if(arr[j] <= arr[min])
            min = j;
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

//Bubble sort -> push maximum to last by adjacent swap
void bubbleSort(int arr[], int n){
    for(int i = n - 1; i >= 0; i--){
        int didSwap = 0;
        for(int j = i; j <= i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                didSwap = 1;
             }
        }
        if(didSwap = 0) break;
    }
}

//Insertion sort -> Takes an element and places it in its correct order
void insertionSort (int arr[], int n){
    for(int i = 0; i <= n - 1; i++){
        int j = i;
        while(j > 0 && arr[j - 1] > arr[j]){
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

//Merge sort -> divide and conquer
void merge (vector<int> &arr, int low, int mid, int high){
    vector<int> temp;//temporary array
    int left = low;//starting index of left half of arr
    int right = mid + 1;//starting index of right half of arr
    
    while(left <= mid && right <= high){//storing elements in the temporary array in a sorted manner
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid){//if elements on the left half are still left
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high){//if elements on the right half are still left
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low; i <= high; i++){//transfering all elements from temporary to arr
        arr[i] = temp[i - low];
    }
}

int mergeSort(vector<int> &arr, int low, int high){
    if(low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);//left half
    mergeSort(arr, mid + 1, high);//right half
    merge(arr, low, mid, high);//merging sorted halves
}

//Quick sort ->