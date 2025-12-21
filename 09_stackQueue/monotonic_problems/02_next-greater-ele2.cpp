#include <bits/stdc++.h>
using namespace std;

//Q2. Next greater element 2
//The next greater element for an element x is the first element greater than x that we come across while traversing the array in a clockwise manner.
//arr = [2, 10, 12, 1 ,11] nge =[10, 12, -1, 11, 12] -> don't just look right side, go circular
//brute
vector<int> nextGreaterCircular(vector<int> &arr) {
    int n = arr.size();
    vector<int> nge(n, -1);
    
    for (int i = 0; i < n; i++) {//i is the index of current ele it stays j seraches for nge
        for (int j = i + 1; j < i + n; j++) { //search circularly
            int ind = j % n;//converts linear index into circular index
            //j = 5; n = 5; 5 % 5 = 0
            //j = 6; n = 5; 6 % 5 = 1
            //after reaching end, it wraps to start
            if (arr[ind] > arr[i]) {//if greater ele is found then break
                nge[i] = arr[ind];
                break;
            }
        }
    }
    return nge;
}
//arr = [1, 2, 1] n = 3
//i = 0; j = 1; ind = 1 % 3 => 1; arr[1] > arr[0] => 2 > 1 => nge[0] = 2
//i = 1; j = 2; ind = 2 % 3 => 2; arr[2] > arr[1] => 1 > 2 => no
//i = 1; j = 3; ind = 3 % 3 => 0; arr[0] > arr[1] => 1 > 2 => no
//i = 1; j = 4; ind = 4 % 3 => 1; arr[1] > arr[1] => 2 > 2 => no => nge[1] = -1
//i = 2; j = 3; ind = 3 % 3 => 0; arr[0] > arr[2] => 1 > 1 => no
//i = 2; j = 4; ind = 4 % 3 => 1; arr[1] > arr[2] => 2 > 1 => nge[2]= 2
//tc -> O(n^2) //sc -> O(n)

//optimal
vector<int> findNGE(vector<int> &arr) {
    int n = arr.size();
    vector<int> nge(n, -1);
    stack<int> st;

    // Loop from 2n - 1 down to 0
    //Because every element must be able to “see” elements on its right including wrapped elements
    for (int i = 2 * n - 1; i >= 0; i--) {//Traverse array twice, Start from the end to ensure right-side elements are processed first
        int idx = i % n;//circular indexing

        //remove smaller elements, stack always keep possible nges
        while (!st.empty() && st.top() <= arr[idx]) {
            st.pop();
        }

        // Fill answer only during the first pass (i < n)
        if (i < n) {//Second pass is only to prepare stack
            nge[idx] = st.empty() ? -1 : st.top();
        }

        st.push(arr[idx]);
    }

    return nge;
}
//arr = [2, 10, 12, 1, 11]
//i = 2 * 5 - 1 = 9; 9 to 0
//i = 9; idx = 9 % 5 => 4; st = empty; 9 < 5 no; push arr[4] = 11; st = [11]
//i = 8; idx = 8 % 5 => 3; st = 11; 11 <= 1 no; 8 < 5 no; push arr[3] = 1; st =[11, 1]
//i = 7; idx = 7 % 5 => 2; st = [11, 1]; 1 <= 12 yes pop 1; 11 <= 12 yes pop 11; st = empty; 7 < 5 no; push arr[2] = 12; st =[12]
//i = 6; idx = 6 % 5 => 1; st = [12]; 12 <= 10 no; 6 < 5 no; push arr[1] = 10; st = [12, 10]
//i = 5; idx = 5 % 5 => 0; st = [12, 10]; 10 <= 2 no; 5 < 5 no; push arr[0] = 2; st = [12, 10, 2]
//i = 4; idx = 4 % 5 => 4; st = [12, 10, 2]; 2 <= 11 yes pop 2; 10 <= 11 yes pop 10; 12 <= 11 no; 4 < 5 yes nge[4] = 12; push arr[4] = 11; st = [12, 11]
//i = 3; idx = 3 % 5 => 3; st = [12, 11]; 11 <= 1 no; 3 < 5 yes nge[3] = 11; push arr[3] = 1; st = [12, 11, 1]
//i = 2; idx = 2 % 5 => 2; st = [12, 11, 1]; 1 <= 12 yes pop 1; 11 <= 12 yes pop 11; 12 <= 12 yes pop 12; st = empty; 2 < 5 yes nge[2] = -1; push arr[2] = 12; st = [12]
//i = 1; idx = 1 % 5 => 1; st = [12]; 12 <= 10 no; 1 < 5 yes nge[1] = 12; push arr[1] = 10; st = [12, 10]
//i = 0; idx = 0 % 5 => 0; st = [12, 10]; 10 <= 2 no; 0 < 5 yes nge[0] = 10; push arr[0] = 2; st = [12, 10, 2]
//nge = [10, 12, -1, 11, 12]
//tc -> O(4n) => O(n) //sc -> O(2n) + O(n) => O(n)

