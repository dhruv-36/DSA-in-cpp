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

5) ////////////   Circular Tour   //////////
int tour(petrolPump p[],int n)
    {
       int deficit = 0;
       int balance = 0;
       int start = 0;
       
       for(int i=0; i<n; i++) {
           balance += p[i].petrol - p[i].distance;
           if(balance < 0) {
               start = i+1;
               deficit += balance;
               balance = 0;
           }
       }
       
       if(balance + deficit >=0) 
            return start;
        return -1;
       
    }
};
////////////////////////  APPROACH 2 DEQUE ///////////////
{
       int balance = 0;
        int deficit = 0;
        int start = 0;
        int front = 0;
        int rear = 0;

        while (rear < n) {
            balance += p[rear].petrol - p[rear].distance;

            if (balance < 0) {
                // If balance is negative, reset front and rear
                start = rear + 1;
                front = start;
                rear = front;
                deficit += balance;
                balance = 0; // Reset balance for the next potential start
            } else {
                // If balance is positive or zero, move rear forward
                rear++;
            }

            // Base condition: If front == rear, check if tour is complete
            if (front == rear && balance + deficit >= 0) {
                return start;
            }
        }

        // After completing the loop, check if a valid start exists
        if (balance + deficit >= 0) {
            return start;
        }

        return -1; // If no valid starting point exists
}

6) Interleave of queue
queue<int> interleave( queue<int> &q){
    int mid= q.size()/2;
    queue<int> q1;
    int i=1;
    while(i<=mid){
        int e= q.front();
        q1.push(e);
        q.pop();
        i++;
    }
    while(!q1.empty()){
        int a= q1.front();
        q1.pop();
        q.push(a);
        int e= q.front();
        q.pop();
        q.push(e);
        
        
    }
    return q;
}



7) Sum of minimum and maximum elements of all subarrays of size k
Deque Handling for maxi and mini:      NOTE IMP
When you remove elements from the maxi and mini deques,
the comparisons should be done using the back of the deque (pop_back()), 
not the front. This is because you want to remove elements that are not useful anymore.
	
int sumWindow(int arr[], int N, int K) {
    deque<int> maxi;
    deque<int> mini;

    // Initialize the deques for the first window
    for (int i = 0; i < K; i++) {
        while (!maxi.empty() && arr[maxi.back()] <= arr[i]) {
            maxi.pop_back();
        }
        maxi.push_back(i);
        while (!mini.empty() && arr[mini.back()] >= arr[i]) {
            mini.pop_back();
        }
        mini.push_back(i);
    }

    int ans = 0;
    ans += arr[maxi.front()] + arr[mini.front()];

    // Process the rest of the windows
    for (int i = K; i < N; i++) {
        // Remove elements out of this window from the deques
        if (!maxi.empty() && maxi.front() <= i - K) {
            maxi.pop_front();
        }
        if (!mini.empty() && mini.front() <= i - K) {
            mini.pop_front();
        }

        // Add new elements to the deques
        while (!maxi.empty() && arr[maxi.back()] <= arr[i]) {
            maxi.pop_back();
        }
        maxi.push_back(i);
        while (!mini.empty() && arr[mini.back()] >= arr[i]) {
            mini.pop_back();
        }
        mini.push_back(i);

        // Add the max and min for this window to the sum
        ans += arr[maxi.front()] + arr[mini.front()];
    }

    return ans;
}
