#include <bits/stdc++.h>
using namespace std;

//A celebrity is a person who is known by everyone else at the party but does not know anyone in return. Given a square matrix M of size N x N where M[i][j] is 1 if person i knows person j, and 0 otherwise, determine if there is a celebrity at the party. Return the index of the celebrity or -1 if no such person exists.
//brute
func(mat[][]){
    knowMe[N], Iknow[n];
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1; j ++){
            if(mat[i][j] = 1){
                knowMe[j]++;
                Iknow[i]++;
            }
        }
    }
    for(int i = 0; i < n - 1; i++) {
        if(knowMe[i] == n - 1 && Iknow[i] == 0){
            return -1;
        }
    }
}
//tc -> O(n * n) + O(n) //sc -> O(2n)


//optimal
func(mat[][]) {
    top = 0; down = n -1;
    while(top(down)) {
        if(mat[top][down] == 1) {
            top = top + 1;
        }
        else if(mat[down][top] == 1){
            down = down - 1;
        }
        else {
            top--;
            down--;
        }
    }
    if(top > down) return - 1;
    for(int i = 0; i < n - 1; i++){
        if(mat[top][i] == 0) && (mat[i][top] == 1)
        else return - 1;
    }
    return top;
}