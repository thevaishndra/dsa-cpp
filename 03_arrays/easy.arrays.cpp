#include<bits/stdc++.h>
using namespace std;
//Array -> linear data structure, stores similar elements

// Q1. Largest element in array
//brute
int sortArray(vector<int> &arr){
    sort(arr.begin(), arr.end());//first sort the array in ascending order
    return arr[arr.size()-1];//print [size of array - 1]th index
}
//tc -> O(n log n) //sc -> O(1)

//optimal
int findLargestElement(int arr[], int  n){
    int largest= arr[0];
    for(int i = 0; i < n; i++){//using a for loop to compare largest with elements of array
        if(arr[i] > largest)//if any value is greater than largest 
        largest = arr[i];//update the largest
    }
    return largest;
}
//tc -> O(n) //sc -> O(1)


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
//tc -> O(n log n) //sc -> O(1)

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
//tc -> O(n) + O(n) = O(n) //sc -> O(1)

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
//tc -> O(n) //sc -> O(1)


//Q3. Check if the array is sorted
int checkSorted(int arr[], int n){
    for(int i = 1; i < n; i++){
        if(arr[i] <= arr[i-1]){//the next no. should be greater than previous 
            return false;
        } 
    }
    return true;
}
//tc -> O(n) //sc -> O(1)


//Q4. Remove Duplicates from sorted array -imp
//Brute
int removeDuplicates(int arr[], int n){
    set <int> st;//set takes unique values and no repeats
    for(int i = 0; i < n; i++){
        st.insert(arr[i]);//collection of non repeating values
    }
    int index = 0;
    //copy elements from set to original array
    for (auto it : st) {//iterates over st taking it - iterator as each element
        arr[index] = it;//assign value from set to array
        index++;//move to next index
    }
    return st.size();//return number of unique elements
}
//tc -> O(n log n) //sc -> O(n)

//Optimal
int removeDuplicates2(int arr[], int n){
    int i = 0;//2 pointer approach
    for(int j = 1; j < n; j++){//i and j both starts with consecutive elements
        if(arr[j] != arr[i]){//they are same only j moves forward but they are not
            arr[i + 1] = arr[j];//then i + 1 position is same as value j is holding
            i++;// i + 1 position becomes i and j will move forward as it was doing
        }
    }
    return i + 1;//this will create an array with no duplicates till i + 1 position
}
//tc -> O(n) //sc -> O(1)


//Q5. Left rotate the array by one place
void leftRotateOne(int arr[], int n){
    int temp = arr[0];//store first element in temp
    for(int i = 1; i < n; i++){
        arr[i-1] = arr[i];//values gets shifted to left one place
    }
    arr[n - 1] = temp;//place temp at the last position
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";//rotated array
    }
}
//tc -> O(n) sc -> O(1)


//Q6. Left rotate the array by D places
//Brute
int leftRotateByD(int arr[], int n, int d){
    d = d % n;//handles rotation greater than size of array, no of rotations is reduced to array bounds
    int temp[d];//stores first d elements
    for(int i = d; i < n; i++){//shift rest of array by d positions
        arr[i - d] = arr[i];
    }
    // int j = 0;
    // for(int i = n - d; i < n; i++){
    //     arr[i] = temp[j];
    //     j++;
    // } But instead of writing j we can do
    for(int i = n - d; i < n; i++){//copy the elements from temp[] to the end of arr[]
        arr[i] = temp[i - (n - d)];//indexing of temp - 0, 1, 2 - so that the elements on those index can be copied to array
    }
}
//tc -> O(1) + O(d) + O(n - d) + O(d) = O(n - d + d) => O(n + d)  sc -> O(d) + O(1) = O(d)

//Optimal
void reverse(int arr[], int start, int end){//Function to reverse elements if not using stl otherwise cpp stl has in-built reverse func
    while(start <= end){//1,2,3,4,5 -> 5,2,3,4,1 -> 5,4,3,2,1 -> reverses in this way
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start ++; 
        end--;
    }
}
int leftRotateArrayByD2(int arr[], int n, int d){//function for rotation
  // Reverse first d elements
  reverse(arr, 0, d - 1);
  // Reverse last n-d elements
  reverse(arr, d, n - 1);
  // Reverse whole array
  reverse(arr, 0, n - 1);
}
//in right rotation, reverse last d elements, first n - d elements, reverse whole array
//tc -> O(d) + O(n - d) + O(n) = O(2n) sc -> O(1)
//tc slightly increased


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
//tc -> O(n) + O(x) + O(n - x) = O(2n) sc -> O(x) but O(n) in worst case

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
            j++;//only values are swapped-> 0s are going towards left and j is still pointing at 0 after j++ whereas i is still at j + 1 after i++
        }
    }
    return arr;//we need not write a loop to print array
}
//tc -> O(x) +O(n - x) = O(n) sc -> O(1)


//Q8. Linear search
int linearSearch(int arr[], int n, int num){
    for(int i = 0; i < n; i++){
        if(arr[i] == num){//if element is equal to the given num, return i otherwise return -1
        return i;
        }
    }
      return -1;
}
//tc -> O(n) sc -> O(1)


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
    for(auto &it : st){//&it -> reference to each element
        Union.push_back(it);//now putting back set elements in the new array called union
    }
}
//tc -> O(n1 log n) + O(n2 log n) + O(n1 + n2) sc -> O(n1 + n2) + O(n1 + n2) - once to store, and other time to return the answer

