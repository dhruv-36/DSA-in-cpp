// void swap_alternates(int arr[], int size){
//     for(int i=0;i<size;i=i+2){
//         swap(arr[i],arr[i+1]);
//         if(arr[i]==size-1){               // This is done in order to put the last element in the same order if(size is odd)
//             break;
//         }
//     }

//     for(int i=0;i<size;i++){
//     cout<<arr[i]<<" ";
//     }
// }


//   Binary Search //
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 6, 8, 12, 43, 56};
    int element = 42;
    int size = sizeof(arr) / sizeof(arr[0]);
    int start = 0;
    int end = size - 1;
    int count = 0;

    while (start <= end) {  // Correct condition
        int mid = (start + end) / 2;
        if (arr[mid] == element) {
            count = 1;  // Correct assignment
            break;
        } else if (arr[mid] > element) {
            end = mid-1 ;  
        } else {
            start = mid+1 ;  
        }
    }

    if (count == 1) {
        cout << "yes";
    } else {
        cout << "no";
    }

    return 0;
}



////   Fast Exponentiation /////

int Fast_Exponentiation(int x, int n) {
	int rel=1;
	while(n!=0){
	    if(n%2==1){
	        rel=rel*x;
	    }
		x=x*x;
		n=n>>1;
	}
	
	return (rel);
}





/////////// First & Last Position in a Sorted Array  //////////

int firstPosition(vector<int>& arr, int n, int k){
    int start=0;
    int end=n-1;
    int rel=-1;  // if not find any occurenece, return -1
    while(start<=end){
        int mid=(start+end)/2;
        if(k==arr[mid]){
            rel=mid;
            
            end=mid-1;
        }
        else if(k<arr[mid]){
            end=mid-1;
        }
        else {
            start=mid+1;
        }
    }

    
    return rel;
    

}

int lastPosition(vector<int>& arr, int n, int k){
    int start=0;
    int end=n-1;
    int rel=-1;  // if not find any occurenece, return -1
    while(start<=end){
        int mid=(start+end)/2;
        if(k==arr[mid]){
            rel=mid;
            
            start=mid+1;
        }
        else if(k<arr[mid]){
            end=mid-1;
        }
        else {
            start=mid+1;
        }
    }

    
    return rel;
    

}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int first=firstPosition( arr,  n,  k);
    int last= lastPosition( arr,  n,  k);
    pair<int, int> p;
    p.first=first;
    p.second=last;
    return p;

}

TOTAL OCCURENECE=(LAST-FIRST+1)






//////  Painter's Partition   ///////

bool istrue(vector<int> &boards, int k, int mid){
    int size=boards.size();
    int sum=0;
    int count=1;
    for(int i=0;i<size;i++){
        if(sum+ boards[i]<=mid){
            sum +=boards[i];
        }
        else{
            count++;
            if(count> k || boards[i]> mid){
                return false;
            }
            sum=boards[i];
        }
    }
    return true;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int start=0;
    int end;
    int size=boards.size();
    for(int i=0;i<size;i++){
        end +=boards[i];

    }
    int ans=-1;
    
    while(start<=end){
        int mid= (start+ end)/2;
        if(istrue(boards, k, mid)){
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans;
}



/////////////////////////////  Pivot Element  //////////////////////////

int main(){
    int arr[]={7,9,10,12,13,1,2,3};
    int start=0; 
    int end=8-1;
    int pivot=-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]<arr[mid+1]&& arr[mid]<arr[mid-1]){
            pivot=arr[mid];
            break;
        }
        else if(arr[mid]<arr[mid+1] && arr[mid]>arr[mid-1]){
            start=mid+1;
        }
        else if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
            end=mid-1;
        }
    }
    cout<< pivot;
        
    return 0;
}




/////////////////////////////////////   Precise Square Root  ////////////////////////////////
#include <iostream>
using namespace std;

