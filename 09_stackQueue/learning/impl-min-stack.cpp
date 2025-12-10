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
    stack<long long> st;//only one stack
    long long mini;//to store current minimum

public:
    MinStack() {
        mini = LLONG_MAX;
    }

    // Push element
    void push(long long val) {
        if (st.empty()) {//if stack is empty
            st.push(val);//push val
            mini = val;//value of mini is same as val
        }
        else {
            if (val >= mini) {//if new val is greater than mini just push it
                st.push(val);//as it doesn't change minimum
            }
            else {//If the new value is smaller than the current minimum
                //We do not push the real value
                //Instead we push an encoded value
                long long encoded = 2LL * val - mini;
                st.push(encoded);
                mini = val;//update mini to new val
            }
        }
    }
    //Why encode?
    //To store the new minimum safely, To help us recover the old minimum when popping later
    //Encoded values are always less than new minimum, so we can detect them easily

    // Pop element
    void pop() {
        if (st.empty()) return;//no elements exist do nothing

        long long x = st.top();//Store it in x so we can check if it’s encoded or normal
        st.pop();//remove top element

        //detect encoded value
        if (x < mini) {//if x is less than mini, then the value is encoded, not a real number
            mini = 2LL * mini - x;//restores the previous minimum before the encoded value was pushed
        }
    }

    // Get top element
    long long top() {
        if (st.empty()) return -1;

        //in the optimal MinStack, some values stored in the stack are encoded, not real
        long long x = st.top();//fetch the top element
        if (x >= mini) return x;//if it doesn't satisfies it means x is real value
        else return mini;  // if it satisfies means x is encoded, so the real top value is the current minimum
    }

    // Get minimum element
    long long getMin() {
        if (st.empty()) return -1;
        return mini;//simply return minimum
    }
};
//push(5), push(3), push(7), push(2), pop(), top(), getMin()
//val = 5; st = 5; mini = 5
//val = 3; 3 >= 5 -> false => encoded = 2*3 - 5 = 1; st = 5, 1; mini = 3
//val = 7; 7 >= 3 -> true => st = 5, 1, 7; mini = 2
//val = 2; 2 >= 3 -> false => encoded = 2*2 - 3 = 1; st = 5, 1, 7, 1; mini = 2
//x = 1; top of stack is popped which was 1; 1 < 2 -> true => mini = 2*2 - 1 = 3; st = 5, 1, 7
//7 >= 3 -> true => top = 7
//mini = 3

//tc -> O(1) //sc -> O(n)