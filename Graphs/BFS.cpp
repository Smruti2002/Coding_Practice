https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution {
  public:
    
    vector<int> vis;
    vector<int> arr;
    void bfs(int node, vector<int> adj[]){
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        while(!q.empty()){
            int k = q.front();
            for(auto p : adj[k]){
                if(!vis[p]){
                    vis[p] = 1;
                    q.push(p);
                }
            }
            arr.push_back(k);
            q.pop();
        }
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vis.assign(V+1,0);
        bfs(0,adj);
        return arr;
    }
};
