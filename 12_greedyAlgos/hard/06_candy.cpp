#include <bits/stdc++.h>
using namespace std;

//Q6. Candy
func(rating[]) {
    left[n]; right[n];
    left[0] = 1; right[n-1] = 1;

    for(int i = 1; i < n - 1; i++) {
        if(rating[i] > rating[i - 1]) {
            left[i] = left[i - 1] + 1;
        } else {
            left[i] = 1;
        }
    }
    for(int i = n - 2; i >= 0; i--) {
        if(rating[i] > rating[i + 1]) {
            right[i] = right[i + 1] + 1;
        } else {
            right[i] = 1;
        }
    }
    int sum = 0;
    for(int i = 0; i < n - 1; i++) {
        sum += max(left[i], right[i]);
    }
    return sum;
} 
//tc -> O(3n) //sc -> O(2n)

//better
func(rating[]) {
    left[n]; right[n];
    left[0] = 1; right[n-1] = 1;

    for(int i = 1; i < n - 1; i++) {
        if(rating[i] > rating[i - 1]) {
            left[i] = left[i - 1] + 1;
        } else {
            left[i] = 1;
        }
    }
curr = 1; right = 1; sum = max(1, left(n - 1));
for(int i = n - 2; i >= 0; i--) {
    if(rating[i] > rating[i + 1]) {
        curr = right + 1;
        right = arr;
    } 
    else {
        curr = 1;
        sum = sum + max(left[i], curr);
    }
    return sum;
}
}

//optimal
func(ratings) {
    sum = 1; i = 1;
    while(i < n) {
        if(ratings[i] == ratings[i - 1]) {
            sum = sum + 1;
            i++;
            continue;
        }
        peak = 1;
    }
    while(i < n && ratings[i] > ratings[i - 1]) {
        peak += 1;
        sum += peak;
        i++;
    }
    down = 1;
    while(i < n && ratings[i] < ratings[i - 1]) {
        sum += down;
        i++;
        down++;
    }
    if(down > peak) {
        sum += down - peak;
    }
    return sum;
}
//tc -> O(n) //sc -> O(1)