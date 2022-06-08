// https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
public:
    
    vector<vector<int>> paths;
    void bfs(vector<vector<int>>& graph,int node,int k,vector<int> v){
        if(node==k){
            v.push_back(node);
            paths.push_back(v);
            return ;
        }
        v.push_back(node);
        for(auto j : graph[node]){
            bfs(graph,j,k,v);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> v;
        int n = graph.size();
        bfs(graph,0,n-1,v);
        return paths;
    }
};
