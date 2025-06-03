#include<bits/stdc++.h>
using namespace std;

//Q5. Left rotate the array by one place
void leftRotateOne(int arr[], int n){
    int temp = arr[0];//store first element in temp
    for(int i = 1; i < n; i++){
        arr[i-1] = arr[i];//values gets shifted to left one place
    }
    arr[n - 1] = temp;//place temp at the last position
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";//rotated array
    }
}
//tc -> O(n) sc -> O(1)