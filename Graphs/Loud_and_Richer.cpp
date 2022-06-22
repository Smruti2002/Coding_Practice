// https://leetcode.com/problems/loud-and-rich/

class Solution {
public:
    int vis[500]={0};
    vector<int> mini;
    vector<int> adj[500];
    
    int dfs(int node,vector<int> &quiet){
        vis[node]=1;
        mini[node] = node;
        for(auto v : adj[node]){
            if(!vis[v]){
                int nn = dfs(v,quiet);
                if(quiet[nn]<quiet[mini[node]]){
                    mini[node] = nn;
                }
            }
            else{
                if(quiet[mini[node]]>quiet[mini[v]]){
                    mini[node]=mini[v];
                }
            }
        }
        return mini[node];
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int m = richer.size();
        int n = quiet.size();
        for(int i = 0; i<m; i++){
            adj[richer[i][1]].push_back(richer[i][0]);
        }
        mini.assign(n,-1);
        for(int i =0; i<n; i++){
            if(!vis[i]){
                mini[i] = dfs(i,quiet);
            }
        }
        return mini;
    }
};
