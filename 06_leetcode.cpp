// 7. Reverse Integer
// int reverseN = 0;
//         while (x != 0) {
//             int lastDigit = x % 10;
//             if ((reverseN > INT_MAX / 10) || (reverseN < INT_MIN / 10)) {
//                 return 0;
//             }
//             reverseN = (reverseN * 10) + lastDigit;
//             x = x / 10;
//         }
//         return reverseN;

// 9. Palindrome Number
// int duplicate = x; long long reverseN = 0;
//         while ( x > 0){
//             int lastDigit = x % 10;
//             reverseN = (reverseN * 10) + lastDigit;
//             x = x/10;
//         }
//         if (duplicate == reverseN){
//             return true;
//         } else return false;

// 125. Valid Palindrome
// int start = 0;
//         int end = s.length() - 1;

//         while (start < end) {
//             while (start < end && !isalnum(s[start])) {
//                 start++;
//             }

//             while (start < end && !isalnum(s[end])) {
//                 end--;
//             }

//             if (tolower(s[start]) != tolower(s[end])) {
//                 return false;
//             }
//             start++;
//             end--;
//         }
//         return true;

// 509. Fibonacci Number
// if (n<=1) return n;
//         int last= fib(n-1);
//         int slast= fib(n-2);
//         return last+slast;