#include<bits/stdc++.h>
using namespace std;

//Q13. Find the no. that appears once & other numbers twice
//brute -> traverse an array , do a linear search and count if it appears more than once
int appearsOnce(vector<int> &arr, int n){
    for(int i = 0; i < n; i++){
        int num = arr[i];//pick current no
        int count = 0;

        for(int j = 0; j < n; j++){//count how many times it appears
            if(arr[j] == num){
                count++;
            }
        }
        if(count == 1){//if it appears only once, return it
            return num;
        }
    }
    return -1;//if there is no such number
}
//tc -> O(n * n) sc -> O(1) 

//better
int appearsOnce2(vector<int> &arr, int n){
    int maxi = arr[0];
    for(int i = 0; i < n; i++){
        maxi = max(maxi, arr[i]);
    }
    vector<int> hash(maxi + 1, 0);

    for(int i = 0; i < n; i++){
        hash[arr[i]]++;
    }
    for(int i = 0; i < n; i++){
        if(hash[arr[i]] == 1){
            return arr[i];
        }
    }
    return -1;
}
//tc -> sc ->

//