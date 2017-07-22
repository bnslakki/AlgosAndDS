int cp[maxn];

void compress(){
	for(int i = 0; i < n; i++){
		cp[i] = arr[i];
	}
	sort(cp, cp + n);
	for(int i = 0; i < n; i++){
		arr[i]=(lower_bound(cp,cp+n,arr[i])-cp);
	}
}
