#include<bits/stdc++.h>
using namespace std;
//Array -> linear data structure, stores similar elements
//EASY QUES

// Q1. Largest element in array
//brute
int sortArray(vector<int> &arr){
    sort(arr.begin(), arr.end());//first sort the array in ascending order
    return arr[arr.size()-1];//print [size of array - 1]th index
}
//tc -> O(n log n)
//sc -> O(1)

//optimal
int findLargestElement(int arr[], int  n){
    int largest= arr[0];
    for(int i = 0; i < n; i++){//using a for loop to compare largest with elements of array
        if(arr[i] > largest)//if any value is greater than largest 
        largest = arr[i];//update the largest
    }
    return largest;
}
//tc -> O(n)
//sc -> O(1)


//Q2. Second largest element in array
//brute
int findSecondLargest(int arr[], int n){
    sort(arr, arr+n);//sort the array in ascending order
    int secondLargest = arr[0]; 
    int largest = arr[n - 1];//ofc, largest element will be in the last
    for(int i = n-2; i >= 0; i--){//Finding the second element which is not equal to the largest element 
        if(arr[i] != largest)//logically the element before largest is slargest but what if ie the same no. as largest
        secondLargest = arr[i];
        break;
    }
    return secondLargest;
}
//tc -> O(n log n)
//sc -> O(1)

//better
int findSecondLargest2(vector<int> &arr){
    int largest = arr[0];//first pass: finding largest 
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
        return largest;
    }
    int slargest = -1;//if there are negatives in the array then we will take INT_MIN
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > slargest && arr[i] != largest){//element should be greater than slargest and not equal to largest
            slargest = arr[i];
        }
        return slargest;
    }
}
//tc -> O(n) + O(n) = O(n)
//sc -> O(1)

//optimal
int findSecondLargest3(vector<int> &arr) {
    int largest = arr[0];
    int slargest = -1;
        
    for (int i = 1; i < arr.size(); i++){//finding largest & slargest both in one pass
        if(arr[i] > largest){
            slargest = largest;
            largest = arr[i];
        } else if (arr[i] < largest && arr[i] > slargest){
            slargest = arr[i];
        } 
    }
        return slargest; 
}
//tc -> O(n)
//sc -> O(1)


//Q3. Check if the array is sorted
int checkSorted(int arr[], int n){
    for(int i = 1; i < n; i++){
        if(arr[i] <= arr[i-1]){//the next no. should be greater than previous 
            return false;
        } 
    }
    return true;
}
//tc -> O(n)
//sc -> O(1)


//Q4. Remove Duplicates from sorted array -imp
//Brute
int removeDuplicates(int arr[], int n){
    set <int> st;//set takes unique values and no repeats
    for(int i = 0; i < n; i++){
        st.insert(arr[i]);//collection of non repeating values
    }
    int index = 0;
    //copy elements from set to original array
    for (auto it : st) {
        arr[index] = it;//assign value from set to array
        index++;//move to next index
    }
    
    return st.size();//return number of unique elements
}
//tc -> O(n log n)
//sc -> O(n)

//Optimal
int removeDuplicates2(int arr[], int n){
    int i = 0;//2 pointer approach
    for(int j = 0; j < n; j++){//i and j both starts together from same element
        if(arr[j] != arr[i]){//they are same only j oves forward but they are not
            arr[i + 1] = arr[j];//then i + 1 position is same as value j is holding
            i++;// i + 1 position becomes i and j will move forward as it was doing
        }
    }
    return i + 1;//this will create an array with no duplicates till i + 1 position
}
//tc -> O(n)
//sc -> O(1)


//Q5. Left rotate the array by one place
int leftRotateOne(int arr[], int n){
    int temp = arr[0];
    for(int i = 1; i < n; i++){
        arr[i-1] = arr[i];
    }
    arr[n - 1] = temp;
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
}


