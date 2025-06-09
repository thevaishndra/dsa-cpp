#include<bits/stdc++.h>
using namespace std;

// Q2. Majority Element N by 3 times
//Brute
vector <int> majorityElement(vector<int> arr) {
    int n = arr.size();
    vector<int> ls;

    for(int i = 0; i < n; i++) {
        if(ls.size() == 0 || ls[0] != arr[i]){//checks if the list is empty or the current element is not already in the list
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(arr[j] == arr[i]) {
                    count++;//how many time it occurs
                }
            }

            if(count > n/3){
                ls.push_back(arr[i]);//if the count is greater than n/3, then we add it to the list
            }
        }
            if(ls.size() == 2) break;//atmost 2 elements can satisfy this condition, no matter greater the value of n
    }
    return ls;
}
//tc -> O(n^2) //sc -> O(n)

//Better
vector <int> majorityElement2(vector<int> arr) {
    int n = arr.size();
    vector<int> ls;

    map<int, int> mpp;//hash map
    int mini = int(n/3) + 1;//not greater than or equal to but strictly greater than n/3 

    for(int i = 0; i < n; i++) {
        mpp[arr[i]]++;//traverse whole array and update the count of each element in the map

        if(mpp[arr[i]] == mini) {//check if the value of any element is greater than floor of n/3 + 1
            ls.push_back(arr[i]);//if yes, include it in the list
        }
        if(ls.size() == 2) break;//atmost 2 elements can satisfy this condition, no matter greater the value of n
    }//stop as soon as size of list becomes 2
    return ls;
}
//tc -> O(n log n) //sc -> O(n)

//Optimal
vector <int> majorityElement3(vector<int> arr) {
    int n = arr.size();
    int count1 = 0; int count2 = 0;
    int element1 = INT_MIN;
    int element2 = INT_MIN;

    for(int i = 0; i < n; i++) {
        if(count1 == 0 && element2 != arr[i]){//count 1 is not zero and element 2 is not equal to current value
            count1 = 1;//count1 becomes one
            element1 = arr[i];//current value is element 1
        }
        else if(count2 == 0 && element1 != arr[i]) {//now count 2 is not zero and element 1 is not equal to current value
            count2 = 1;//count2 becomes one
            element2 = arr[i];//current value os element 2
        }
        else if(element1 == arr[i]) count1++;//if current element matches element 1, increment count1
        else if(element2 == arr[i]) count2++;//if current element matches element 2, increment count2
        else {//if matches neither reduce the count, voting out of non-majority elements
            count1--;
            count2--;
        }
    }

    vector<int> ls;
    count1 = 0; count2 = 0;
    for(int i = 0; i < n; i++) {//how many times element1 and element2 occur in the array
        if(arr[i] == element1) count1++;
        if(arr[i] == element2) count2++;
    }

    int mini = int(n/3) + 1;//value should be greater than the floor of n/3
    if(count1 >= mini) ls.push_back(element1);
    if(count2 >= mini) ls.push_back(element2);

    return ls;
}
//tc -> O(2n) //sc -> O(1)