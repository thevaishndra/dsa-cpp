#include <bits/stdc++.h>
using namespace std;

//
sum = 0;
for(int i = 0; i < n - 1; i++) {
    longest = arr[i]; smallest = arr[i];
    for(int j = i + 1; j < n - 1; j++) {
        largest = max(largest, arr[j]);
        smallest = min(smallest, arr[j]);
        sum = sum + (longest - smallest);
    }
}
sum of subarray min
sum of subarray max