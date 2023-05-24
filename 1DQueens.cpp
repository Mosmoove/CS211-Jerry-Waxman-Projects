#include<iostream>
#include<cmath>
using namespace std;


bool ok(int board[], int c) {
for(int i = 0; i < c; i++) {
	if((c - i) == abs(board[c] - board[i]) || board[i] == board[c]) {
		return false;
	}
}
return true;

}
void printSol(int board[]) {
	static int found = 0;
	cout << "Solution # " << ++found << endl;
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			if(board[i] == j) {
				cout << "1 ";// if array equals to j, print 1
			}
			else {
				cout << "0 ";// else print 0
			}
}
cout << endl;

}

}//Print function ends

int main() {
	int board[8] = {0};// set array to 0
	int c = 0;
	board[c] = 0;// b[0][0] = 1 in 2D version

	while(c >= 0) {
		if(c == 8) {
			printSol(board);
			c--;// backtrack
		}
		else {
			//reset queen
		        board[c] = -1;
		}
		while(c >= 0 && c < 8) {
			board[c]++;
			if(board[c] == 8) { // if end of column passes
				c--;// backtrack;
			}
		
		else if (ok(board, c) == true) { // check if queens place is ok
		c++;
		break;
		}
	}
}
return 0;
}
	


