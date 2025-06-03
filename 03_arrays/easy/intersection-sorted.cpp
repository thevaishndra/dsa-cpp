#include<bits/stdc++.h>
using namespace std;

//Q10. Intersection of two sorted array
//Brute
vector<int> findIntersection(int arr1[], int arr2[], int n, int m) {
    vector<int> intersection;//vector to store final ans
    vector<int> visited(m, 0); //visited array to track which elements in arr2 have already been used

    for (int i = 0; i < n; i++) {//we start from arr1[i] and traverse whole of arr2[j] to match elements
        for (int j = 0; j < m; j++) {
            if (arr1[i] == arr2[j] && visited[j] == 0) { //check if element is common and unvisited
                intersection.push_back(arr1[i]);  //Add the element to the ans
                visited[j] = 1;  // Mark this element in arr2 as visited, when we will agin traverse the whole array we will not take this
                break;  
            }
            if (arr2[j] > arr1[i])  //how we are matching and traversing arr2, if arr[i] = 4 and we traversed arr2 and found element greater than 4 like 5,
                break; //so we know we won't be having 4 ahead because it's a sorted array and we will break the loop
        }
    }
    return intersection;
}
//tc -> O(n * m) sc -> O(n * m)

//optimal
vector<int> findIntersection2(int arr1[], int arr2[], int n, int m) {
    vector <int> intersection;//vector that stores common elements between 2 arrays
    int i = 0; int j = 0;
    while(i < n && j < m){//within bounds
        if(arr1[i] < arr2[j]){//if the element is lesser we will not take
            i++;
        } else if (arr2[j] < arr1[i]){//if the element is greater we will not take
            j++;
        } else {//if the elments are same we are adding them in intersection
            intersection.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return intersection;
}
//tc -> O(n + m) in worst case sc -> O(1) and O(n + m) in worst case if no intersections