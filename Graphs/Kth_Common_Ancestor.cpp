// https://leetcode.com/problems/kth-ancestor-of-a-tree-node/submissions/

class TreeAncestor {
public:
    int up[50001][18];
    vector<vector<int>> children;
    vector<int> depth;
    
    void dfs(int sc){
        for(auto nn : children[sc]){
            depth[nn] = depth[sc]+1;
            up[nn][0] = sc;
            for(int i =1; i<18; i++){
                up[nn][i] = up[up[nn][i-1]][i-1];
            }
            dfs(nn);
        }
    }
    
    TreeAncestor(int n, vector<int>& parent) {
        children.clear();
        children.resize(n);
        for(int i=1; i<n; i++){
            children[parent[i]].push_back(i);
        }
        for(int i=0; i<18; i++){
            up[0][i] = 0;
        }
        depth.clear();
        depth.assign(n,0);
        dfs(0);
    }
    
    int getKthAncestor(int node, int k) {
        if(depth[node]<k)
            return -1;
        for(int i = 0; i<18; i++){
            if(k & (1<<i)){
                node = up[node][i];
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
