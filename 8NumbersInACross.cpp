#include <iostream>
#include <cmath>
using namespace std;



bool ok(int board[], int col) {
	static int array[8][5] = { // helper array
		{-1},
		{0, 1},
		{0, 1, -1},
		{0, 2, -1},
		{1, 2, -1},
		{1, 2, 3, 4, -1},
		{2, 3, 5, -1},
		{4, 5, 6, -1},
	};

	for(int i = 0; i < col; i++) {	// row test
              if(board[i] == board[col]) {
		      return false;
	      }
	}

	for(int i = 0; array[col][i] != -1; i++) {
		// check is the numbers are consecutive
		if(abs(board[col] - board[array[col][i]]) == 1) {
			return false;
		}
	}
	return true;
}


void print(int board[]) {
	static int counts = 0;
	cout << "Solution # " << ++counts << endl;
	cout << " " << board[1] << " " << board[4] << endl;
        cout << board[0] << " " << board[2] << " " << board[5] << " " <<  board[7] << endl;
        cout << " " << board[3] << " " << board[6] << endl;
}
//prints all possible solution.

void backtrack(int& col) {
	col--;
	if(col == -1)
		exit(1); // if col is below 1, the program terminates since all the solutions were found
}

int main() {
	int board[8] = {0};
	int col = 0;
	board[col] = 1;

                      while(col >= 0) {
			col++;
			if(col == 8) {
				print(board);
				backtrack(col);
			}
			else {
				board[col] = 0;
			}
			while(col >= 0) {
				board[col]++;
				if(board[col] > 8) { // if no solutions were found in a row, backtrack
					backtrack(col);
					continue;
				}
				else if(ok(board,col)) {// if the number is ok go to next col
					break;
				}
			}
		}
		
	return 0;
}


