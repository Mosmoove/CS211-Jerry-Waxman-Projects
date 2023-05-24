#include <iostream>
#include <cmath>
using namespace std;

bool ok(int board[], int c)
{
  for (int i = 0; i < c; i++)
  {
    if ((c - i) == abs(board[c] - board[i]) || board[i] == board[c])
      return false;
  }
  return true;
}

void printSol(int board[])
{
  static int found = 0;
  int i, j, k, l;
  typedef char box[5][7]; // making the board a pointer so that it can point to specific items
  box bb, wb, *board1[8][8];
  box bq, wq; // black and white queens (bq = black queen, wq = white queen)
  cout << "Solution #" << ++found << endl;
  // bb=black box and wb = white box
  for (i = 0; i < 5; i++)
    for (j = 0; j < 7; j++)
    {
      wb[i][j] = ' ';       // prints white boxes
      wq[i][j] = ' ';       // white queen
      bb[i][j] = char(219); // black box
      bq[i][j] = char(219); // black queen
    }
  // to make the queen appear, we need to make the queen shape
  wq[1][1] = char(219);
  wq[2][1] = char(219);
  wq[3][1] = char(219);
  wq[3][2] = char(219);
  wq[3][3] = char(219);
  wq[3][4] = char(219);
  wq[3][5] = char(219);
  wq[2][3] = char(219);
  wq[1][3] = char(219);
  wq[1][5] = char(219);
  wq[2][5] = char(219);
  // same for black queens
  bq[1][1] = ' ';
  bq[2][1] = ' ';
  bq[3][1] = ' ';
  bq[3][2] = ' ';
  bq[3][3] = ' ';
  bq[3][4] = ' ';
  bq[3][5] = ' ';
  bq[2][3] = ' ';
  bq[1][3] = ' ';
  bq[1][5] = ' ';
  bq[2][5] = ' ';
  // prints the board in an alternating position between white and black
  for (i = 0; i < 8; i++)
    for (j = 0; j < 8; j++)
      if ((i + j) % 2 == 0) // if i+j is even, white box
        board1[i][j] = &wb;
      else
        board1[i][j] = &bb; // else, black box

  for (i = 0; i < 8; i++)
  {
    if ((board[i] + i) % 2 == 0)
      board1[board[i]][i] = &wq; // if even, white queen
    else
      board1[board[i]][i] = &bq; // if odd, black queen
  }
  // print the board via the pointers in array board
  // first print upper border
  cout << "   ";
  for (i = 0; i < 7 * 8; i++)
    cout << '_';
  cout << endl;

  // now print the board
  for (i = 0; i < 8; i++)
  {
    for (k = 0; k < 5; k++)
    {
      cout << char(179);
      for (j = 0; j < 8; j++)
      {
        for (l = 0; l < 7; l++)
        {
          cout << (*board1[i][j])[k][l];
        }
      }
      cout << char(179) << endl;
    }
  }

  // before exiting print lower border
  cout << "   ";
  for (i = 0; i < 7 * 8; i++)
    cout << char(196);
  cout << endl;
}

void next(int board[], int &c)
{
  c--; // backtrack a column
  if (c == -1)
  {
    cout << "There are no more solutions!" << endl; // once it reaches its maximum number of solutions, the program will terminate indicating that there are no solutions left
    exit(0);
    board[c]++;
  }
}
int main()
{
  int board[8] = {0}, c = 0;
  board[c] = 0; // board[0][0] = 1 in 2D version

  while (c >= 0)
  {
    c++;
    if (c == 8)
    {
      printSol(board);
      next(board, c); // backtrack
    }
    else
    {
      board[c] = -1; // reset the queen
    }
    while (c >= 0 && c < 8)
    {
      board[c]++;
      if (board[c] == 8)
      {
        next(board, c); // backtrack
      }
      else if (ok(board, c))
        break;
    }
  }
  return 0;
}