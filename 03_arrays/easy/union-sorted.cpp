#include<bits/stdc++.h>
using namespace std;

//Q9. Union of two sorted array
//Brute
vector <int> findUnion(int arr1[], int arr2[], int n, int m){
    set <int> st;
    for(int i = 0; i < n; i++){
        st.insert(arr1[i]);//add unique elements in set from array 1
    }
    for(int i = 0; i < m; i++){
        st.insert(arr2[i]);//add unique elements in set from array 2
    }
    vector <int> Union;
    for(auto &it : st){//&it -> reference to each element
        Union.push_back(it);//now putting back set elements in the new array called union
    }
}
//tc -> O(n1 log n) + O(n2 log n) + O(n1 + n2) sc -> O(n1 + n2) + O(n1 + n2) - once to store, and other time to return the answer

//Optimal
vector<int> findUnion2(int arr1[], int arr2[], int n, int m) {
    int i = 0, j = 0;//i -> pointer for arr1; j -> pointer for arr 2
    vector<int> Union;//a vector to store final union of both arrays
    
    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) {//starting with arr1[i]
            if (Union.empty() || Union.back() != arr1[i]) {//we check if union is empty or it is not equal to same element
                Union.push_back(arr1[i]);
            }
            i++;//arr1[i] has been processed
        } else {//starting with arr2[i]
            if (Union.empty() || Union.back() != arr2[j]) {
                Union.push_back(arr2[j]);
            }
            j++;//arr2[j] has been processed
        }
    }

    while (i < n) {//remaining elements for arr1
        if (Union.empty() || Union.back() != arr1[i]) {
            Union.push_back(arr1[i]);
        }
        i++;
    }

    while (j < m) {//remaining elements for arr2
        if (Union.empty() || Union.back() != arr2[j]) {
            Union.push_back(arr2[j]);
        }
        j++;
    }

    return Union;//final union of botha arrays
}
//tc -> O(n + m) sc -> O(n + m) in worst case if no duplicates exist