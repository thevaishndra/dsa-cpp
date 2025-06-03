#include<bits/stdc++.h>
using namespace std;

//Q4. Remove Duplicates from sorted array -imp
//Brute
int removeDuplicates(int arr[], int n){
    set <int> st;//set takes unique values and no repeats
    for(int i = 0; i < n; i++){
        st.insert(arr[i]);//collection of non repeating values
    }
    int index = 0;
    //copy elements from set to original array
    for (auto it : st) {//iterates over st taking it - iterator as each element
        arr[index] = it;//assign value from set to array
        index++;//move to next index
    }
    return st.size();//return number of unique elements
}
//tc -> O(n log n) //sc -> O(n)

//Optimal
int removeDuplicates2(int arr[], int n){
    int i = 0;//2 pointer approach
    for(int j = 1; j < n; j++){//i and j both starts with consecutive elements
        if(arr[j] != arr[i]){//they are same only j moves forward but they are not
            arr[i + 1] = arr[j];//then i + 1 position is same as value j is holding
            i++;// i + 1 position becomes i and j will move forward as it was doing
        }
    }
    return i + 1;//this will create an array with no duplicates till i + 1 position
}
//tc -> O(n) //sc -> O(1)