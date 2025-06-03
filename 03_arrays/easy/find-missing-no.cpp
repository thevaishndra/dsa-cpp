#include<bits/stdc++.h>
using namespace std;

//Q11. Find missing no. in an array
//Brute
int missingNo(int arr[], int n){
    for(int i = 1; i <= n; i++){//traversing the original array of size n -> including missing no
        int flag = 0;//initially all are 0, if we found the same no while traversing we mark it as 1, if we found missing no it will be 0
        for(int j = 0; j < n-1; j++){//linear search in array
            if(arr[j] == i){//check if i is in the arr[]
                flag = 1;//missing no not found
                break;
            }
        }
        if(flag == 0){//missing no. found
            return i;
        }
    }
    return -1;//no missing no
}
//tc -> O(n) * O(n - 1) = O((n * n) - n) => O(n * n) sc -> O(1)

//Better
int missingNo2(vector<int> &arr, int n){
    int hash[n + 1] = {0};//hash array of size n + 1, initializing all values from 0
        for(int i = 0; i < n - 1; i++){//we are marking in hash
            hash[arr[i]]++;//if arr[i] = 1 then hash[1]++ means in hash it would be incremented by 1 ie, 0 -> 1
        }
        for(int i = 1; i <= n; i++){
            if(hash[i] == 0){//the no which doesn't gets marked as 1 in hash means that is not present in array
                return i;//missing nummber
            }
        }
        return -1;//if there is no missing number
}
//tc -> O(n) + O(n) = O(n) sc -> O(n)

//Optimal 1
int missingNo3(vector<int> &arr, int n){
    int sum = n * (n + 1) / 2;//sum of natural nos formula -> so actual sum including the missing no.
    int s2 = 0;
    for(int i = 0; i < n; i++){
        s2 += arr[i];// sum of nos present in array
    }
    return (sum - s2);//actual sum - sum of nos present in array gives missing no.
}
//tc -> O(n) sc -> O(1)

//Optimal 2
int missingNo4(vector<int> &arr, int n){
    int xor1 = 0; int xor2 = 0;
    for(int i = 0; i < n - 1; i++){
        xor2 ^= arr[i];// xor of all elements in array -> 1 ^ 2 ^ 4
        xor1 ^= (i + 1);//xor of all elements including missing no -> 1 ^ 2 ^ 3 ^ 4
    }
    return xor1 ^ xor2;//(1 ^ 2 ^ 4) ^ (1 ^ 2 ^ 3 ^ 4) = 3 -> missing no
}//a ^ a = 0; 0 ^ a = a -> all same nos will cancel out each other and then we get no itself by ^ with 0
//tc -> O(n) sc -> O(1)