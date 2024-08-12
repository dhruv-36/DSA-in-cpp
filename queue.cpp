#include<iostream>
#include<queue>
using namespace std;

int main() {






///////    Doubly Ended Queue  /////////  STL 



    deque<int> d;

    d.push_front(12);
    d.push_back(14);

    cout << d.front() << endl;
    cout << d.back() << endl;

    d.pop_front();
    
    cout << d.front() << endl;
    cout << d.back() << endl;
    d.pop_back();

    if(d.empty()) {
        cout << "queue is empty" << endl;
    }
    else{
        cout << "queue is not empty " << endl;
    }



///////////////    Simple Queue  ////////  STL //

    //create a queue
    queue<int> q;

    q.push(11);
    cout << "front of q is: " << q.front() << endl;
    q.push(15);
    cout << "front of q is: " << q.front() << endl;

    q.push(13);
    cout << "front of q is: " << q.front() << endl;

    cout << "size of queue is : " << q.size() << endl;

    q.pop();
    q.pop();
    q.pop();

    cout << "size of queue is : " << q.size() << endl;

    if(q.empty()) {
        cout << "Queue is empty " << endl;
    }
    else{
        cout << "queue is not empty " << endl;
    }
  


    return 0;
}







GFG Questions
1) ///// Queue Reversal   //////
queue<int> rev(queue<int> q)
    
    {
        stack<int> s;
        while(!q.empty()){
            s.push(q.front());
            q.pop();
        }
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
        return q;
    }

b)  Recursive Approach ///
void reverse(queue<int> &q){
        if(q.empty()){
           return;
       }
       int e= q.front();
       q.pop();
       reverse(q);
       q.push(e);
    }
    queue<int> rev(queue<int> q)
    {
        // add code here.
        reverse(q);
        return q;
       
    }



2) ///// First negative in every window of size k   ////////

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
            deque<long long int> q;
            vector<long long int> rel;
            for(int i=0;i<K;i++){
                if(A[i]<0){
                    q.push_back(i);
                }
                
            }
            if(q.size()>0){
                rel.push_back(A[q.front()]);
            }
            else{
                rel.push_back(0);
            }
            
            for(int i=K;i<N;i++){
                if(!q.empty() && i-q.front()>=K){
                    q.pop_front();
                }
                
                if(A[i]<0){
                    q.push_back(i);
                }
                if(q.size()>0){
                rel.push_back(A[q.front()]);
                }
                else{
                    rel.push_back(0);
                }
            }
            return rel;
 }


3) //// Reverse First K elements of Queue ////
void reverse(queue<int> &q, int k, int count){
        if(q.empty()|| count==k){
           return;
       }
       int e= q.front();
       q.pop();
       reverse(q, k, count+1);
       q.push(e);
    }
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        reverse(q, k, 0);
        for(int i=0; i<q.size()-k;i++){
            int a= q.front();
            q.pop();
            q.push(a);
            
        }
        return q;
    }



4)   ///// First non-repeating character in a stream///
string FirstNonRepeating(string A){
		    // Code here
		      queue<char> q;
		      unordered_map<char, int> map;
		      string s="";
		      for(int i=0; i<A.length();i++){
		          q.push(A[i]);
		          map[A[i]]++;
		            
		          while(!q.empty()){
		              if(map[q.front()]>1){
		                  q.pop();
		              }
		              else{
		                  s.push_back(q.front());
		                  break;
		              }
		          }
		          if(q.empty()){
		              s.push_back('#');
		          }
		      }
		      return s;
		}

5) 
