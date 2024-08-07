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
        if(top>=0){
            top--;
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




