#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	
	int i=0, j=0;
	
	while(i<m+n && j<n){
		if(arr1[i]==0){
			arr1[i] = arr2[j];
			i++;
			j++;
		}
		else if(arr1[i]<=arr2[j]){
			i++;
		}
		else{
			swap(arr2[j], arr1[i]);
			sort(arr2.begin()+j, arr2.end());
			i++;
		}
		
	}
	return arr1;
}