//Optimal
vector<int> findUnion2(int arr1[], int arr2[], int n, int m) {
    int i = 0, j = 0;//i -> pointer for arr1; j -> pointer for arr 2
    vector<int> Union;//a vector to store final union of both arrays
    
    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) {//starting with arr1[i]
            if (Union.empty() || Union.back() != arr1[i]) {//we check if union is empty or it is not equal to same element
                Union.push_back(arr1[i]);
            }
            i++;//arr1[i] has been processed
        } else {//starting with arr2[i]
            if (Union.empty() || Union.back() != arr2[j]) {
                Union.push_back(arr2[j]);
            }
            j++;//arr2[j] has been processed
        }
    }

    while (i < n) {//remaining elements for arr1
        if (Union.empty() || Union.back() != arr1[i]) {
            Union.push_back(arr1[i]);
        }
        i++;
    }

    while (j < m) {//remaining elements for arr2
        if (Union.empty() || Union.back() != arr2[j]) {
            Union.push_back(arr2[j]);
        }
        j++;
    }

    return Union;//final union of botha arrays
}
//tc -> O(n + m) sc -> O(n + m) in worst case if no duplicates exist


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


//Q11. Find missing no. in an array
//Brute
int missingNo(int arr[], int n){
    for(int i = 1; i <= n; i++){//traversing the original array of size n -> including missing no
        int flag = 0;//initially all are 0, if we found the same no while traversing we mark it as 1, if we found missing no it will be 0
        for(int j = 0; j < n-1; j++){//linear search in array
            if(arr[j] == i){//check if i is in the arr[]
                flag = 1;//missing no not found
                break;
            }
        }
        if(flag == 0){//missing no. found
            return i;
        }
    }
    return -1;//no missing no
}
//tc -> O(n) * O(n - 1) = O((n * n) - n) => O(n * n) sc -> O(1)

//Better
int missingNo2(vector<int> &arr, int n){
    int hash[n + 1] = {0};//hash array of size n + 1, initializing all values from 0
        for(int i = 0; i < n - 1; i++){//we are marking in hash
            hash[arr[i]]++;//if arr[i] = 1 then hash[1]++ means in hash it would be incremented by 1 ie, 0 -> 1
        }
        for(int i = 1; i <= n; i++){
            if(hash[i] == 0){//the no which doesn't gets marked as 1 in hash means that is not present in array
                return i;//missing nummber
            }
        }
        return -1;//if there is no missing number
}
//tc -> O(n) + O(n) = O(n) sc -> O(n)

//Optimal 1
int missingNo3(vector<int> &arr, int n){
    int sum = n * (n + 1) / 2;//sum of natural nos formula -> so actual sum including the missing no.
    int s2 = 0;
    for(int i = 0; i < n; i++){
        s2 += arr[i];// sum of nos present in array
    }
    return (sum - s2);//actual sum - sum of nos present in array gives missing no.
}
//tc -> O(n) sc -> O(1)

//Optimal 2
int missingNo4(vector<int> &arr, int n){
    int xor1 = 0; int xor2 = 0;
    for(int i = 0; i < n - 1; i++){
        xor2 ^= arr[i];// xor of all elements in array -> 1 ^ 2 ^ 4
        xor1 ^= (i + 1);//xor of all elements including missing no -> 1 ^ 2 ^ 3 ^ 4
    }
    return xor1 ^ xor2;//(1 ^ 2 ^ 4) ^ (1 ^ 2 ^ 3 ^ 4) = 3 -> missing no
}//a ^ a = 0; 0 ^ a = a -> all same nos will cancel out each other and then we get no itself by ^ with 0
//tc -> O(n) sc -> O(1)


//Q12. Max consecutive ones
int maxConsecutiveOnes(vector<int> &arr, int n){
    int count = 0; int maxi = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 1){// if element is 1 in array
            count++;// we will mark it in count as no of times it is 1
            maxi = max(maxi, count);//tracking the maximum count of consecutives we get after incrementing the count everytime
        } else {// as we get i = 0, it will break the count and changes it to 1 again, so count again the consecutive 1s
            count = 0;
        }
    }
    return maxi;//count of max consecutive 1s
}
//tc -> O(n) sc -> O(1)


//Q13. Find the no. that appears once & other numbers twice
//brute -> traverse an array , do a linear search and count if it appears more than once
int appearsOnce(vector<int> &arr, int n){
    for(int i = 0; i < n; i++){
        int num = arr[i];//pick current no
        int count = 0;

        for(int j = 0; j < n; j++){//count how many times it appears
            if(arr[j] == num){
                count++;
            }
        }
        if(count == 1){//if it appears only once, return it
            return num;
        }
    }
    return -1;//if there is no such number
}
//tc -> O(n * n) sc -> O(1) 

//better
int appearsOnce2(vector<int> &arr, int n){
    int maxi = arr[0];
    for(int i = 0; i < n; i++){
        maxi = max(maxi, arr[i]);
    }
    vector<int> hash(maxi + 1, 0);

    for(int i = 0; i < n; i++){
        hash[arr[i]]++;
    }
    for(int i = 0; i < n; i++){
        if(hash[arr[i]] == 1){
            return arr[i];
        }
    }
    return -1;
}
//tc -> sc ->

//


//Q14. Longest subarray with sum K [positives]
//Q15. Longest subarray with sum K [positives + negatives]