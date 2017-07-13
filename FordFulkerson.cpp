#include "bits/stdc++.h"
using namespace std;

const int maxn=10001;

vector<int> arr[maxn];
int parent[maxn];
bool visit[maxn];
int cap[maxn][maxn];

bool bfs(int s, int e){
	memset(visit, 0, sizeof visit);
	queue<int>q;
	q.push(s);
	visit[s] = 1;
	parent[s] = -1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 0; i < arr[u].size(); i++){
			if(!visit[arr[u][i]] && cap[u][arr[u][i]] > 0){
				q.push(arr[u][i]);
				parent[arr[u][i]] = u;
				visit[arr[u][i]] = 1;
			}
		}
	}
	return visit[e] == 1;
}

int FordFulkerson(int s, int e){
	int max_flow = 0;
	while(bfs(s,e)){
		int path_flow = INT_MAX;
		
		//min flow in a path
		for(int v = e; v != s; v = parent[v]){
			int u = parent[v];
			path_flow = min(path_flow, cap[u][v]);
		}

		//update capacities
		for(int v = e; v != s; v = parent[v]){
			int u = parent[v];
			cap[u][v] -= path_flow;
			cap[v][u] += path_flow;
		}
		max_flow += path_flow;
	}
	return max_flow;
}

int main(){
	//freopen("t.txt","r",stdin);
	int t, n, m, cost;
	int u, v, w;
	for(scanf("%d", &t); t--;){
		scanf("%d %d", &n, &m);
		for(int i = 0; i < m; i++){
			scanf("%d %d %d",&u, &v, &w);
			u++, v++;
			arr[u].push_back(v);
			arr[v].push_back(u);
			cap[u][v] = w;
		}
		printf("%d\n",FordFulkerson(1, n));
	}
}
