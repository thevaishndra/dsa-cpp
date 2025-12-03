#include <bits/stdc++.h>
using namespace std;

//Q1. Count no of bits to be flipped to convert A to B
int bitsFlip(int start, int goal) {
    int ans = start ^ goal;
    int cnt = 0;
    for(int i = 0; i < 32; i++) {
        count += (num & 1);
        num >> num >> 1;
    }
    return count;
}
//tc -> O(32) -> O(1) //sc -> O(1)