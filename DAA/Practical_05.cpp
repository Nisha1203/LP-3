//Design n-Queens matrix having first Queen placed. Use backtracking to place remaining 
//Queens to generate the final n-queen‘s matrix

#include<bits/stdc++.h>
using namespace std;

// 2. The `isSafe` function checks if it is safe to place a queen at a given position. It takes the current state of the board, 
//the position (x, y), and the size of the board 'n' as input parameters.It checks the rows, columns, and diagonals to ensure 
//that no other queen can attack the current position.
bool isSafe(int **arr, int x, int y, int n){ //here y is column
    //The loop checks all rows above the current row x to see if there is already a queen placed in the same column y.
    for(int row=0;row<x;row++){ 
        if(arr[row][y]==1){
            return false;
        }
    }

    int row =x;
    int col =y;
    //It checks if there is any queen placed on the upper-left diagonal.
    while(row>=0 && col>=0){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col--;
    }

    row =x;
    col =y;
    // It checks if there is any queen placed on the upper-right diagonal.
    while(row>=0 && col<n){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col++;
    }

    return true;
}

// 3. The `printBoard` function is used to print the current state of the board. It takes the 2D array representing the board 
//and the size 'n' as input parameters.It prints '[]' for empty positions and '[Q]' for the positions with a queen.
void printBoard(int **arr, int n){
	for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
			if(arr[i][j] == 1) cout << "[Q]";
			else cout << "[]";
		}
        cout << endl;
	}
	cout << endl;
	cout << endl;
}

// 4. The `nQueen` function is the main function that implements the backtracking approach for solving the N-Queens problem. 
// It takes the current state of the board, the current row 'x', and the size 'n' as input parameters. It recursively tries to 
//place the queens in safe positions,backtracking when it's not possible to place the queens any further.
void nQueen(int** arr, int x, int n){
    if(x == n){ 
        printBoard(arr, n);
		return;
    }

    for(int col=0;col<n;col++){
        if(isSafe(arr,x,col,n)){
            arr[x][col]=1;
            nQueen(arr,x+1,n);
            arr[x][col]=0;
        }
    }
}

// 5. In the `main` function, the code takes the input for the size of the board 'n' and initializes a 2D array 'arr' to represent the board. 
// It then calls the `nQueen` function with the initial row set to 0.
int main(){
    int n;
    cin >> n;
    
    //int **arr = new int*[n]; - This line creates a pointer arr that points to an array of pointers. 
    //Here, the new int*[n] part allocates memory for an array of size 'n' that stores pointers to integers.
    int **arr = new int*[n];    
    for(int i=0;i<n;i++){
        arr[i] = new int[n];// This loop iterates 'n' times and allocates memory for each row of the 2D array
        for(int j=0;j<n;j++){
            arr[i][j]=0; // This nested loop initializes all elements of the 2D array to 0.
        }
    }
	
	nQueen(arr, 0, n);
	
	cout << "--------All possible solutions--------";
	
    return 0;
}

/*
Time Complexity: O(N!)
Auxiliary Space: O(N^2)
*/

// 6. After printing all possible solutions, the code prints the message "--------All possible solutions--------".

// 7. Finally, the code includes the time and space complexity analysis as comments.

// The time complexity is O(N!), where N is the number of queens (and the dimensions of the board). The algorithm generates all possible configurations
//  of the N-Queens problem, resulting in factorial time complexity. The auxiliary space complexity is O(N^2), representing the space 
//used by the 2D array to represent the chessboard.