//Q6. Left rotate the array by D places
//Brute
int leftRotateByD(int arr[], int n, int d){
    d = d % n;
    int temp[d];
    for(int i = d; i < n; i++){
        arr[i - d] = arr[i];
    }
    // int j = 0;
    // for(int i = n - d; i < n; i++){
    //     arr[i] = temp[j];
    //     j++;
    // } But instead of writing j we can do
    for(int i = n - d; i < n; i++){
        arr[i] = temp[i - (n - d)];//for ex: n-d = 4 so, i = 4, 4 - 4 = 0; which is the first index of temp
    }//then i = 5, 5 - 4 = 1; which is the second index of temp and so on
    //so, instaed of creating another pointer j we can print elements from temp by doing this
}
//Optimal
void reverse(int arr[], int start, int end){//Function to reverse elements if not using stl otherwise cpp stl has in-built reverse func
    while(start <= end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start ++; 
        end--;
    }
}
int leftRotateArrayByD2(int arr[], int n, int d){
  // Reverse first k elements
  reverse(arr, 0, d - 1);
  // Reverse last n-k elements
  reverse(arr, d, n - 1);
  // Reverse whole array
  reverse(arr, 0, n - 1);
}


//Q7. Move all zeroes to the end of array
//Brute
int moveZeroesToEnd(int arr[], int n){
    vector <int> temp;//creating temporary initiating with 0

    for(int i = 0; i < n; i++){//putting all the non zero elements in temp
        if(arr[i] != 0){
            temp.push_back(arr[i]);
        }
    }
    int nonZero = temp.size();
    for(int i = 0; i < nonZero; i++){//now, from temp putting back non zeros in array in the starting
        arr[i] = temp[i];
    }
    for(int  i = nonZero; i < n; i++){//after the non zero size, putting zeros in the remaining array
        arr[i] = 0;
    }
    for(int i = 0; i < n; i++){//return array as it is an int type instead of vector
        cout<<arr[i]<<" ";
    }
}
//Optimal
vector<int> moveZeroesToEnd2(int n, vector<int>arr){
    int j = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] = 0){
            j = i;//j is always going to be at 0
            break;
        }
    }//suppose, if j+1 is non zero eg: 1,we will swap it, now j is pointing 1 and i is pointing 0, 
    //but then we also do j++, then j is again at 0, and in loop i is iterating so i goes to next element adjacent to j
    for(int i = j + 1; i < n; i++){
        if(arr[i] != 0){
            swap(arr[i], arr[j]);//as we used vector we need not write code for swap
            j++;
        }
    }
    return arr;//we need not write a loop to print array
}
//Q8. Linear search
int linearSearch(int arr[], int n, int num){
    for(int i = 0; i < n; i++){
        if(arr[i] == num){//if element is equal to the given num, return i otherwise return -1
        return i;
        }
    }
      return -1;
}
//Q9. Union of two sorted array
//Brute
vector <int> findUnion(int arr1[], int arr2[], int n, int m){
    set <int> st;
    for(int i = 0; i < n; i++){
        st.insert(arr1[i]);//add unique elements in set from array 1
    }
    for(int i = 0; i < m; i++){
        st.insert(arr2[i]);//add unique elements in set from array 2
    }
    vector <int> Union;
    for(auto & it : st){
        Union.push_back(it);//now putting back set elements in the new array called union
    }
}
//Optimal
vector <int> findUnion(int arr1[], int arr2[], int n, int m){
    int  i = 0; int  j = 0;
    vector <int> Union;
    while( i < n && j < m){
        if(arr1[i] <= arr2[j]){
            if(Union.size() == 0 || Union.back() != arr1[i]){
                Union.push_back(arr1[i]);
                i++;
            }
        }
        else {
            if(Union.size() == 0 || Union.back() != arr2[j]){
                Union.push_back(arr2[j]);
                j++;
            }
        }
    }
    while(i < n){
        if(Union.back() != arr1[i]){
            Union.push_back(arr1[i]);
            i++;
        }
    }
    while(j < m){
        if(Union.back() != arr2[j]){
            Union.push_back(arr2[j]);
            j++;
        }
    }
    return Union;
}
//Q10. Intersection of two sorted array

//Q11. Find missing no. in an array
//Q12. Max consecutive ones
//Q13. Find the no. that appears once & other numbers twice
//Q14. Longest subarray with sum K [positives]
//Q15. Longest subarray with sum K [positives + negatives]