// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    vector <string> v;
    bool check (int x, int y, int n, vector<vector<int>> &m, char ch)
    {
        if(ch=='U')
            x--;
        else if(ch=='D')
            x++;
        else if(ch=='R')
            y++;
        else
            y--;
            
        if(x<n && y<n && x>=0 && y>=0 && m[x][y]==1)
            return true;
        return false;
    }
    
    void rec(vector<vector<int>> &m,int n,int x,int y,string s)
    {
        string temp = s;
        if(x==n-1 && y==n-1)
                {v.push_back(s);return ;}
        if(check(x,y,n,m,'U')==false && check(x,y,n,m,'D')==false && check(x,y,n,m,'R')==false && check(x,y,n,m,'L')==false)    
        {
            return;
        }
        if(check(x,y,n,m,'U'))
        {
            s = s+'U';
            m[x-1][y] = 0;
            rec(m,n,x-1,y,s);
            m[x-1][y] = 1;
            s = temp;
        }
        if(check(x,y,n,m,'D'))
        {
            s = s+'D';
            m[x+1][y] = 0;
            rec(m,n,x+1,y,s);
            m[x+1][y] = 1;
            s = temp;
        }
        if(check(x,y,n,m,'R'))
        {
            s = s+'R';
            m[x][y+1] = 0;
            rec(m,n,x,y+1,s);
            m[x][y+1] = 1;
            s = temp;
        }
        if(check(x,y,n,m,'L'))
        {
            s = s+'L';
            m[x][y-1] = 0;
            rec(m,n,x,y-1,s);
            m[x][y-1] = 1;
            s = temp;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        if(m[0][0]==0)
            return v;
        m[0][0] = 0;
        rec(m,n,0,0,"");
        return v;
    }
};