int floorSqrt(int n) {
    if (n == 0 || n == 1) return n;

    int start = 0;
    int end = n;
    int ans = 0;

    while (start <= end) {
        long long int mid = start + (end - start) / 2;  // Prevent overflow

        // Check if mid is a perfect square
        if (mid * mid == n) {
            return mid;
        }

        // If mid*mid is less than n, move start to mid + 1
        if (mid * mid < n) {
            ans = mid; // Update answer to mid, since mid*mid is still less than n
            start = mid + 1;
        } else {
            // If mid*mid is greater than n, move end to mid - 1
            end = mid - 1;
        }
    }

    return ans;
}

double preciseSQUARE_ROOT(int squareRoot, int precision, int num) {
    double factor = 1;
    double anss = squareRoot;
    double ans;

    for (int i = 0; i < precision; ++i) {
        factor /= 10;
        for (double j = anss; j * j < num; j += factor) {
            ans = j;
        }
    }

    return ans;
}

int main() {
    int num = 37;
    int squareRoot = floorSqrt(num);
    double preciseRoot = preciseSQUARE_ROOT(squareRoot, 3, num); // Example precision to 3 decimal places
    cout << "The precise square root of " << num << " is " << preciseRoot << endl;

    return 0;
}


/////////////////////////////////      Square Root ///////////////////////////////

int floorSqrt(int n) {
    if (n == 0 || n == 1) return n;

    int start = 0;
    int end = n;
    int ans = 0;

    while (start <= end) {
        long long int mid = start +(end-start) / 2;          excecption handling

        // Check if mid is a perfect square
        if (mid * mid == n) {
            return mid;
        }

        // If mid*mid is less than n, move start to mid + 1
        if (mid * mid < n) {
            ans = mid; // Update answer to mid, since mid*mid is still less than n
            start = mid + 1;
        } else {
            // If mid*mid is greater than n, move end to mid - 1
            end = mid - 1;
        }
    }

    return ans;  // in the function if something is not returned, then return ans(like -1 for bool/ int)
}




///////////////  GFG   /////////

Array Leaders
vector<int> leaders(int n, int arr[]) {
        // Code here
        vector<int> rel;
        for(int i=0; i<n;i++){
            int j=n-1;
            bool is=true;
            while(j!=i || arr[i]!=arr[j]){
                if(arr[i]<arr[j]){
                    is=false;
                    break;
                }
                else{
                    j--;
                }
            }
            if(is){
                rel.push_back(arr[i]);
            }
        }
        return rel;
    }



Maximum Score from Subarray Minimums
int pairWithMaxSum(vector<int> &arr) {
        // Your code goes here
         int maxi=INT_MIN;
       int n= arr.size();
       for(int i=0;i<n-1;i++){
           if((arr[i]+arr[i+1])>maxi){
               maxi=(arr[i]+arr[i+1]);
           }
       }
       return maxi;
    }


Sum of all divisors from 1 to n
long long sumOfDivisors(int N)
    {
        // Write Your Code here
        long long sum=0;
        for(int i=1;i<=N;i++){
            long long s=0;
            int j=1;
            while(j<=i){
                if(i%j==0){
                    s+=j;
                }
                j++;
            }
            j=1;
            sum+=s;
        }
        return sum;
    }
    
    // // Write Your Code here
    //     long long sum = 0;
    
    //     for(int i = 1; i <= N; i++) {
    //         sum += (N / i) * i;
    //     }
        
    //     return sum;
    // }



    
/////////////Union of Two Sorted Arrays  /////////
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        vector<int> rel;
        map<int, int>p;
        for(int i=0;i<n;i++){
            int a= arr1[i];
            p[a]++;
        }
        for(int i=0;i<m;i++){
            int a= arr2[i];
            p[a]++;
        }
        for(auto it=p.begin(); it!=p.end();it++){
            if(it->second>=1){
                rel.push_back(it->first);
            }
        }
        //sort(rel.begin(), rel.end());
        return rel;
    }




