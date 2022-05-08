// https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1

class Solution 
{
    public:
    
    bool check(int grid[N][N],int x, int y, int k)
    {
        int col,row;
        for(col = 0; col<=8; col++)
        {
            if(grid[x][col]==k)
            return false;
        }
        for(row = 0; row<=8; row++)
        {
            if(grid[row][y]==k)
            return false;
        }
        if(x<=2)
            row = 0;
        else if(x<=5)
            row = 3;
        else
            row = 6;
            
        if(y<=2)
            col = 0;
        else if(y<=5)
            col = 3;
        else
            col = 6;
            
        for(int i = row; i < (row+3); i++)
        {
            for(int j = col; j< (col+3); j++)
            {
                if(grid[i][j]==k)
                    return false;
            }
        }
        
        return true;
    }
    
    bool solve(int grid[N][N], int x, int y)
    {
        if(x==N-1 && y==N-1)
        {
            if(grid[x][y]==0)
            {
                for(int i = 1; i<10; i++)
                {
                    if(check(grid,x,y,i))
                    {
                        grid[x][y]=i;
                        return true;
                        
                    }
                }
                return false;
            }
            return true;
        }
        
        int next_row,next_col;
        if(y==N-1)
        {
            next_row = x+1;
            next_col = 0;
        }
        else
        {
            next_row = x;
            next_col = y+1;
        }
        
        if(grid[x][y]!=0)
        {
            return solve(grid,next_row,next_col);
        }
        else
        {
            for(int i = 1; i<10 ; i++)
            {
                if(check(grid,x,y,i))
                {
                    grid[x][y] = i;
                    bool res = solve(grid,next_row,next_col);
                    if(res==true)
                        return true;
                    grid[x][y] = 0;
                }
            }
            return false;
        }
    }
    
    bool SolveSudoku(int grid[N][N])  
    { 
        return solve(grid,0,0);
    }
    
    
    void printGrid (int grid[N][N]) 
    {
        int i,j;
        for(i=0; i<N; i++)
        {
            for(j=0; j<N; j++)
            {
                cout << grid[i][j] << " ";
            }
        }
    }
};
