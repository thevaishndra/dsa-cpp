#include <bits/stdc++.h>
using namespace std;

//Q.4 Trapping rain water 
//Given an array of non-negative integers representation elevation of ground. Your task is to find the water that can be trapped after rain
//Brute
//For each bar in the array, find the maximum height bar on its left
//Find the maximum height bar on its right
//Calculate the trapped water on the current bar as min(maxLeft, maxRight) - current height
//Sum all trapped water from each bar to get the total amount of trapped water
int trap(vector<int>& arr) {
    int n = arr.size();
    if (n <= 2) return 0;//With 0, 1, or 2 bars, water cannot be trapped

    //highest bar from index 0 to i -> leftMax
    //highest bar from index i to n-1 -> rightMax
    vector<int> leftMax(n), rightMax(n);

    // Build left max array -> always stores the highest bar seen so far from the left
    leftMax[0] = arr[0];//At index 0, there are no elements to left, So max till index 0 is the element itself
    for (int i = 1; i < n; i++) {//Because index 0 is already handled, We move left → right
        leftMax[i] = max(leftMax[i - 1], arr[i]);//what is tallest bar so far?
    }//between tallest till previous index, current bar

    // Build right max array -> always stores the highest bar seen so far from the right
    rightMax[n - 1] = arr[n - 1];//At index n - 1, there are no elements to right, So max till index n - 1 is the element itself
    for (int i = n - 2; i >= 0; i--) {//because last index is handled, we move right -> left
        rightMax[i] = max(rightMax[i + 1], arr[i]);//what is tallest bar so far?
    }//between current bar and prev bar to its right

    // Calculate trapped water
    int total = 0;
    for (int i = 0; i < n; i++) {
        int water = min(leftMax[i], rightMax[i]) - arr[i];//the formula to get trapped water
        if (water > 0) total += water;//adding water to tatal after every bar
    }

    return total;
}
//arr = [3, 0, 0, 2, 0, 4]
//leftMax[0] = 3; [1] = max[3,0] = 3; [2] = max[3, 0] = 3; [3] = max[3, 2] = 3; [4] = max[3, 0] = 3; [5] = max[3, 4] = 4
//rightMax[5] = 4; [4] = max[4, 0] = 4; [3] = max[4, 2] = 4; [2] = max[4, 0] = 4; [1] = max[4, 0] = 4; [0] = max[4, 3] = 4
//leftMax =  [3, 3, 3, 3, 3, 4]; rightMax = [4, 4, 4, 4, 4, 4]
//i = 0 -> water = min(3, 4) - 3 = 0; total = 0;
//i = 1 -> water = min(3, 4) - 0 = 3; total = 3;
//i = 2 -> water = min(3, 4) - 0 = 3; total = 6;
//i = 3 -> water = min(3, 4) - 2 = 1; total = 7;
//i = 4 -> water = min(3, 4) - 0 = 3; total = 10;
//i = 5 -> water = min(4, 4) - 4 = 0; total = 10;
//tc -> O(2n) + O(n) => O(3n) ~ O(n) //sc -> O(2n) for leftMax and rightMax arrays


//Optimal
// min(max on left, max on right) − height
int findTotal(vector<int>& arr) {
    int n = arr.size();
    if (n <= 2) return 0;//With 0, 1, or 2 bars, water cannot be trapped

    int left = 0;//start
    int right = n - 1;//end

    int leftMax = 0;//highest bar seen from left
    int rightMax = 0;//highest bar seen from right
    int total = 0;

    while (left <= right) {
        // Left side is smaller → right side is guaranteed to have a bar ≥ current left -> process left
        if (arr[left] <= arr[right]) {//The smaller side decides water level
            if (arr[left] >= leftMax) {//If current bar is taller than previous calculated max
                leftMax = arr[left];//Update leftMax
            } else {//if Current bar is shorter than leftMax
                total += leftMax - arr[left];//add trapped water to total
            }
            left++;//move forward
        }

        // Right side is smaller → process right
        else {
            if (arr[right] >= rightMax) {//if current bar is taller than previous calculated max
                rightMax = arr[right];//Update rightMax
            } else {
                total += rightMax - arr[right];//add trapped water to total
            }
            right--;//move forward
        }
    }
    return total;
}
//arr = [3, 0, 0, 2, 0, 4]
//left = 0; right = 5; leftMax = 0; rightMax = 0; total = 0;
//3 <= 4 yes -> 3 >= 0 yes-> leftMax = 3; left = 1
//0 <= 4 yes -> 0 >= 3 no -> total = 3 - 0 => 3; left = 2;
//0 <= 4 yes -> 0 >= 3 no -> total = 3 - 0 => 3 => 3 + 3 = 6; left = 3;
//2 <= 4 yes -> 2 >= 3 no -> total = 3 - 2 => 1 => 6 + 1 = 7; left = 4
//0 <= 4 yes -> 0 >= 3 no -> total = 3 - 0 => 3 => 7 + 3 = 10; left = 5
//4 <= 4 yes -> 4 >= 3 yes -> rightMax = 4; right = 4
//left <= right condition fails -> exit loop; total = 10
//tc -> O(n) //sc -> O(1)