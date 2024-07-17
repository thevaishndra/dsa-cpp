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

//Insertion sort -> 