#include<bits/stdc++.h>
using namespace std;

//Q9. Find missing and repeating no.
//Brute
vector<int>findMissingRepeatingNumbers(vector<int> &arr) {
    int n = arr.size();
    int missing = -1; 
    int repeating = -1;

    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(arr[j] == i){
                cnt++;
            }
        }
        if(cnt == 2) {
            repeating = i;
        }
        else if(cnt == 0) {
            missing = i;
        }
        if(repeating != - 1 && missing != -1) {
            break;
        }
    }
    return {repeating, missing};
}
//tc -> O(n^2) //sc -> O(1)

//Better
vector <int> findMissingRepeatingNumbers(vector<int> &arr) {
    int n =  arr.size();
    int hash[n + 1] = {0};

    for(int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    int repeating = -1;
    int missing = -1;

    for(int i = 0; i <= n; i++) {
        if(hash[i] == 2) {
            repeating = i;
        }
        else if (hash[i] == 0) {
            missing = i;
        }
        if(repeating != -1 && missing != -1) {
            break;
        }
    }
    return{repeating, missing};
}
//tc -> O(2n) //sc -> O(n)

//Optimal1
vector<int> findMissingRepeatingNumbers2(vector<int> &arr) {
    long long n = arr.size();

    long long sn = (n * (n + 1)) / 2;
    long long s2n = (n * (n + 1) * (2 * n + 1)) / 6;

    long long s = 0; long long s2 = 0;
    for(int i = 0; i < n; i++) {
        s += arr[i];
        s2 += (long long)arr[i] * (long long)arr[i];
    }

    long long val1 = s - sn;
    long long val2 = s2 - s2n;

    val2 = val2 / val1;

    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}
//tc -> O(n) //sc -> O(1)

//Optimal2 
vector<int> findMissingRepeatingNumbers3(vector<int> &arr) {
    int n = arr.size();
    int xorr = 0;

    for(int i = 0; i < n; i++) {
        xorr = xorr ^ arr[i];
        xorr = xorr ^ (i + 1);
    }

    int number = (xorr & ~(xorr - 1));

    int zero = 0;
    int one = 0;

    for(int i = 0; i < n; i++) {
        if((arr[i] & number) == 0) {
            one = one ^ arr[i];
        }
        else {
            zero = zero ^ arr[i];
        }
    }

    for(int i = 1; i <= n; i++) {
        if((i & number) != 0) {
            one = one ^ i;
        }
        else{
            zero = zero ^ i;
        }
    }

    int count = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == zero) {
            count++;
        }
    }

    if(count == 2){
        return {zero, one};
    }
    return {one, zero};
}
//tc -> O(n) //sc -> O(1)
