#include<bits/stdc++.h>
using namespace std;

//Q8. Merge 2 sorted arrays without using extra space
//brute
void merge(int arr1[], int arr2[], int n, int m) {
    long long arr3[n + m];
    int left = 0; 
    int right = 0;
    int index = 0;
    while(left < n && right < m) {
        if(arr1[left] < arr2[right]) {
            arr3[index] = arr1[left];
            left++;
            index++;
        }
        else {
            arr3[index] = arr2[right];
            right++;
            index++;
        }
    }
    while(left < n) {
        arr3[index++] = arr1[left++];
    }
    while(right < m) {
        arr3[index++] = arr2[right++];
    }

    for(int i = 0; i < n + m; i++) {
        if(i < n) {
            arr1[i] = arr3[i];
        }
        else {
            arr2[i - n] = arr3[i];
        }
    }
}
//tc ->O(n + m) + O(n + m) sc -> O(n + m)

//Optimal 1

