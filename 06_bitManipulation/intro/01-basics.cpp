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
//Each bit is multiplied by 2 raised to the power of its position index
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
//The one's complement of a binary number is obtained by flipping all the bits
//(1101) base2 -> (0010) base2


//4. Twos complement
//The two's complement is obtained by taking the one's complement of a number and adding 1
//1s complement + 1 -> 0010 + 1 -> (0011) base2

//5. Bitwise Operators
// AND Operator (&) -> all true is true; 1 false is false
//1101 & 0111 -> 0101

//6. OR Operator (|) -> 1 true is true; all false is false
//1101 | 0111 -> 1111

//7. XOR Operator (^) -> if no. of 1s is odd then 1; if no. of 1s is even then 0
//1101 ^ 0111 -> 1010

//8. NOT Operator (~) -> Flips all bits of the number
//so, to do x = ~(s) -> 1.flip  2.Check -ve  3.If yes then Add 1 (2s complement) 3. Add -ve sign
//~5 -> ~0101 -> 1010 (It becomes a -ve no as msb is 1)
//1010 -> 0101 -> 0101 + 1 -> 0110 => 6 add -sign from og val => -6
//~(-6) -> ~0110 -> 1001 -> 1001 + 1 -> 1010 -> 5

//9. binary addition 1+1 = 10 -> write 0 carry 1; 1+1+1=11 -> write 1 carry 1

//10. Shift
//Right shift -> Shifts bits to the right, fills left with 0s
//13 >> 1 -> 1101 >> 1 -> 110 => 6  //13 >> 4 -> 1101 >> 4 -> 0000 => 0
//Left shift -> Shifts bits to the left, fills right with 0s
//13 << 1 -> 1101 << 1 -> 11010 => 16 + 8 + 2 = 26 (left shift by 1 is same as multiplying by 2)
//13 << 4 -> 1101 << 4 -> 11010000 => 16 + 64 + 128 => 208


//11. Swap 2 no. without a third variable
//temp = a; a = b; b = temp;
//XOR -> even no of 1s -> 0; odd no. of 1s -> 1;  5 ^ 5 = 0
//a = a ^ b; b = a ^ b => (a ^ b) ^ b => a; a = a ^ b => (a ^ b) ^ b => (a ^ b) ^ a => b


//12. Check if the ith bit is set or not
//using left shift -> (n & (1 << i) != 0)
//n = 13; i = 2;
//13 -> (1101) base2 
//1 << i => 1 << 2 => 100
//1101 & 100 => 0100 != 0; hence it's a set

//using right shift -> ((n >> i) & 1 != 0)
//n = 13; i = 2;
//13 -> 1101
//1101 >> 2 => 0011
//0011 & 1 = 0001 != 0; hence it's a set


//13. Set the ith bit 1
//n | (1 << i)
//n = 9; i = 2;
//9 -> (1001) base2 
//1 << 2 = 100
//1001 | 100 = 1101


//14. Set the ith bit 0
//n & ~(1 << i)
//n = 13; i = 2;
//13 -> (1101) base2
//1 << 2 -> 100
//1101 & ~100 -> 1101 & 011 -> 1001


//15. Toggle the ith bit means make 0 -> 1 and make 1 -> 0
//n ^ (1 << i)
//n = 13; i = 2;
//1101 ^ 100 -> 1001
//1001 ^ 100 -> 1101


//16. Binary Subtraction -> 1 - 1 = 0; 1 - 0 = 1; 0 - 1 = borrow 1 it becomes 10 - 1 = 1 

//17. Remove the last set bit (right most)
//n = 12 -> 1100 - 1 = 1011 last set bit becomes 0
//0 - 1 => 10 - 1 = 1;  0 - 1 => 1 - 0 = 1 because it was 0 it borrowed and has given so it doesnt become 10 but 1
//1 - 0 => 0 - 0 = 0 as it has also given and no need to borrow; 1 - 0 = 1
//n = 16 -> 10000 - 1 => 01111 last set bit becomes 0


//18. Check if the no. is a power of 2
//n = 16 -> 10000 -> 1 set bit so power of 2 
//n = 13 -> 1101 -> 3 set bit not power of 2
//(n & n - 1 == 0) it satisfies the condition then yes
//10000 & 01111 = 00000 == 0 power of 2
//1101 & 1100 = 1100 != 0 not a power of 2


//19. Count the no of set bits
//n = 13 -> 1101 -> 3 set bits
//how many times it doesn't gets divided by 2 it produces remainder as 1 and that is set bit we need to count
int countSetBits(int n) {
    int cnt = 0;
    while(n > 1) {
        if(n % 2 == 1) cnt += 1; // cnt += n & 1; n = n >> 1 // bit op are slightly faster and hence used in cp
        n = n / 2;
    }
    if (n == 1) cnt += 1;
    return cnt;
}
//builtin stl popcount(x) -> func that gives the set bit


//20. Divide 2 integers without using multiplication and division operator
//dividend = 22; divisor = 3; 22/3 = 7 ans
//3 + 3 + 3 + 3 + 3 + 3 + 3 = 21
int divide(int dividend, int divisor) {
        
        // Base case
        if(dividend == divisor) return 1;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(divisor == 1) return dividend;
        
        // Variable to store the sign of result
        bool isPositive = true;
        
        // Updating the sign of quotient
        if(dividend >= 0 && divisor < 0) 
            isPositive = false;
        else if(dividend < 0 && divisor > 0)
            isPositive = false;
            
        // Storing absolute dividend & divisor
        long long n = dividend;
        long long d = divisor;

        n = abs(n);
        d = abs(d);
        
        // Variable to store the answer and sum
        long long ans = 0, sum = 0;
        
        /* Looping while sum added to divisor is
        less than or equal to divisor */
        while(sum + d <= n) {
            
            // Increment the count
           ans++;
           // Update the sum
           sum += d;
        }
        
        // Handling overflowing condition
        if(ans > INT_MAX && isPositive) 
            return INT_MAX;
        if(ans > INT_MAX && !isPositive)
            return INT_MIN;
        
        /* Returning the quotient 
        with proper sign */
        return isPositive ? ans : -1*ans;
    }
//tc -> O(dividend)

 int divide(int dividend, int divisor) {
        
        // Base case
        if(dividend == divisor) return 1;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(divisor == 1) return dividend;
        
        // Variable to store the sign of result
        bool isPositive = true;
        
        // Updating the sign of quotient
        if(dividend >= 0 && divisor < 0) 
            isPositive = false;
        else if(dividend < 0 && divisor > 0)
            isPositive = false;
            
        // Storing absolute dividend & divisor
        long long n = dividend;
        long long d = divisor;

        n = abs(n);
        d = abs(d);
        
        // Variable to store the answer and sum
        long long ans = 0, sum = 0;
        
        /* Looping while sum added to divisor is
        less than or equal to divisor */
        while(sum + d <= n) {
            
            // Increment the count
           ans++;
           // Update the sum
           sum += d;
        }
        
        // Handling overflowing condition
        if(ans > INT_MAX && isPositive) 
            return INT_MAX;
        if(ans > INT_MAX && !isPositive)
            return INT_MIN;
        
        /* Returning the quotient 
        with proper sign */
        return isPositive ? ans : -1*ans;
    }