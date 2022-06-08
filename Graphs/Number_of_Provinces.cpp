// https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    int vis[201]={0};
    void dfs(int node,int prov,vector<vector<int>>& graph){
        vis[node] = prov;
        for(int i=0; i<graph.size(); i++){
            if(graph[node][i]==1){
                if(!vis[i])
                    dfs(i,prov,graph);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int prov = 0;
        int n = isConnected.size();
        for(int i = 0; i<n; i++){
            if(!vis[i])
                dfs(i,++prov,isConnected);
        }
        return prov;
    }
};
