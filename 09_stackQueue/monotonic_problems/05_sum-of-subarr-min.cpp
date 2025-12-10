#include <bits/stdc++.h>
using namespace std;

//Q.5 Given an array of integers arr of size n, calculate the sum of the minimum value in each (contiguous) subarray of arr. Since the result may be large, return the answer modulo 10⁹ +7
//Brute
sum = 0; mod = (int) (1e9+7)
for(int i = 0; i < n - 1; i++) {
    int mini = arr[i];
    for(int j = i; j < n - 1; j++) {
        mini = min(mini, arr[j]);
        sum = (sum + mini) % mod;
    }
    return sum;
}
//tc -> O(n^2) //sc -> O(1)


//Optimal
//