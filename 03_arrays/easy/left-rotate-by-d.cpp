#include<bits/stdc++.h>
using namespace std;

//Q6. Left rotate the array by D places
//Brute
int leftRotateByD(int arr[], int n, int d){
    d = d % n;//handles rotation greater than size of array, no of rotations is reduced to array bounds
    int temp[d];//stores first d elements
    for(int i = d; i < n; i++){//shift rest of array by d positions
        arr[i - d] = arr[i];
    }
    // int j = 0;
    // for(int i = n - d; i < n; i++){
    //     arr[i] = temp[j];
    //     j++;
    // } But instead of writing j we can do
    for(int i = n - d; i < n; i++){//copy the elements from temp[] to the end of arr[]
        arr[i] = temp[i - (n - d)];//indexing of temp - 0, 1, 2 - so that the elements on those index can be copied to array
    }
}
//tc -> O(1) + O(d) + O(n - d) + O(d) = O(n - d + d) => O(n + d)  sc -> O(d) + O(1) = O(d)

//Optimal
void reverse(int arr[], int start, int end){//Function to reverse elements if not using stl otherwise cpp stl has in-built reverse func
    while(start <= end){//1,2,3,4,5 -> 5,2,3,4,1 -> 5,4,3,2,1 -> reverses in this way
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start ++; 
        end--;
    }
}
int leftRotateArrayByD2(int arr[], int n, int d){//function for rotation
  // Reverse first d elements
  reverse(arr, 0, d - 1);
  // Reverse last n-d elements
  reverse(arr, d, n - 1);
  // Reverse whole array
  reverse(arr, 0, n - 1);
}
//in right rotation, reverse last d elements, first n - d elements, reverse whole array
//tc -> O(d) + O(n - d) + O(n) = O(2n) sc -> O(1)
//tc slightly increased