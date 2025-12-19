#include <bits/stdc++.h>
using namespace std;

//Q4. Lemonade Change
bool func(arr) {
    five = 0; ten = 0; twenty = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 5) five = five + 1;
        else if(arr[i] == 10) {
            if(five) {
                five -= 1;
                ten += 1;
            }
            else return false;
        }
        else {
            if(ten & five) {
                ten -= 1;
                five -= 1;
            }
            else if(five >= 3) {
                five -= 3;
            }
            else {
                return false;
            }
        }
    }
    return true;
}
//tc -> O(n)