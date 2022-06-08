// https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:
    
    int vis[1000] = {0};
    void dfs(int node, int comp,vector<vector<int>>& rooms){
        vis[node] = comp;
        for(auto k : rooms[node]){
            if(!vis[k])
                dfs(k,comp,rooms);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int comp = 0;
        int n = rooms.size();
        for(int i = 0; i<n; i++){
            if(!vis[i])
                dfs(i,++comp,rooms);
        }
        return comp==1;
    }
};
