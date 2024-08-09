//////  STL STACK   //////
 //creation of stack
    stack<int> s;

    //push operation
    s.push(2);
    s.push(3);

    //pop
    s.pop();

    cout << "Printing top element " << s.top() << endl;

    if(s.empty()){
        cout << "Stack is empty " << endl;
    }
    else{
        cout << "stack is not empty " << endl;
    }

    cout << "size of stack is " << s.size() << endl;

  





////    STACK IMPLEMENTATION   /////
#include<iostream>
using namespace std;

class Stack{
    // properties   ( attributes)
    public:
    //int *arr;: This line declares a pointer to an integer, named arr. In the context of a stack, arr will typically be used to point to the dynamically allocated array that stores the stack elements//
    int *arr;
    int top;
    int size;
    
    // behaivour  ( constructor, functions,  destructor)
    Stack (int size){  //  constructor ( once its created all the attributes set like this by itself)
        this-> size=size;
        arr= new int[size];
        top  = -1;
    }
    void push(int element){
        if(size-top>1){
            top ++;   //// update first then fill the element into the stack( IMP)
            arr[top]=element;
        }
        else{
            cout<<"stack Overflow"<<endl;
        }
    }
    void pop(){
       // int ans= arr[top];       IMP: return the top element after the pop operation      IMMPPPP
        if(top>=0){
            top--;
            //return ans;
        }
        else{
            cout<<"Stack Underflow";
        }
    }
    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"stack is Empty";
            return -1;   /// need to return a Integer Value(COMPULSORY)
        }
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        
        return false;
        cout<<endl;
    }
    void print(){
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
};

int main(){
    Stack Stack(2); 
    Stack.push(1);
    Stack.push(2);
    Stack.push(3);
    Stack.print();
    Stack.pop();
    Stack.print();
    cout<<Stack.peek();
    Stack.pop();
    Stack.pop();
    cout<<Stack.isEmpty();
    cout<<endl;
    cout<<Stack.peek();
    
}




////////   Reverse a String Using Stack   ///////
int main(){
    stack <char> stack;
    string s="abcd";
    string ans="";
    for(int i=0;i<s.length();i++){
        stack.push(s[i]);
    }
    while(!stack.empty()){    /////      stack not empty
        char ch=stack.top();
        ans.push_back(ch);
        stack.pop();
    }
    cout<<ans;
}




Celebrity Problem(GFG)
App1:  Brute Force
int celebrity(vector<vector<int> >& mat) {
        
        // code here
        
        
        for(int i=0;i<mat.size();i++){
            // columns
            bool isCeleb= true;
            for(int j=0; j<mat.size();j++){
                if(i!=j && mat[j][i]==0 ){
                    isCeleb= false; 
                    break;
                }
            }
            if(isCeleb){
                // row
                for(int j=0; j<mat.size();j++){
                    if(i!=j && mat[i][j]==1){
                        isCeleb=false;
                        break;
                    }
                }
            }
            if(isCeleb){
                return i;
                break;
            }
        }
        return -1;
    }

App2: Stack
 int celebrity(vector<vector<int> >& mat) {
        
        // code here
        
        
        stack<int> s;
        for(int i=0;i<mat.size();i++){
            s.push(i);
        }
        while(s.size()!=1){
            int a= s.top();
            s.pop();
            int b= s.top();
            s.pop();
            if(mat[a][b]==1){
                s.push(b);
            }
            else if( mat[b][a]==1){
                s.push(a);
            }
        }
        int a= s.top();
        
        bool col= false;
        int countr=0;
        int countc=0;
        bool row= false;
        for(int i=0; i< mat.size();i++){
            if(mat[i][a]==1){
                countr++;
            }
        }
        if(countr== mat.size()-1){
            row=true;
        }
        for(int i=0; i< mat.size();i++){
            if(mat[a][i]==0){
                countc++;
            }
        }
        if(countc== mat.size()){
            col=true;
        }
        if(col && row){
            return a;
        }
        else{
            return -1;
        }
    }
