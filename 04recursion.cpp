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
int sumOfNumFunc(int n){
if( n == 0) return 0;
return n + sumOfNumFunc(n-1);
}

//factorial of n
int factorial(int n){
if(n == 0) return 1;//to avoid getting 0
return n * factorial(n - 1);
}//TC -> O(N)  SC-> O(N)

//reverse an array (functional)
//using 2 parameter
int reverse(int l, int r, int arr[]){
    if ( l >= r) return;
    swap(arr[l], arr[r]);
    reverse(l + 1, r - 1);//array indices starts with 0
}
//functional
int reverseFunc(int i, int n, int arr[]){
    if(i >= n/2) return;
    swap(arr[i], arr[n-i-1]);//swapping b/w 0 index and last index
    return reverseFunc(i + 1, n, arr);
}

//check string is palindrome
int palindrome(int i, string& s){
    if( i >= s.length()/2) return true;
    if(s[i] != s.length()-i-1) return false;
    return palindrome(i + 1, s);
}

//check fibonacci no.
int fibonacci(int n){

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
    // cout<<sumOfNumFunc(n);
    // cout<<factorial(n);

    // int arr[n]; cin>>arr[n];
    // reverse(0, n-1, arr);
    //to print array we also have to iterate the array in for loop
    // reverseFunc(0, n, arr);

    // string s = "madam"; 
    // palindrome(0, s);

    fibonacci(n);
    return 0;
}