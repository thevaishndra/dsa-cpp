#include<bits/stdc++.h>
using namespace std;
//4*4 square = *
void print1(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<< "*";
        }
        cout<<endl;//go to next line
    }
}
//left bottom right angle triangle = *
void print2 (int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){//till i except this everything is same
            cout<< "*";//1st line-> i star, 2nd line-> 2 star, it depends on i
        }
        cout<<endl;
    }
}
//left bottom right angle triangle = no. Read row wise-> 1, 1 2, 1 2 3, 1 2 3 4, 1 2 3 4 5
void print3(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=i; j++){//this we did in last ques to form a triangle
            cout<<j<<" ";//because 1st col, all no are 1, 2nd col all no. are 2....n columns
        }
        cout<<endl;
    }
}
//left bottom right angle triangle = no. Read row wise-> 1, 2 2, 3 3 3, 4 4 4 4, 5 5 5 5 5
void print4(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){//same as previos one
            cout<<i<<" ";//because 1st row, all no are 1, 2nd row all no. are 2....n rows
        }
        cout<<endl;
    }
}
//left top inverse right angle triangle = *
void print5(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n-i+1; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
//left top inverse right angle triangle = no. Read row wise -> 1 2 3 4 5, 1 2 3 4, 1 2 3, 1 2, 1
void print6(int n){
    for(int i = 0; i <= n; i++){
        for( int j = 1; j <= n-i+1; j++){
            cout<<j<<" ";//as we are printing row here, as all value in one row is same
        }
        cout<<endl;
    }
}
// perfect triangle in the bottom center having: space, star, space
void print7(int n){
    for(int i = 0; i <= n; i++){
        //space
        for(int j = 0; j <= n-i-1; j++){
            cout<<" ";
        }
        //star
        for(int j = 0; j <= (2*i+1); j++){
            cout<<"*";
        }
        //space
        for(int j = 0; j <= n-i-1; j++){
            cout<<" ";
        }
        cout<<endl;
    }
}