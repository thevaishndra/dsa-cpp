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
//arr = [4, 7, 1, 1, 2, -3, -7, 17, 15, -16]
//i = 0; arr[0] = 4 > 0 -> push 4 -> st = [4]
//i = 1; arr[1] = 7 > 0 -> push 7 -> st = [4, 7]
//i = 2; arr[2] = 1 > 0 -> push 1 -> st = [4, 7, 1]
//i = 3; arr[3] = 1 > 0 -> push 1 -> st = [4, 7, 1, 1]
//i = 4; arr[4] = 2 > 0 -> push 2 -> st = [4, 7, 1, 1, 2]
//i = 5; arr[5] = -3 > 0 no -> st is not empty, st top is > 0 but st top -> 2 < 3, so pop 2 -> st = [4, 7, 1, 1]
//st is not empty, st top is > 0 but st top -> 1 < 3, so pop 1 -> st = [4, 7, 1]
//st is not empty, st top is > 0 but st top -> 1 < 3, so pop 1 -> st = [4, 7]
//i = 6; arr[6] = -7 > 0 no -> st is not empty, st top is > 0 but st top -> 7 == 7, so pop 7 -> st = [4]
//i = 7; arr[7] = 17 > 0 -> push 17 -> st = [4, 17]
//i = 8; arr[8] = 15 > 0 -> push 15 -> st = [4, 17, 15]
//i = 9; arr[9] = -16 > 0 no -> st is not empty, st top is > 0 but st top -> 15 < 16, so pop 15 -> st = [4, 17]
//st is ans
//tc -> O(2n) //sc -> O(n)