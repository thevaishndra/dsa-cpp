#include<bits/stdc++.h>
using namespace std;

//Q12. Max consecutive ones
int maxConsecutiveOnes(vector<int> &arr, int n){
    int count = 0; int maxi = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 1){// if element is 1 in array
            count++;// we will mark it in count as no of times it is 1
            maxi = max(maxi, count);//tracking the maximum count of consecutives we get after incrementing the count everytime
        } else {// as we get i = 0, it will break the count and changes it to 1 again, so count again the consecutive 1s
            count = 0;
        }
    }
    return maxi;//count of max consecutive 1s
}
//tc -> O(n) sc -> O(1)