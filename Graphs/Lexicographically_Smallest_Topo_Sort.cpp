#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> indegree;
vector<int> topo;

void bfs(int n){
	priority_queue<int> q;
	for(int i = 1; i<=n; i++){
		if(indegree[i]==0)
			q.push(-1*i);
	}
	while(!q.empty()){
		int x = q.top();
		q.pop();
		topo.push_back(-1*x);
		for(auto k:adj[-1*x]){
			indegree[k]--;
			if(indegree[k]==0)
				q.push(-1*k);
		}
	}
}

int main() {
	int n,m,x,y,i;
	cin >> n >> m;
	adj.resize(n+1);
	indegree.assign(n+1,0);
	while(m--){
		cin >> x >> y;
		adj[x].push_back(y);
		indegree[y]++;
	}	
	bfs(n);
	for(auto k : topo)
		cout << k << " ";
	cout << "\n";
}
