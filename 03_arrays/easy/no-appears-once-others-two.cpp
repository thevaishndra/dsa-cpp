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
//tc -> O(n) + O(n) + O(n) => O(3n) sc -> O(input)

//better 2
int appearsOnce3(vector<int> &arr, int n) {

    //size of the array:
    int n = arr.size();

    // Declare the hashmap.
    // And hash the given array:
    map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

    //Find the single element and return the answer:
    for (auto it : mpp) {
        if (it.second == 1)
            return it.first;
    }

    //This line will never execute
    //if the array contains a single element.
    return -1;
}
//tc -> O(N*logM) + O(M), where M = size of the map i.e. M = (N/2)+1. N = size of the array
//sc -> O(M) as we are using a map data structure. Here M = size of the map i.e. M = (N/2)+1

//optimal
int appearsOnce4(vector<int> &arr, int n) {
    //size of the array:
    int n = arr.size();

    // XOR all the elements:
    int xorr = 0;
    for (int i = 0; i < n; i++) {
        xorr = xorr ^ arr[i];
    }
    return xorr;
}
//tc -> O(n) //sc -> O(1)