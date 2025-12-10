#include <bits/stdc++.h>
using namespace std;

//Q.4 Given an array of non-negative integers representation elevation of ground. Your task is to find the water that can be trapped after rain
//Brute
int trap(vector<int>& arr) {
    int n = arr.size();
    if (n <= 2) return 0;

    vector<int> leftMax(n), rightMax(n);

    // Build left max array
    leftMax[0] = arr[0];
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], arr[i]);
    }

    // Build right max array
    rightMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], arr[i]);
    }

    // Calculate trapped water
    int total = 0;
    for (int i = 0; i < n; i++) {
        int water = min(leftMax[i], rightMax[i]) - arr[i];
        if (water > 0) total += water;
    }

    return total;
}
//tc -> O(2n) + O(n) => O(3n) ~ O(n) //sc -> O(2n) for prefixMax and suffixMax arrays


//Optimal
int findTotal(vector<int>& arr) {
    int n = arr.size();
    if (n <= 2) return 0;

    int left = 0;
    int right = n - 1;

    int leftMax = 0, rightMax = 0;
    int total = 0;

    while (left <= right) {
        // Left side is smaller → process left
        if (arr[left] <= arr[right]) {
            if (arr[left] >= leftMax) {
                leftMax = arr[left];
            } else {
                total += leftMax - arr[left];
            }
            left++;
        }

        // Right side is smaller → process right
        else {
            if (arr[right] >= rightMax) {
                rightMax = arr[right];
            } else {
                total += rightMax - arr[right];
            }
            right--;
        }
    }

    return total;
}
//tc -> O(n) //sc -> O(1)