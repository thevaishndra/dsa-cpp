#include <bits/stdc++.h>
using namespace std;

//Print name n times (if n = 3)
void printName(int i, int n){
    if(i > n) return;//base condition -> it works till 3,3 when it becomes 4,3 it stops and prints name 3 times
    cout<<"Vaish";
    printName(i + 1, n);//we are incrementing i by 1
}

//Print linearly from 1 to n
void print1toN(int i, int n){
    if(i > n) return;
    cout<<i;//printing the no.
    print1toN(i + 1, n);
}

//Print from n to 1
void printNto1(int i, int n){
    if(i < n) return;//when it becomes 0,3 it stops
    cout<<i;//prints -> 3, 2, 1
    printNto1(i-1, n);//3,3 => 2,3  1,3  0,3
}

//print 1 to n (backtrack)
void print1toNbt(int i, int n){
    if(i > n) return;
    print1toNbt(i-1, n);//see what we are paassing 
    cout<<i;//the last no. we will be printing first
}

//print n to 1 (backtrack)
void printNto1bt(int i, int n){
    if(i > n) return;
    printNto1bt(i+1, n);
    cout<<i;
}

//sum of first n no.
//parameterised
void sumOfNum(int i, int sum){
    if(i < 1){
        cout<<sum;
        return;
    }
    sumOfNum(i - 1, sum + i);
}

//functional
int sumOfNumFunc(){

}

int main(){
    int n;
    cin>>n;
    // printName(1, n);
    // print1toN(1, n);
    // printNto1(n, n);//passing 3,3
    // print1toNbt(n, n);
    // printNto1bt(1, n);
    // sumOfNum(n, 0);
    cout<<sumOfNumFunc();
}