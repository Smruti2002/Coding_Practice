// https://practice.geeksforgeeks.org/problems/steps-by-knight5927/

#define ff first
#define ss second

class Solution 
{
    public:
    
    // movement vectors
    int dx[8] = {-2,-2,-1,-1,1,1,2,2};
    int dy[8] = {1,-1,2,-2,2,-2,1,-1};
    int n;
    bool check(int x,int y){
        if(x>=1&&x<=n&&y>=1&&y<=n)
            return 1;
        return 0;
    }
    vector<vector<int>> dist;
    void bfs(pair<int,int> p){
        queue<pair<int,int>> q;
        q.push(p);
        while(!q.empty()){
            pair<int,int> pa = q.front();
            for(int k=0; k<8; k++){
                if(check(pa.ff+dx[k],pa.ss+dy[k])&&dist[pa.ff+dx[k]][pa.ss+dy[k]]>dist[pa.ff][pa.ss]+1){
                    dist[pa.ff+dx[k]][pa.ss+dy[k]]=dist[pa.ff][pa.ss]+1;
                    q.push(make_pair(pa.ff+dx[k],pa.ss+dy[k]));
                }
            }
            q.pop();
        }
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    n = N;
	    dist.assign(N+1,vector<int>(N+1,INT_MAX));
	    dist[KnightPos[0]][KnightPos[1]] = 0;
	    bfs(make_pair(KnightPos[0],KnightPos[1]));
	    return dist[TargetPos[0]][TargetPos[1]];
	}
};
