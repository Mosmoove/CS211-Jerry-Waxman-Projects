#include<iostream>
using namespace std;

bool ok(int queen[], int size) {
	for(int c = 0; c < size; c++) {
		for(int j = 0; j < c; j++) {
			if(c - j == abs(queen[c] - queen[j]) || queen[c] == queen[j]) {
				return false;
			}
		}
	}
	return true;
}

void printArr(int queen[], int size, int count) {
	cout << "Solution # " << count << endl;

	for(int i = 0; i < size; i++) {
		for(int r = 0; r < size; r++) {
			if(queen[i] == r) {
				cout << "1";
			}
			else {
				cout << "0";
			}
		}
		cout << endl;
	}
}


int main() {
	int queen[8] = {0}, count = 0;

	for(int i0 = 0; i0 < 8; i0++) {
		for(int i1 = 0; i1 < 8; i1++) {
		       for(int i2 = 0; i2 < 8; i2++) { 
		            for(int i3 =0; i3 < 8; i3++) {
		     for(int i4 = 0; i4 < 8; i4++) {
	                  for(int i5 = 0; i5 < 8; i5++) {
	     for(int i6 =0; i6 < 8; i6++) {
                   for(int i7 = 0; i7 < 8; i7++) {
		   queen[0] =i0;
		   queen[1] = i1;
		   queen[2] = i2;
		   queen[3] = i3;
		   queen[4] = i4;
		   queen[5] = i5;
		   queen[6] = i6;
		   queen[7] = i7;

		   if(ok(queen, 8)) {
				   printArr(queen, 8, ++count);
				   }
				   }
				   }
				  }
				  }
				  }
				  }
				  }
				  }
				  return 0;
				  }


