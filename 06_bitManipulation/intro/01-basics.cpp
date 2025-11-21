#include <bits/stdc++.h>
using namespace std;

//1. Conversion Decimal base(10) to Binary base(2)
// 7 base(10) -> 111 base(2)
// 7 / 2 = 3 remainder -> 1
// 3 / 2 = 1 remainder -> 1
// 1 / 2 = 0 remainder -> 1
//read remainders from bottom to top
//binary of 7 is 111

string convert2Binary(int n) {
    if (n == 0) return "0";

    string res = "";

    while(n > 0) {
        int bit = n % 2;        // last binary digit
        res += (bit + '0');     // convert 0/1 to char
        n = n / 2;
    }
    reverse(res.begin(), res.end());
    return res;
}
//tc -> log base(2)n -> when things are divided by 2 //sc -> log base(2)n ->no. of remainders


//2. Conersion Binary base(2) to Decimal base(10)
//start with right most bit called as least significant bit
//Each bit is multiplied by 2 raised to the power of its position index.
//1 * 2^0 + 1 * 2^1 + 1 * 2^2 = 1 + 2 + 4 => 7
//decimal of 111 is 7

int convert2Decimal (string x) {
    int p2 = 1;
    int num = 0;

    // start from last index (LSB)
    for(int i = x.length() - 1; i >= 0; i--) {
         if (x[i] == '1') {
            num += p2;
        }
        p2 *= 2;
    }
    return num;
}
//tc -> O(len) //sc -> O(1)

//3. Ones complement
//The one's complement of a binary number is obtained by flipping all the bits.
//(1101) base2 -> (0010) base2


//4. Twos complement
//The two's complement is obtained by taking the one's complement of a number and adding 1.
//1s complement + 1 -> 0010 + 1 -> (0011) base2

//5. Bitwise Operators
// AND Operator (&) -> all true is true; 1 false is false
//1101 & 0111 -> 0101

// OR Operator (|) -> 1 true is true; all false is false
//1101 | 0111 -> 1111

//XOR Operator (^) -> if no. of 1s is odd then 1; if no. of 1s is odd then 0
//1101 ^ 0111 -> 1010

//Shift