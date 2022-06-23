// https://leetcode.com/problems/course-schedule-iv/

class Solution {
public:
    int dist[100][100];
    int adj[100][100];
    int inf = 1e7;
    int n;
    void Floyd(){
        int i,j,k;
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                if(i==j)
                    dist[i][j]=0;
                else if(adj[i][j]==1)
                    dist[i][j]=1;
                else
                    dist[i][j]=inf;
            }
        }
        for(k=0; k<n; k++){
            for(i=0; i<n; i++){
                for(j=0; j<n; j++){
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        n = numCourses;
        int m = prerequisites.size();
        memset(adj,0,sizeof(adj));
        for(int i =0; i<m; i++){
            adj[prerequisites[i][0]][prerequisites[i][1]]=1;
        }    
        Floyd();
        vector<bool> ans(queries.size());
        for(int i=0; i<queries.size(); i++){
            int u = queries[i][0];
            int v = queries[i][1];
            if(dist[u][v]>=inf)
                ans[i]=0;
            else
                ans[i]=1;
        }
        return ans;
    }
};
