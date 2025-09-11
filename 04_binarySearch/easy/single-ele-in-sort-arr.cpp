#include <bits/stdc++.h>
using namespace std;

//Q.9 Find single element in a sorted array
//brute
int singleElement1(vector<int> &arr){
    if(arr.size() == 1) return arr[0];

    for(int i = 0; i < arr.size(); i++){
        //check for first element
        if(i == 0){
            if(arr[i] != arr[i + 1]){
                return arr[i];
            }
        }
        //check for last element
        else if(i == arr.size() - 1){
            if(arr[i] != arr[i - 1]){
                return arr[i];
            }
        }
        //check for the elements
        else {//current element should not be equal to previos element and next element
            if(arr[i] != arr[i - 1] && arr[i] != arr[i + 1]){
                return arr[i];
            }
        }
    }
    return -1
}
//tc -> O(n) //sc -> O(1)

//brute 2
int singleElement2(vector<int> &arr){
    int ans = 0;
    for(int i = 0; i < arr.size(); i++) {
        ans = ans ^ arr[i];//xor of same no will give 0 and we will be left with one no that is single
    }
    return ans;
}
//tc -> O(n) //sc -> O(1)

//optimal -> binary search
int singleElement3(vector<int> &arr){}
