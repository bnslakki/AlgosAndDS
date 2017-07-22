#include "bits/stdc++.h"
using namespace std;

const int maxn = 100005;

int n;
int bit[maxn];
int arr[maxn];
int cp[maxn];

void update(int p, int val){
	for(int i = p; i <= maxn; i += i&-i){
		bit[i] += val;
	}
}

int sum(int p){
	int ans = 0;
	for(int i = p; i; i -= i&-i){
		ans += bit[i];
	}
	return ans;
}

void compress(){
	for(int i = 0; i < n; i++){
		cp[i] = arr[i];
	}
	sort(cp, cp + n);
	for(int i = 0; i < n; i++){
		arr[i]=(lower_bound(cp,cp+n,arr[i])-cp);
	}
}

int inverse_count(){
    compress();
    int ret = 0;
    for(int i = n-1; i >= 0; i--){
        ret += sum(arr[i]);
        update(arr[i] + 1, 1);
    }
    return ret;
}
