1) Problem Statement:
The binary number system only uses two digits, 0 and 1. Any string that represents a number in the binary number system can be called a binary string. You are required to implement the following function: 
int OperationsBinaryString(char *str);
The function accepts a string 'str' as its argument. The string 'str' consists of binary digits separated with an alphabet as follows: 
'A' denotes AND operation 
'B' denotes OR operation 
'C' denotes XOR operation 
You are required to calculate the result of the string 'str', scanning the string left to right, taking one operation at a time, and return the same. 

ExampleInput: 
ICOCICIAOBI 
Output: 
1 
Explanation: 
The alphabet in 'str' when expanded becomes "1 XOR 0 XOR 1 XOR 1 AND 0 OR 1", the result of the expression becomes 1, hence 1 is returned. 

int rel(string &s){
    int rel= s[0]-'0';
    for(int i=1;i<s.length()-1;i=i+2){
        if(s[i]=='C'){
            rel=rel^s[i+1]-'0';
        }
        else if(s[i]=='A'){
            rel=rel&s[i+1]-'0';
        }
        else if(s[i]=='B'){
            rel=rel|s[i+1]-'0';
        }
    }
    return rel;
}



2) Problem statement
A palindrome is a sequence of characters that has the property of reading the same in either direction. You are given a function,
char* ConvertToPalindrome(char*str);
The function accepts a string ‘str’. Implement the function to find and return the minimum characters required to append at the end of string ‘str’ to make it palindrome.
Assumption:
String will contain only lower case English alphabets.
Length of string is greater than equal to 1.
Note:
If string is already palindrome then return “NULL”.
You have to find the minimum characters required to append at the end of string to make it palindrome
Example:
Input:
abcdc
Output:
ba

bool is_palin(string &s){
    int i=0;
    int j= s.length()-1;
    
    while(i<=j){
        if(s[i]!=s[j]){
            return false;
        }
        else{
            i++;
            j--;
        }
    }
    return true;

}
string to_make_palin(string &s){
    if(is_palin(s)){
        return "NULL";
    }
    string rel="";
    int i=0;
    int j= s.length()-1;
    
    while(i<=j){
        if(s[i]!=s[j]){
            rel.push_back(s[i]);
            i++;
        }
        else{
            i++;
            j--;
        }
    }
    reverse(rel.begin(), rel.end());
    return rel;
}

3 ) Cubic sum:
Problem statement
You are given a function:
Int isCubicSumExist(long long int A[], int N);
The function accepts an array ‘A’ of size ‘N’ implement the function to return the count of good integers in array ‘A’
An integer Z is said to be good if and only if there exist two integers x and y such that x3 + y3 = z
Example
Input:
N :3
A : [35,9,1]
Output:
2
Explanation:
35 is a good integer, there exist an answer with X=2,Y=3(23+3  3  = 8+27 = 35)
9 is a good integer,there exist an answer with X=1,Y=2(13  + 2 3   = 9)
1 is not a good integer, so total 2 integers are good in the given array A
The custom input format for the above case
3
35 9 1
int isCubicSumExist(long long int arr[], int n){
    int count=0;
    for(int i=0; i<n;i++){
        long long int a= cbrt(arr[i]);
        int b=1;
        while(b<=a){
            if((b*b*b+a*a*a)==arr[i]){
                count++;
                break;
            }
            else if(b*b*b+ a*a*a<arr[i]){
                b++;
            }
            else{
                a--;
            }
        }
    }
    return count;
}

4) Problem statement:
Implement the following function:
Int PlayList(int airtime, int songs[], int n);

The function accepts a positive integer ‘airTime’ and a positive integer array ‘songs’ of size ‘n’ as its argument. ‘ songs’ consists of length of songs (in minutes). A radio jockey has to playlists of combination of exactly thre songs such that the total length of playlists is equal to ‘airtime’ (in minutes). Implement the function to find the count of playlist that can be find and return the same.
Assumption: ‘songs’ consists of unique elements
Note: Return -1 if ‘songs’ is null(None,in case of python) or n<3

Example:
Input:
airTime : 40
Songs : 7 14 21 19 17 2 29 5
Output:
3
Explanation:
Playlists formed are
{14,21,5} = 14 + 21+ 5 = 40
{7,14,19} = 7 + 14 + 19 = 40
{21,17,2} = 21 + 17 + 2 = 40
Since, 3 playlists can be formed thus, output is 3
#include <bits/stdc++.h>
using namespace std;

void PlayList(int airtime, int songs[], int n) {
    vector<vector<int>> rel;  // Vector to store the triplets
    int count = 0;
    
    for (int i = 0; i < n - 2; ++i) {
        int left = airtime - songs[i];
        unordered_set<int> s;
        
        for (int j = i + 1; j < n; ++j) {
            int complement = left - songs[j];
            
            if (s.find(complement) != s.end()) {
                // If the complement exists in the set, add the triplet
                rel.push_back({songs[i], songs[j], complement});
                ++count;
            }
            
            s.insert(songs[j]);  // Insert the current element into the set
        }
    }
    
    // Output the count of triplets
    cout << "Count: " << count << endl;
    
    // Print each triplet using a traditional for loop with simple formatting
    for (int i = 0; i < rel.size(); ++i) {
        cout << rel[i][0] << " " << rel[i][1] << " " << rel[i][2] << endl;
    }
}

int main() {
    int songs[] = {7, 14, 21, 19, 17, 2, 29, 5};
    int n = sizeof(songs) / sizeof(songs[0]);

    PlayList(40, songs, n);
    return 0;
}

5)
