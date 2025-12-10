#include <bits/stdc++.h>
using namespace std;

//Q.8 Implement min stack -> returns minimum element in stack
//Brute
class MinStack {
    stack<pair<int, int>> st;   // {value, current minimum}

public:
    // Push element
    void push(int val) {//if stack is empty, push {val, val}
        if (st.empty()) {
            st.push({val, val});
        } 
        else {//otherwise calculate minimum and push that
            int currentMin = min(val, st.top().second);//{}
            st.push({val, currentMin});
        }
    }

    // Pop element
    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }

    // Return top element
    int top() {
        return st.top().first;//first element is val
    }

    // Return minimum element
    int getMin() {
        return st.top().second;//second element is current minimum
    }
};
//tc -> O(1) //sc -> O(2 * n)

//Optimal
class MinStack {
    stack<long long> st;
    long long mini;

public:
    MinStack() {
        mini = LLONG_MAX;
    }

    // Push element
    void push(long long val) {
        if (st.empty()) {
            st.push(val);
            mini = val;
        }
        else {
            if (val >= mini) {
                st.push(val);
            }
            else {
                // store encoded value
                long long encoded = 2LL * val - mini;
                st.push(encoded);
                mini = val;
            }
        }
    }

    // Pop element
    void pop() {
        if (st.empty()) return;

        long long x = st.top();
        st.pop();

        if (x < mini) {
            // recover previous minimum
            mini = 2LL * mini - x;
        }
    }

    // Get top element
    long long top() {
        if (st.empty()) return -1;

        long long x = st.top();
        if (x >= mini) return x;
        else return mini;  // encoded value, actual top is mini
    }

    // Get minimum element
    long long getMin() {
        if (st.empty()) return -1;
        return mini;
    }
};

//tc -> O(1) //sc -> O(n)