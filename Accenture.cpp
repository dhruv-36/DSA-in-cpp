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

5) Find Smallest Character
Problem Statement
You are given a function:
def SmallestCharacter(s):
The function accepts a string ‘s’. Implement the function to find the smallest English character which is not present in the given string ‘s’ and return the same.
Example :
Input :
aidubudxd
Output :
c
Explanation :
Input string contains a and b. So now the smallest character that is not present in the string is c.

char smallestCharacter(string s){
    
    char arr[26]={0};
    for(int i=0;i<s.length();i++){
        int a= s[i]-'a';
        arr[a]++;    
    }
    for(int i=0; i<26;i++){
        if(arr[i]==0){
            return i+'a';
        
        }
    }
    return '-';
}

6) Find the word average
Problem Statement
 Implement the following function:
Static float Average(String str){}
The function accepts a string ‘str’ of length ‘len’ as its arugment. Implement the function to calculate the word average and return the same. Word Average is calculated by finding the average of the ASCII values of all of the letters in a word.
Note:
•	‘str’ is not null
•	Input string will contain only lower case English alphabets
•	The ASCII value of lower case ‘a’ is 97 while that of ‘z’ is 122
•	Do not round off your results, it will be automatically rounded off up to 2       decimal places and then displayed 
Example :                      Explanation :
Input :  Char       value            S               115
                                     o               111
 Str:source                          u               117
 Output: 109.50                     r                114
                                    c                99
                                    e                101


float average_string(string s){
    float a=0;
    for(int i=0; i<s.length();i++){
        a+=s[i];
    }
    return a/s.length();
}
int main() {
    // Write C++ code here
    string a="source";
    cout<<fixed<<setprecision(2)<<average_string(a);   ///////////////<<fixed<<setprecision(2) // used for getting the answer for 2 decimal numbers

    return 0;
}

6) Problem Description :The function accepts two positive integers ‘r’ and ‘unit’ and a positive integer array ‘arr’ of size ‘n’ as its argument ‘r’ represents the number of rats present in an area, ‘unit’ is the amount of food each rat consumes and each ith element of array ‘arr’ represents the amount of food present in ‘i+1’ house number, where 0 <= i
Note:
Return -1 if the array is null
Return 0 if the total amount of food from all houses is not sufficient for all the rats.
Computed values lie within the integer range.
Example 

Input:
r: 7
unit: 2
n: 8
arr: 2 8 3 5 7 4 1 2
Output:
4

Explanation:
Total amount of food required for all rats = r * unit= 7 * 2 = 14.

The amount of food in 1st houses = 2+8+3+5 = 18. Since, amount of food in 1st 4 houses is sufficient for all the rats. Thus, output is 4.
int rat(int arr[], int r, int n, int util){
    if(n==0){
        return -1;
    }
    int count =0;
    int total= r*util;
    int sum=0;
    for(int i=0; i<n;i++){
        sum+=arr[i];
        count ++;
        if(sum>=total){
            return count;
        }
    }
    
    return 0;
    
}

8) You are given a function.
int CheckPassword(char str[], int n);
The function accepts string str of size n as an argument. Implement the function which returns 1 if given string str is valid password else 0.
str is a valid password if it satisfies the below conditions.
– At least 4 characters
– At least one numeric digit
– At Least one Capital Letter
– Must not have space or slash (/)
– Starting character must not be a number
Assumption:
Input string will not be empty.
bool password(string s){
    bool size=false;
    if(s.length()>=4){
        size= true;
    }
    bool is_numeric= false;
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i])){
            is_numeric=true;
        }
    }
    bool is_capital= false;
    for(int i=0;i<s.length();i++){
        if(isupper(s[i])){
            is_capital=true;
        }
    }
    bool start=true;
    if(isdigit(s[0])){
        start= false;
    }
    bool is_slash=true;
    for(int i=0;i<s.length();i++){
        if(s[i]=='/' || s[i]==' '){
            is_slash=false;
            break;
        }
    }
    return size && is_capital && start && is_numeric && is_slash; 
}

