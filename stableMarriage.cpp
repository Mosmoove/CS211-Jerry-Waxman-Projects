#include <iostream>
#include <cmath>
using namespace std;

bool ok(int board[], int col)
{
    // let board[] = woman,  let col = man
    int mp[3][3] = {
        {0, 2, 1},
        {0, 2, 1},
        {1, 2, 0}};
    // mp is man preference
    int wp[3][3] = {
        {2, 1, 0},
        {0, 1, 2},
        {2, 0, 1}};
    // wp is womans preference

    for (int i = 0; i < col; i++)
    {
        if (board[i] == board[col])
        {
            return false;
            // if current woman is already matched with another man, return false
        }
    }
    for (int i = 0; i < col; i++)
    {
        if ((mp[col][board[i]] < mp[col][board[col]]) && (wp[board[i]][col] < wp[board[i]][i]))
        {
            return false; // this will produce an instability
        }
    }
    for (int i = 0; i < col; i++)
    {
        if ((wp[board[col]][i] < wp[board[col]][col]) && (mp[i][board[col]] < mp[i][board[i]]))
        {
            return false; // if new man likes current woman and if current woman likes the new man, the marriage is unstable which will return to false.
        }
    }
    return true;
    // else return true if the marriage does not show signs of instability
}

void printSolutions(int board[])
{
    static int count = 0;
    cout << "Solution #" << ++count << endl;
    for (int i = 0; i < 3; i++)
        cout << "Man " << i << " matches "
             << "Woman " << board[i] << endl;
    cout << endl;
}
int main()
{

    int board[3] = {0};
    int col = 0;
    board[col] = 0;

    while (col >= 0)
    {
        col++;

        if (col >= 3)
        {                          // if we found a solution
            printSolutions(board); // call the function
            col--;                 // and backtrack.
        }
        else
        {
            board[col] = -1;
        }

        while (col >= 0)
        {
            board[col]++;

            if (board[col] >= 3)
            {
                col--;
            }
            else if (ok(board, col))
            {
                break;
            }
        }
    }

    return 0;
}