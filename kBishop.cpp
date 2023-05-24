#include<iostream>
#include<cmath>
using namespace std;

bool ok(int board[], int col, int n) {
  // board[col] / n = row
  // board[col] % n = column
  for(int i = 0; i < col; i++) {
    if(((board[col] / n) - (board[i] / n)) == abs((board[col] % n) - (board[i] % n))) {
      return false;
    }
  }
  return true;
}

int findKBishops(int n, int k) {
  int *board = new int[k]; // dynamically allocate the array size, k, in a heap memory
  int count = 0;
  int col = 0;
  board[0] = 0; // the first bishop will be set in square 0

  while(col >= 0) {
    col++;
    if(col == k) {
      count++;
      col--; // backtrack
      
    }
    else {
      board[col] = board[col - 1];
    }
    while(col >= 0) {
      board[col]++;
      if(board[col] == n*n) 
        col--; //if the bishop position is equal to the number of squares in the board, go back a column (backtracking)
     else if(ok(board,col, n)) {
        break;
     }
    }
  }
  delete[] board; // returns memory to the pool
  return count; // returns the number of solutions
  
}

int main() {
int n, k; // declare variables n and k
  
  while(true) {
    cout << "Enter a value of n: "; // reads value for n
  cin >> n;
    if(n == -1) // the program will terminate if the user enters -1 for n
      return 0;
  cout << "Now enter a value of k: "; // reads value for k
    cin >> k;
    if(k > n) // k must me less than or equal to n, otherwise the program terminates
      return 0;
  
  cout << "The number of bishops for this k Bishop is " << findKBishops(n, k) << endl;
  }
  return 0;
}