#include <bits/stdc++.h>
using namespace std;

//

func(Arr) {
    list st;
    for(int i = 0; i < n - 1; i++) {
        if(arr[i] > 0) st.push(Arr[i]);
        else {
            while(!st.empty() && st.back() > 0 && st.back() > absolute(Arr[i])){
                st.pop_back
            }
        }
        if(!st.empty && st.back() == abs(arr[i])) st.pop_back
        else if(st.empty() || st.back() < 0) {
            st.push(Arr[i]);
        }
    }
    return list, st;
}
//tc -> O(2n) //sc -> O(n)