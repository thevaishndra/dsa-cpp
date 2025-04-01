#include <bits/stdc++.h>
using namespace std;

//HASHING-> For any given no. of times, how many times a no. appears
//NUMBER HASHING

//without hash
int f(int n, int arr[]){
    int count = 0;
    for(int  i = 0; i < n; i++){
        if(arr[i] == n){
            count = count + 1;
        }
    }
    return count;
}//TC -> O(N) -> O(Q * N)

//with hash
void print1(){
    //array 
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>> arr[i];
    }

    //pre-compute
    int hash[13] = {0};//depending on max size of array we declare hash else it's given in ques; array size is 12 we take 13
    for(int i = 0; i < n; i++){
        hash[arr[i]] += 1;
    }

    //queries
    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;

    //fetch
    cout<<hash[number]<<endl;
    }
}

//CHARACTER HASHING
//without hash
int f(int n, char c, string s){
    int count = 0;
    for(int i =0; i < n; i++){
        if(s[i] == c)
        count++;
    }
    return count;
}

//with hash
void print2(){
    string s;
    cin>>s;

    //pre-compute
    int hash[26] = {0};//considering only lower cases, if it doesn't state exclusively then [256] -> total characters
    for(int i = 0; i < s.size(); i++){
        hash[s[i] - 'a']++;
    }

    //queries
    int q; 
    cin>>q;
    while(q--){
        char c;
        cin>>c;
        //fetch
        cout<<hash[c - 'a']<<endl;
    }
}