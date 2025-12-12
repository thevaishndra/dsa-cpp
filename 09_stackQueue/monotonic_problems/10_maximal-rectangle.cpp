#include <bits/stdc++.h>
using namespace std;

//Given a m x n binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
//Brute
func(maat[][]){
    n m maxArea = 0;
    for(int j = 0; j < m - 1; j++) {
        sum = 0;
        for(int i = 0; i < n - 1; i++) {
            sum += mat[i][j];
            if(mat[i][j] == 0) sum = 0;
            pSum[i][j] = sum
        }
    }
    for(int i = 0; i < n - 1; i++) {
            maxArea = max(maxArea, lHis(pSum[i]));
        }
        return maxArea;
}
//tc -> O(m * n) + O(n * 2m) //sc -> O(n * m) + O(n)