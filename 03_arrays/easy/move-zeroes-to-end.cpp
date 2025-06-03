#include<bits/stdc++.h>
using namespace std;

//Q7. Move all zeroes to the end of array
//Brute
int moveZeroesToEnd(int arr[], int n){
    vector <int> temp;//creating temporary initiating with 0

    for(int i = 0; i < n; i++){//putting all the non zero elements in temp
        if(arr[i] != 0){
            temp.push_back(arr[i]);
        }
    }
    int nonZero = temp.size();
    for(int i = 0; i < nonZero; i++){//now, from temp putting back non zeros in array in the starting
        arr[i] = temp[i];
    }
    for(int  i = nonZero; i < n; i++){//after the non zero size, putting zeros in the remaining array
        arr[i] = 0;
    }
    for(int i = 0; i < n; i++){//return array as it is an int type instead of vector
        cout<<arr[i]<<" ";
    }
}
//tc -> O(n) + O(x) + O(n - x) = O(2n) sc -> O(x) but O(n) in worst case

//Optimal
vector<int> moveZeroesToEnd2(int n, vector<int>arr){
    int j = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] = 0){
            j = i;//j is always going to be at 0
            break;
        }
    }//suppose, if j+1 is non zero eg: 1,we will swap it, now j is pointing 1 and i is pointing 0, 
    //but then we also do j++, then j is again at 0, and in loop i is iterating so i goes to next element adjacent to j
    for(int i = j + 1; i < n; i++){
        if(arr[i] != 0){
            swap(arr[i], arr[j]);//as we used vector we need not write code for swap
            j++;//only values are swapped-> 0s are going towards left and j is still pointing at 0 after j++ whereas i is still at j + 1 after i++
        }
    }
    return arr;//we need not write a loop to print array
}
//tc -> O(x) +O(n - x) = O(n) sc -> O(1)