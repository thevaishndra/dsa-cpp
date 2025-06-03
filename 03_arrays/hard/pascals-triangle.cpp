#include<bits/stdc++.h>
using namespace std;

// Q1. Pascal's Triangle - each no. is sum of two numbers directly above it
// variation 1 : given row no. r and column no. c, print value at position (r,c)
// Brute - generate entire pascal's triangle and return the value

// Optimal
int nCr(int n, int r) {// here n = r - 1 and r = c - 1
    long long res = 1; 
    for (int i = 0; i < r; i++) {// n! / (r! * (n - r)!)
        res = res * (n - i); // we observed that the value of c is same as no. elements in numerator and denom
        res = res / (i + 1);// in numerator it goes backwards and in denom it goes forward
    }//eg -> 10C3 = 10 * 9 * 8 / 1 * 2* 3 
    return res;
}
int nCrElement(int r, int c) {
    int element = nCr(r - 1, c - 1);
    return element;
}
//tc -> O(r)  //sc -> O(1)

// variation 2 : given row no. n, print the nth row
// Brute - n is the row no. and c is the column no. , using the previous method print the row
int main () {
    int n;
    for(int c = 1; c <= n; c++) {
        cout << nCr(n - 1 , c - 1) << " ";// calling previous function
    }
}
//tc -> O(n * r) //sc -> O(1)

// Optimal 
int row(int n) {
    long long ans  = 1;
    cout << ans << "";//printing the first element that will always be 1
    for( int  i = 1; i < n; i++){
        ans = ans * (n - i);// currentElement =  previousElement * (rowNumber - colNumber) / columnNumber
        ans  = ans / i;// i is column here
        cout << ans << " ";//printing the next elements
    }
    cout << endl;
}
//tc -> O(n) //sc -> O(1)

//variation 3 : generate the whole pascal's triangle, It's not pattern printing no need to print spaces
// Brute - combination of variation 1 and 2
vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;
    for(int r = 1; r <= n; r++){
        vector<int> tempList;
        for(int c = 1; c <= r; c++) {
            tempList.push_back(nCr(r - 1, c - 1));
        }
        ans.push_back(tempList);
    }
    return ans;
}
//tc -> O(n * n * r) => O(n^3) //sc -> O(1)

//Optimal
vector <int> generateRow(int row) {
    long long ans = 1;
    vector <int> ansRow;
    ansRow.push_back(1);

    for(int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}
vector<vector<int>> pascalTriangle2(int n) {
    vector <vector<int>> ans;
    for(int row = 1; row <= n; row++) {
        ans.push_back(generateRow(row));
    }
    return ans;
}
//tc -> O(n^2) //sc -> O(1)
