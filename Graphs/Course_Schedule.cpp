// https://leetcode.com/problems/course-schedule/

class Solution {
public:
    
    vector<int> adj[2000];
    int indegree[2000] = {0};
    int n;
    vector<int> topo;
    
    void bfs(){
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int k = q.front();
            q.pop();
            topo.push_back(k);
            for(auto v : adj[k]){
                indegree[v]--;
                if(indegree[v]==0)
                    q.push(v);
            }
        }
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        int m = prerequisites.size();
        for(int i = 0; i<m; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        bfs();
        return topo.size()==n;
    }
};
