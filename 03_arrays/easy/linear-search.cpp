#include<bits/stdc++.h>
using namespace std;

//Q8. Linear search
int linearSearch(int arr[], int n, int num){
    for(int i = 0; i < n; i++){
        if(arr[i] == num){//if element is equal to the given num, return i otherwise return -1
        return i;
        }
    }
      return -1;
}
//tc -> O(n) sc -> O(1)