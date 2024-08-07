#include<bits/stdc++.h>
using namespace std;
//4*4 square = *
void print1(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<< "*";
        }
        cout<<endl;//go to next line
    }
}
//left bottom right angle triangle = *
void print2 (int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){//till i except this everything is same
            cout<< "*";//1st line-> i star, 2nd line-> 2 star, it depends on i
        }
        cout<<endl;
    }
}
//left bottom right angle triangle = no. Read row wise-> 1, 1 2, 1 2 3, 1 2 3 4, 1 2 3 4 5
void print3(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=i; j++){//this we did in last ques to form a triangle
            cout<<j<<" ";//because 1st col, all no are 1, 2nd col all no. are 2....n columns
        }
        cout<<endl;
    }
}
//left bottom right angle triangle = no. Read row wise-> 1, 2 2, 3 3 3, 4 4 4 4, 5 5 5 5 5
void print4(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){//same as previos one
            cout<<i<<" ";//because 1st row, all no are 1, 2nd row all no. are 2....n rows
        }
        cout<<endl;
    }
}
//left top inverse right angle triangle = *
void print5(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n-i+1; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
//left top inverse right angle triangle = no. Read row wise -> 1 2 3 4 5, 1 2 3 4, 1 2 3, 1 2, 1
void print6(int n){
    for(int i = 0; i <= n; i++){
        for( int j = 1; j <= n-i+1; j++){
            cout<<j<<" ";//as we are printing row here, as all value in one row is same
        }
        cout<<endl;
    }
}
// perfect triangle in the bottom center having: space, star, space
void print7(int n){
    for(int i = 0; i < n; i++){
        //space
        for(int j = 0; j < n-i-1; j++){
            cout<<" ";
        }
        //star
        for(int j = 0; j < (2*i+1); j++){
            cout<<"*";
        }
        //space
        for(int j = 0; j < n-i-1; j++){
            cout<<" ";
        }
        cout<<endl;
    }
}
//inverted perfect triangle in center- '*'
void print8 (int n){
    for(int i = 0; i < n; i++){
        //space
        for(int j=0; j < i; j++){
            cout<<" ";
        }
        //star
        for(int j = 0; j < 2*n-(2*+1); j++){
            cout<<"*";
        }
        //space
        for(int j = 0; j < i; j++){
            cout<<" ";
        }
        cout<<endl;
    }
}
//diamond with no symmetry ctrC ctrlV ques7 + ques8
void print9(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            cout<<" ";
        }
        for(int j = 0; j < 2*i+1; j++){
            cout<<"*";
        }
        for(int j= 0; j <= n-i-1; j++){
            cout<<" ";
        }
        cout<<endl;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            cout<<" ";
        }
        for(int j = 0; j <= 2*n-(2*i+1); j++){
            cout<<"*";
        }
        for(int j = 0; j < i; j++){
            cout<<" ";
        }
        cout<<endl;
    }
}
// half perfect diamond in left, it was ques 2+ 5 if it didn't had symmetry, but it has symmetry
void print10(int n){
    for(int i = 1; i <= 2*n-1; i++){//n rows
    int stars = i;//we want to print stars = i till half diamond
    if(i > n) stars = 2*n-i;//after that half, we are printing differently
    for(int j = 1; j <=stars; j++){
        cout<<"*";
    }
    cout<<endl;
} 
}
//left bottom right angle triangle, row- 1, 0 1, 1 0 1, 0 1 0 1, 1 0 1 0 1
void print11(int n){
    int start = 1;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0) start = 1;
        else start = 0;
        for(int j = 0; j < 1; j++){
            cout<<start;
            start = 1 - start;
        }
        cout<<endl;
    }
}
//left bottom right angle triangle + right bottom right angle triangle
//row no :- 1, 1 2, 1 2 3, 1 2 3 4 space row no :- 1, 2 1, 3 2 1, 4 3 2 1
void print12(int n){
    int space = 2*(n-1);
    for(int i = 1; i <= n; i++){
        //number
        for(int j = 1; j <= i; j++){
            cout<<j;
        }
        //space
        for(int j = 1; j <= space; j++){
            cout<<" ";
        }
        //number
        for(int j = 1; j <= i; j++){
            cout<<j;
        }
        cout<<endl;
        space -= 2;//spaces: 6, 4, 2, 0 it's decreasing by 2
    }
}
//left right angle triangle, read row: 1, 2 3, 4 5 6; 7 8 9 10, 11 12 13 14 15
void print13(int n){
    int num = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout<<num;
            num += 1;//as we are incrementing no by 1 in every line
        }
        cout<<endl;
    }
}
//read row - A, A B, A B C, A B C D, A B C D E left right angle triangle
void print14(int n){
for(int i = 0; i < n; i++){
    for(char ch = 'A'; ch <= 'A'+i; ch++){//A+0 = A; A+1= B; A+2=C....n
        cout<<ch<<" ";
    }
    cout<<endl;
}
}
//read row - A B C D E, A B C D, A B C, A B, A left inverted right angle triangle
void print15(int n){
for(int i = 1; i <= n; i++){
    for(char ch = 'A'; ch <= n-i-1; ch++){
        cout<<ch<<" ";
    }
    cout<<endl;
}
}
//read row - A, B B, C C C, D D D D, E E E E E right angle triangle
void print16(int n){
for(int i = 0; i < n; i++){
    char ch = 'A' + i;
    for(int j = 0; j <= i; j++){
        cout<<ch<<" ";
    }
    cout<<endl;
}
}
//perfect triangle in center - space, alphabet, space -> A, A B A, A B C B A, A B C D C B A, A B C D E D C B A
void print17(int n){
    for(int i = 0; i < n; i++){
        //space
        for(int j = 0; j < n-i-1; j++){
            cout<<" ";
        }
        //alphabet
        char ch ='A'; int breakpoint = (2*i+1)/2;
        for(int j = 0; j < 2*i+1; j++){
            cout<<ch;
            if(j <= breakpoint) ch++;
            else ch--;
        }
        //space
        for(int j = 0; j < n-i-1; j++){
            cout<<" ";
        }
        cout<<endl;
    }
}
//read row - E, D E, C D E, B C D E, A B C D E left bottom right angle triangle
void print18(int n){
    for(int i = 0; i < n; i++){
        for(char ch = 'E'- i ; ch < 'E'; ch++){//because in last of every row there is E
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}
//perfect diamond of spaces surrounded by stars - star, space, star
void print19(int n){
    for(int i = 1; i <= n; i++){
        //stars
        for(int j =1; j <= n-i; j++){
            cout<<"*";
        }
        //space
        int inis = 0;
        for(int j =0; j < inis; j++){
            cout<<" ";
        }
        //space
        for(int j = 1; j <= n-i; j++){
            cout<<" ";
        }
        cout<<endl;
        inis += 2;
    }
    //then the inverted part
    for(int i = 1; i <= n; i++){
        //stars
        for(int j = 1; j <= i; j++){
            cout<<"*";
        }
        //space
        int inis = 2*n -2;
        for(int j = 0; j < inis; j++){
            cout<<" ";
        }
        //stars
        for(int j =1; j <= i; j++){
            cout<<" ";
        }
        cout<<endl;
        inis -=2;
    }
}
//half left diamond + half right diamond -> star, space, star
void print20(int n){
int space = 2*n-2;
for(int i = 1; i <= 2*n-1; i++){
    int stars = i;
    if(i > n) stars = 2*n-i;
    //stars
    for(int j = 1; j <= stars; j++){
        cout<<"*";
    }
    //space
    for(int j = 1; j <= space; j++){
        cout<<" ";
    }
    //stars
    for(int j = 1; j <= stars; j++){
        cout<<"*";
    }
    cout<<endl;
    if(i < n) space -= 2;
    else space += 2;
}
}
//