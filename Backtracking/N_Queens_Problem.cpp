#include<bits/stdc++.h>
using namespace std;

/* N Queens Problem. Given a board of N*N size, find the number of ways to place N queens in it 
   This is the backtracking approach */

int N;
vector <int> placed; // will store the column number in which the queen is placed for each row
int ans  = 0;

void rec(int row)
{
    // we have to place the queen at row.

    if(row==N)
    {
        ans++;
        return;
    }

    for(int col = 0; col<N; col++)
    {
        bool safe = 1;
        for(int pRow=0; pRow < row; pRow++)
        {
            int pCol = placed[pRow];

            // the diagonal elements and same col is prohibited
            if(pCol==col || (abs(pCol-col)==abs(pRow-row)))
            {
                safe = 0;
            }
        }
        if(safe)  // the column can be used to place the queen 
        {
            placed.push_back(col);
            rec(row+1);
            placed.pop_back();
        }
    }
}

int main()
{
    N = 1;
    rec(0);
    cout << ans << endl;
}