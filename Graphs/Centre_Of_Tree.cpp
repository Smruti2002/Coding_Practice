// https://leetcode.com/problems/minimum-height-trees/

class Solution {
public:
    vector<int> adj[20000];
    int par[20000] = {-1};
    int dist[20000] = {0};
    void dfs(int nn, int pp, int dd){
        dist[nn]=dd;
        par[nn]=pp;
        for(auto v: adj[nn]){
            if(v!=pp)
                dfs(v,nn,dd+1);
        }
    }
    int maxi(int n){
        int ind = 0;
        int m = dist[0];
        for(int i = 1; i<n; i++){
            if(dist[i]>dist[ind]){
                ind = i;
            }
        }
        return ind;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        for(int i =0; i<n-1; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0,-1,0);
        int max1 = maxi(n);
        dfs(max1,-1,0);
        int max2 = maxi(n);
        int temp = max2;
        vector<int> path;
        while(temp!=-1){
            path.push_back(temp);
            temp = par[temp];
        }
        vector<int> ans;
        if(path.size()%2==0){
            ans.push_back(path[path.size()/2]);
            ans.push_back(path[path.size()/2 -1]);
        }
        else{
            ans.push_back(path[path.size()/2]);
        }
        return ans;
    }
};
