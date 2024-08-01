

//////// (a^b )  Optimised O(logn)
int pow(int a, int b){
    // Base case
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    int ans= pow(a, b/2);   // recursive call (hum kyun krein ye kaam bhala)
    if(b%2==0){
        return ans*ans;
    }
    else {
        return a*ans*ans;
    }
}





///////////////////// Binary Search ////////////////////
bool binary_search(int arr[], int size, int start, int end, int element){
    // Base case:1 element not found
    if(start>end){
        return false;
    }
    int mid= (start+end)/2;
    // Base case 2: elemnt found 
    if(element==arr[mid]){
        return true;
    }
    else if (arr[mid]>element){
        return binary_search(arr, size, start, mid-1, element);
    }
    else{
        return binary_search(arr, size, mid+1, end, element);
    }
}









/////////////////////////    Bubble_Sort ///////////////////////////
void bubble_sort(int* arr, int n){
    // Base case
    if(n==0 || n==1){
        return;
    }
    for(int i=1;i<n;i++){
        if(arr[i-1]>arr[i]){
            swap(arr[i-1], arr[i]);
        }
    }
    bubble_sort(arr, n-1);
} 








///////////////////////////   check_palindrome  //////////////////////

bool check_palindrome(string& s, int start, int end){
    // Base case
    if(start>end){
        return false;
    }
    if(s[start]!=s[end]){
        return false;
    }
    return (s, start+1, end-1);
}







/////////////////////  Linear Search  ////////////////
bool linear_search(int arr[], int n, int element){
    if(n==0){
        return false;
    }
    if(arr[0]==element){
        return true;
    }
    return linear_search(arr+1, n-1, element);
}






//////////////// Quick Sort ///////////////
int partition(int *arr, int s, int e) {
    int pivot = arr[s];
    int count = 0;

    // Count how many elements are less than the pivot
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] < pivot) {
            count++;
        }
    }

    // Place the pivot at the correct position
    int pivot_index = s + count;
    swap(arr[s], arr[pivot_index]);

    // Initialize pointers for the partitioning process
    int start = s;
    int end = e;

    while (start < pivot_index && end > pivot_index) {
        // Increment start until we find an element greater than the pivot
        while (arr[start] <= pivot) {
            start++;
        }
        // Decrement end until we find an element less than the pivot
        while (arr[end] > pivot) {
            end--;
        }
        // Swap elements to ensure correct partitioning
        if (start < pivot_index && end > pivot_index) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }

    return pivot_index;
}

void quick_sort(int* arr, int s, int e) {
    // Base case: If the segment is already sorted
    if (s >= e) {
        return;
    }

    // Partition the array and get the pivot index
    int pivot_index = partition(arr, s, e);

    // Recursively sort the left and right partitions
    quick_sort(arr, s, pivot_index - 1);
    quick_sort(arr, pivot_index + 1, e);
}












/////////////////////// Say Number  ///////////////////////////
void say_number(long long int n){
    string rel[10]={"Zero","One", "Two" , "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    if(n== 0){
        return ;
    }
    say_number(n/10);
    cout<< rel[n%10]<<" ";
}

// Array is sorted or not 

bool is_sorted(int arr[], int n){
    int m =n-1;
    if(m<=0){
        return true;
    }
    if(arr[1]<arr[0]){
        return false;
    }
    return is_sorted(arr+1, n-1);
}







///////////////////  String Reverse  ////////////////////////
void reverse(string& s, int start, int end){
    // Base case
    if(start>end){
        return;
    }
    // char temp;
    // temp=s[start];
    // s[start]=s[end];
    // s[end]=temp;
    swap(s[start],s[end]);
    start++;
    end--;
    reverse(s, start, end);
}







///////////////////////// Sum of Array  //////////////////////
int sum(int arr[], int n){
    int summ=0;
    if(n==1){
        return arr[0];
    }
    int continous_sum=sum(arr+1, n-1);   ///  need something that can be passed to next function as sum will  again =0 as function calls itself for next pass
    summ=continous_sum+arr[0];
    sum(arr+1, n-1);
    return summ;
}






//////////////////////////////// Rat in the Maze  ////////////////////////////////

class Solution {
private:
    bool is_possible(int new_x, int new_y, vector<vector<int>>& visited, vector<vector<int>> &m, int n) {
        // Correct boundary check and visited condition check
        if (new_x < n && new_x >= 0 && new_y < n && new_y >= 0 && m[new_x][new_y] == 1 && visited[new_x][new_y] == 0) {
            return true;
        }
        return false;
    }

    void solution(vector<vector<int>> &m, int n, int x, int y, vector<string>& ans, string output, vector<vector<int>>& visited) {
        // Base case: reached the bottom-right corner
        if (x == n-1 && y == n-1) {
            ans.push_back(output);
            return;
        }
        
        // Mark the current cell as visited
        visited[x][y] = 1;
        
        // Movement in the order: Down, Left, Right, Up to maintain lexicographical order
        int new_x, new_y;
        
        // Move Down
        new_x = x + 1;
        new_y = y;
        if (is_possible(new_x, new_y, visited, m, n)) {
            output.push_back('D');
            solution(m, n, new_x, new_y, ans, output, visited);
            output.pop_back();
        }
        
        // Move Left
        new_x = x;
        new_y = y - 1;
        if (is_possible(new_x, new_y, visited, m, n)) {
            output.push_back('L');
            solution(m, n, new_x, new_y, ans, output, visited);
            output.pop_back();
        }

        // Move Right
        new_x = x;
        new_y = y + 1;
        if (is_possible(new_x, new_y, visited, m, n)) {
            output.push_back('R');
            solution(m, n, new_x, new_y, ans, output, visited);
            output.pop_back();
        }
        
        // Move Up
        new_x = x - 1;
        new_y = y;
        if (is_possible(new_x, new_y, visited, m, n)) {
            output.push_back('U');
            solution(m, n, new_x, new_y, ans, output, visited);
            output.pop_back();
        }
        
        // Unmark the current cell (backtracking)  its being done at the end to beginning when touched the base case then function recall to mark 1 to 0 to find other any possible way to traverse
        visited[x][y] = 0;
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Initialize the visited matrix to 0 for all elements
        vector<vector<int>> visited(n, vector<int>(n, 0));

        // Result vector
        vector<string> ans;
        
        // Start point is blocked
        if (m[0][0] == 0) {
            return ans;
        }

        // Start the solution
        string output = "";
        solution(m, n, 0, 0, ans, output, visited);
        
        // Sort the paths lexicographically
        sort(ans.begin(), ans.end());
        return ans;
    }
};




