#include "bits/stdc++.h"
using namespace std;

const int maxn = 1000;

vector<pair<int, int>>arr[maxn];

int n;
void Dials(int source, int weight){
	vector<pair<int, list<int>::iterator>>dist(n);
	for(int i = 0; i < n; i++)
		dist[i].first=INT_MAX;
	
	list<int> B[weight * n + 1];
	
	B[0].push_back(source);
	dist[source].first = 0;
	
	int i=0;
	while(1){
		while(!B[i].size() && i < weight*n)i++;
		if(i == weight*n)break;
		int u = B[i].front();
		B[i].pop_front();
		for(int j = 0; j < arr[u].size(); j++){
			int v = arr[u][j].first;
			int wt = arr[u][j].second;
			int du = dist[u].first;
            int dv = dist[v].first;
            if (dv > du + wt){
                if(dv != INT_MAX)B[dv].erase(dist[v].second);
                dist[v].first = du + wt;
                dv = dist[v].first;
                B[dv].push_front(v);
                dist[v].second = B[dv].begin();
            }
		}
	}
	 for(int i = 0; i < n; ++i)
        printf("%d %d\n", i, dist[i].first);	
}

int main(){

}
