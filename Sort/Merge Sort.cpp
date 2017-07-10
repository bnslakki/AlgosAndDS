#include "bits/stdc++.h"
using namespace std;

void Merge(int arr[], int i, int mid, int j, int tm[]){
	
	int i_ = i, k = mid + 1, p = i;
	while((i <= mid) && (k <= j))
		tm[p++] = (arr[i] < arr[k]) ? arr[i++]: arr[k++];
	
	while(i <= mid)tm[p++] = arr[i++];
	while(k <= j)tm[p++] = arr[k++];
	
	for(int l = i_; l <= j; l++)arr[l] = tm[l];
}

void Merge_Sort(int arr[], int i, int j, int tm[]){
	if(i >= j)return ;
	int mid = (i + j)>>1; 
	Merge_Sort(arr, i, mid, tm);
	Merge_Sort(arr, mid + 1, j, tm);
	Merge(arr, i, mid, j, tm);
}

int main(){
	int arr[] = {4, 5, 7, 3, 7, 3, 1, 9, 0, -4};
	int size = sizeof arr/sizeof arr[0];
	int tm[size + 1];
	
	Merge_Sort(arr, 0, size - 1, tm);
	
	for(auto i : arr){
		cout<<i<<" ";
	}
}
