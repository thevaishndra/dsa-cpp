#include<bits/stdc++.h>
using namespace std;
//BASIC MATHS -> 7789 % 10 = 9; 7789 / 10 = 778

//Ques 1 -> Count no. of digits
void print1(int n){
    int count = 0;
    while(n > 0){//456 > 0 then keep on doing till it becomes 0
        int lastDigit = n % 10;// ld = 456 % 10 = 6
        count ++;// +1
        n = n/10;// n = 456/10 =45
    }
    cout<<count<<" ";
}/*another way to do this:
log base 10 (456) + 1 almost equal to 3
int count(int n){
int count = (int)(log base 10(n)+ 1);
return count;
Time Complexity -> O(log base 10 (N))}*/

//Ques 2 -> Reverse a no.
void print2(int n){
    
}
