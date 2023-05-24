#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    vector<int> t[3]; // three towers represented as an array of 3
    int n, candidate = 1, towards = 1, from = 0, move = 0;

    cout << "Please enter the number of rings to move: ";
    cin >> n;

    // initialize the 3 towers
    //  t[0] is represented as the first tower --> A
    //  t[1] is represented as the second tower --> B
    //  t[2] is represented as the third tower --> C
    for (int i = n + 1; i >= 1; i--)
        t[0].push_back(i);
    t[1].push_back(n + 1);
    t[2].push_back(n + 1);

    if (n % 2 == 0)
    {                // checks if n is even or odd
        towards = 2; // if there is an even number of rings it will be initally set to 2
    }
    else
    {
        towards = 1; // else it will be set to one
    }

    while (t[1].size() < n + 1)
    { // there are still rings to transfer to tower B = t[1]
        cout << "move number " << ++move << ": Transfer ring " << candidate << " from tower " << char(from + 65) << " to tower " << char(towards + 65) << endl;
        t[towards].push_back(t[from].back()); // append the ring onto the "towards" tower
        t[from].pop_back();                   // then remove the ring from the "from" tower

        if (t[(towards + 1) % 3].back() < t[(towards + 2) % 3].back())
        {
            from = (towards + 1) % 3;
        }
        else
        {
            from = (towards + 2) % 3;
        }
        candidate = t[from].back(); // get the next candidate

        if (n % 2 != 0)
        {
            if (candidate < t[(from + 1) % 3].back()) // take the candidate and compare that to back
                towards = (from + 1) % 3;             // from + 1 moves when that happens
            else
                towards = (from + 2) % 3; // otherwise
        }

        else if (candidate < t[(from + 2) % 3].back())
        {
            towards = (from + 2) % 3;
        }
        else
        {
            towards = (from + 1) % 3;
        }
    }
    return 0;
}