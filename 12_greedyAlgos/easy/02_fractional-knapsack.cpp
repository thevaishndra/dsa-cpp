#include <bits/stdc++.h>
using namespace std;

//Q2. Fractional Knapsack Problem
Item {
    val,
    weight
};

bool cmp (itemVal1, itemVal2) {
    if(val1.value/val1.weight > val2.value/val2.weight)
        return true;
}
return false;

double func(Item arr[], w) {
    sort(arr, comp);
    total val = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i].weight <= w) {
            totVal += arr[i].value;
            w = w.arr[i].weight;
        }
        else {
            total += (arr[i].value/arr[i].weight) * w;
            break;
        }
    }
    return totVal;
}
//tc -> O(n + nlogn)
//sc -> O(1)