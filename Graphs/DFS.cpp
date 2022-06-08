// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1/
class Solution {
  public:
    vector<int> vis;
    vector<int> arr;
    void dfs(int node,vector<int> adj[]){
        vis[node] = 1;
        arr.push_back(node);
        for(auto k : adj[node]){
            if(!vis[k])
                dfs(k,adj);
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vis.assign(V+1,0);
        dfs(0,adj);
        return arr;
    }
};
