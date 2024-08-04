//////// //Function to find the maximum occurring character in a string  ////////////
    

class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        int arr[26]={0};
        int size=str.length();
        
        for(int i=0;i<size;i++){
            int number=0;
            if(str[i]>='a' && str[i]<='z'){
                number=str[i]-'a';
                arr[number] ++;
            }
            else if(str[i]>='A' && str[i]<='Z'){
                number=str[i]-'A';
                arr[number] ++;
            }
            
        }
        int max=0;
        int ans=0;
        for(int i=0;i<26;i++){
            if(arr[i]>max){
                max=arr[i];
                ans=i;
            }
        }
        char rel='a'+ans;
        return rel;
    }

};





////////  Palindrome   /////////////////

int String_Length(string s) {
    int length = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        length++;
    }
    return length;
}

char Upper_to_Lower(char ch){
     char temp;
     if(ch>='A' && ch <='Z'){
         temp = ch - 'A' + 'a';
         return temp;
     }
     return ch;
}

bool check_upper(char ch){
     if (ch >= 'A' && ch <= 'Z') {
         return true;
     }
     return false;
}

bool check_lower(char ch){
     if (ch >= 'a' && ch <= 'z') {
         return true;
     }
     return false;
}
bool check_numeric(char ch){
    if(ch>='0' && ch<='9'){
        return true;
    }
    return false;
}
bool checkPalindrome(string s) {
    int start = 0;
    int end = String_Length(s) - 1;
    while(start <= end){
        if(!check_upper(s[start]) && !check_lower(s[start]) && !check_numeric(s[start])){
            start++;
            continue;
        }
        if(!check_upper(s[end]) && !check_lower(s[end]) && !check_numeric(s[end])){
            end--;
            continue;
        }
        if(Upper_to_Lower(s[start]) != Upper_to_Lower(s[end])){
            return false;
        }
        start++;
        end--;
    }
    return true;
}











/////////////////  Reverse Words in a Given String //////////////////////////////

#include <bits/stdc++.h>
using namespace std;

bool is_space(char ch) {
    return ch == ' ';
}

string reverseString(string str) {
    // Reverse the entire string
    reverse(str.begin(), str.end());

    int start = 0;

    // Reverse each word in the reversed string
    for (int i = 0; i <= str.length(); i++) {
        if ( is_space(str[i]) || i == str.length() ) {
            reverse(str.begin() + start, str.begin() + i);
            start = i + 1;
        }
    }

    return str;
}

int main() {
    string str = "the sky is blue";

    // Function call
    string rev = reverseString(str);

    // Print the reversed string
    cout << rev;
    return 0;
}
















GFG 
Maximum Occuring Character
char getMaxOccuringChar(string str)
    {
        // Your code here
        int arr[26]={0};
        int size=str.length();
        
        for(int i=0;i<size;i++){
            int number=0;
            if(str[i]>='a' && str[i]<='z'){
                number=str[i]-'a';
                arr[number] ++;
            }
            else if(str[i]>='A' && str[i]<='Z'){
                number=str[i]-'A';
                arr[number] ++;
            }
            
        }
        int max=0;
        int ans=0;
        for(int i=0;i<26;i++){
            if(arr[i]>max){
                max=arr[i];
                ans=i;
            }
        }
        char rel='a'+ans;
        return rel;
    }
    
    
    
    ///  APPROACH 2  MAP
    
    
    /*unordered_map< char, int> map;
        for(int i=0;i<str.length();i++){
            map[str[i]]++;
        }
        
        int maxCount = 0;
        char maxchar;
       
        
        
        for(auto it : map){
            if(it.second > maxCount ||  it.second == maxCount && maxchar> it.first){
                maxCount = it.second;   /// count to barabar hai purane ka but naya char kam hai purane se(lexicographically smaller character) 
                maxchar=it.first;
               
            }
        }
        return maxchar;
    } */






First non-repeating character in a stream

string FirstNonRepeating(string A){
		    map<char, int> m;
		    string ans = "";
		    queue<char> q;
		    
		    for(int i=0; i<A.length(); i++) {
		        char ch = A[i];
		        
		        //// queue me push karo
		        q.push(ch);
		        
		        ////   increase count
		        m[ch]++;
		        
		        while(!q.empty()) {
		            if(m[q.front()] > 1){
		                // repeating character
		                q.pop();
		            }
		            else
		            {
		                // non-repeating character found
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        if(q.empty()){
		            ans.push_back('#');
		        }
		    }
		    return ans;
		}

