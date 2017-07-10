#include "bits/stdc++.h"
using namespace std;

const int maxn = 1000;

vector<pair<int, int>>arr[maxn];
int dist[maxn];


int dijkstra(int source, int vertex){
	
	int u, v, w;
	// Initialize Single Source
	for(int i = 1; i <= vertex; i++) dist[i] = INT_MAX;
	dist[source] = 0;
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
	q.push({source,0});
	
	while (!q.empty()){
		u = q.top().first;
		q.pop();
		for (int i = 0; i < arr[u].size(); i++){
			v = arr[u][i].first;
			w = arr[u][i].second;

			// Relax
			if(dist[v] > w + dist[u]){
				dist[v] = w + dist[u];
				q.push({v, dist[v]});
			}
		}
	}
}

int main(){
	
}
