// https://leetcode.com/problems/escape-the-spreading-fire/submissions/

#define ff first
#define ss second

class Solution {
public:
    
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int n,m,inf = 1e9;
    int blocked[300][300];
    int vis[300][300];
    
    bool check(int x, int y,vector<vector<int>>& grid){
        if(x>=0&&x<n&&y>=0&&y<m&&grid[x][y]==0)
            return 1;
        return 0;
    }
    
    void BFS(vector<vector<int>>& grid){
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j] =1;
                    blocked[i][j]=0;
                }
                else
                    blocked[i][j] = INT_MAX;
            }
        }
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                if(check(p.ff+dx[i],p.ss+dy[i],grid)&& !vis[p.ff+dx[i]][p.ss+dy[i]]){
                    vis[p.ff+dx[i]][p.ss+dy[i]] = 1;
                    q.push({p.ff+dx[i],p.ss+dy[i]});
                    blocked[p.ff+dx[i]][p.ss+dy[i]] = blocked[p.ff][p.ss]+1;
                }
            }
        }
    }
    
    bool check2(int x,int y,vector<vector<int>>& grid,int t){
        if(x==n-1 && y==m-1){
            if(blocked[x][y]>=t)
                return 1;
            return 0;
        }
        if(x>=0&&x<n&&y>=0&&y<m&&grid[x][y]==0&&blocked[x][y]>t)
            return 1;
        return 0;
    }
    
    void DFS(int x,int y,vector<vector<int>>& grid,int t){
        vis[x][y]=1;
        for(int i=0; i<4; i++){
            if(check2(x+dx[i],y+dy[i],grid,t+1)&& !vis[x+dx[i]][y+dy[i]]){
                DFS(x+dx[i],y+dy[i],grid,t+1);
            }
        }
    }
    
    int maximumMinutes(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(vis,0,sizeof(vis));
        BFS(grid);
        int lo = 0,hi= 1e9, mid,res = -1;
        while(lo<=hi){
            mid = (lo+hi)/2;
            memset(vis,0,sizeof(vis));
            DFS(0,0,grid,mid);
            if(vis[n-1][m-1]==1){
                res = mid;
                lo = mid+1;
            }
            else
                hi = mid-1;
        }
        return res;
    }
};
