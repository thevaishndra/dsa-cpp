#include <bits/stdc++.h>
using namespace std;

//Q. Asteroid Collision
// Right-moving → just push
// Left-moving → fight with right-moving
// Bigger survives
// Equal → both die
// End result = remaining elements in stack
list<int> func(vector<int>& arr) {
    list<int> st;//works like a stack
    int n = arr.size();

    for (int i = 0; i < n; i++) {

        // If asteroid is moving right
        if (arr[i] > 0) {
            st.push_back(arr[i]);//put into the stack
        }
        else {
            // Collision case
            while (!st.empty() && st.back() > 0 && st.back() < abs(arr[i])) {//abs -> absolute value; st.back() same as top
                st.pop_back();//if the current element greater than the top element of stack, means prev element should be popped
            }

            // Equal size collision
            if (!st.empty() && st.back() == abs(arr[i])) {//If both asteroids are of same size
                st.pop_back();//Both get destroyed, So remove top and do not push current one
            }
            // No collision, push left-moving asteroid
            else if (st.empty() || st.back() < 0) {
                st.push_back(arr[i]);//Then no collision → push current asteroid
            }
        }
    }
    return st;//Return the final list of remaining asteroids
}
//tc -> O(2n) //sc -> O(n)