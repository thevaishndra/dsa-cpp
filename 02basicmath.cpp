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
}/*optimized way 
log base 10 (456) + 1 almost equal to 3
Time Complexity -> O(log base 10 (N))*/
void print2(int n){
int count = (int)(log base 10(n)+ 1);
return count;
}


//Ques 2 -> Reverse a no.
void print3(int n){
    inr reverseN = 0;
    while(n > 0){
        int lastDigit = n % 10;// 456 % 10 = 6
        n = n / 10;// 456 / 10 = 45
        reverseN = (reverseN * 10) + lastdigit// 0* 10= 0 + 6 = 6
    }
    cout<<reverseN<<" ";
}

//Check palindrome no.
//The reverse of the no. is exactly same as the original no.
void print4(int n){
    int duplicate = n; int reverseN = 0;
    while(n > 0){
        int lastDigit = n % 10;
        n = n / 10;
        reverseN = (reverseN * 10) + lastDigit;
    }
    if (reverseN == duolicate) cout<<"True";
    else cout<<"False";
}

//Check Armstrong no.
// addition of any power, of all the digits of a no. results in no.itself
//eg -> 371 = 3 pow 3 + 7 pow 3 + 1 pow 3 = 371; 1634 = 1 pow 4 + 6 pow 4 + 3 pow + 4 pow 4
void print5(int n){
    int duplicate = n; int sum = 0;
    while(n > 0){
        int lastDigit = n % 10;
        count ++;
        sum = sum + pow(lastDigit, count);
        n = n / 10;
    }
    if (sum == duplicate) cout<<"True";
    else cout<<"False";
}

//Print all divisors
//brute-force approach
void print6(int n){
    for(int i =0; i <= n; i++){
        if(n % i == 0) cout<<i<<" ";
    }
}
//optimized way
void print7(int n) vector<int>ls{
    for( int i =0; i*i <= n; i++){//n = 36, looping from 6*6 <= 36, so that we don't take no. that comes again
        if(n % i == 0){//like 1 * 36 but not 36 * 1, 2* 18 but not 18 *2, etc
            ls.push_back(i);

            if(n/i != i){//we don't want to take 6 two times in 6*6=36
            ls.push_back(n/i);//adding in list a no. which is not like repetetive
        }
        } 
    }
    sort(ls.begin(), ls.end());//sorting in order
    for(auto it: ls) cout<<it<<" ";//printing it
}
