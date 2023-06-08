#include <bits/stdc++.h> 


int merge(int l, int mid, int r, vector<int> &arr){
	if(l>=r) return 0;
	int j=mid+1;
	int cnt=0;
	for(int i=l; i<=mid; i++){
		while(j<=r && arr[i]>2LL*arr[j]){
			j++;
		}
		cnt += (j-(mid+1));
	}
	int i=l, k=0;
	j=mid+1;
    int temp[r-l+1];
    while(i<=mid && j<=r){
        if(arr[i]>arr[j]){
            temp[k++] = arr[j++];
        }
        else{
            temp[k++] = arr[i++];
        }
    }

    while(i<=mid) temp[k++] = arr[i++];
    while(j<=r) temp[k++] = arr[j++];
    for (i=0; i<k; i++) arr[l+i] = temp[i]; 
	return cnt;
}
int mergeSort(int l, int r, vector<int> &arr){
	if(l>=r) return 0;
	int cnt=0;
	int mid = l+(r-l)/2;
	cnt += mergeSort(l, mid, arr);
	cnt += mergeSort(mid+1, r, arr);
	cnt += merge(l, mid, r, arr);
	return cnt;
}
int reversePairs(vector<int> &arr, int n){
	return mergeSort(0, n-1, arr);
}
