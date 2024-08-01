void sum_anti_diagonal(int arr1[3][3],int column, int row ){
	int sum=0;
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			
				cout<<arr1[i][j];
		}
		cout<<endl;
	
	}
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			if(j+i==(column-1)){    //// Check the condition w.r.t the position with column and row of the array for satisfying anti diagonal sum condn.
				sum+=arr1[i][j];
			}	
		}
	
	}
	cout<<sum;
}








///////////////////////////   2-D Arrays   ///////////////////////////////

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








///////////////////////////////    IIMMPP    2-D Array Dynamically    /////////////////////////////////


#include <iostream>
using namespace std;

int main() {

    int row;
    cin >> row;

    int col;
    cin >> col;

    //creating a 2D array
    int** arr = new int*[row];
    for(int i=0; i<row; i++) {
        arr[i] = new int[col];
    }

    //taking input
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cin >> arr[i][j];
        }
    }

    //taking output
    cout << endl;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cout << arr[i][j] << " ";
        } cout << endl;
    }


    //releasing memory
    for(int i=0; i<row; i++) {
        delete [] arr[i];
    }   

    delete [] arr;

    //how to create a 2D array dynamically
    //input/Output
    //memory free kaise karani hai 

    return 0;
}