9) void greatest(int arr[], int n){
    int min=INT_MAX;                             ///  for max    int max= INT_MIN;
    int index=-1;                                ////     if(arr[i]>max){ max= arr[i]; index=i;}
    for(int i=0;i<n;i++){   /// iterates through n as not comparing between i and i+1;
        if(arr[i]<min){
            min=arr[i];
            index=i;
        }
    }
    cout<<"Element"<<min<<endl;;
    cout<<"Index"<<index;
    
}

10) distance between 3 points (x1, y1) (x2, y2) (x3, y3)
     double distance(int x1,int x2,int x3,int y1,int y2,int y3){
    double a= sqrt(pow(x2-x1,2) + pow(y2-y1,2));
    double b= sqrt(pow(x3-x2,2) + pow(y3-y2,2));
    return a+b;
}

11) Counting number of carries in the sum of two numbers
int is_carry(int a, int b){
    int carry=0;
    int sum=0;
    int count=0;
    int factor=1;
    int digit_sum=0;
    while(a!=0 || b!=0){
        digit_sum=a%10 +b%10 + carry;
        if(digit_sum>9){
            carry=1;
            count++;
        }
        else{
            carry=0;
        }
        sum+=(digit_sum%10)*factor;
        factor*=10;
        a=a/10;
        b=b/10;
    }
    return count;
}


12) Write a program to check if two strings are anagrams of each other. An anagram is a word or phrase formed by rearranging 
the letters of another word or phrase. Your program should return True if the two input strings are anagrams, and False 
otherwise.
For example, if the input strings are "listen" and "silent", the program should return True, as both strings can be rearranged 
to form the same letters.
Write a program that takes two strings as input and determines whether they are anagrams or not.
Sample input1:                  Sample input 2:                                   
listen                               hello
silent                               world
Sample output1:                Sample output 2:
True                                 false

bool anagram(string a, string b) {
    // Check if the lengths of both strings are the same
    if (a.length() != b.length()) {
        return false;
    }

    int arr1[26] = {0};  // Array to store frequency of characters in string a
    int arr2[26] = {0};  // Array to store frequency of characters in string b

    for (int i = 0; i < a.length(); i++) {
        int ch1 = a[i] - 'a';
        int ch2 = b[i] - 'a';
        arr1[ch1]++;
        arr2[ch2]++;
    }

    // Compare the frequency arrays
    for (int i = 0; i < 26; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }

    return true;
}




13) ///////////  MEDIAN of array  ////////////
int main() {
    // Write C++ code here
    vector<int> arr={2,5,1,7};
    sort(arr.begin(), arr.end());
    float median;
    if(arr.size()%2==1){
        median= arr[arr.size()/2];
    }
    else{
        median= (arr[arr.size()/2] + arr[arr.size()/2-1])/2.0;
    }
    cout<<median;
    return 0;
}



14)  Equilibrium Index
int equilibrium_index(vector<int> arr, int size){
    int left=0;
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    int right= sum;
    for(int i=0; i< size; i++){
        
        right-= arr[i];
        if(left==right){
            return i;
        }
        left += arr[i];
    }
    return -1;
}







Maximum or minimum word in a string
string word(const string& a) {
    int s = 0;       // Start index of the current word
    int maxi = 0;    // Maximum length of the word found
    int start = 0;   // Start index of the longest word
    int e=0;
    for (int i = 0; i < a.length(); i++) {
        // Use a while loop to find the end of the current word
        int e = i;
        while (e < a.length() && a[e] != ' ') {
            e++;
        }

        // Calculate the length of the current word
        int length = e - s;
        if (length > maxi) {
            maxi = length;
            start = s;
        }

        // Move the start index to the next word
        i = e; // Skip over the current word
        s = i + 1; // Update start index for the next word
    }

    return a.substr(start, maxi);
}

