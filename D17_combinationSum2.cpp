#include <bits/stdc++.h>
void f(int ind, int target, vector<int>&ds, vector<int> &arr, int n, 
vector<vector<int>>&ans){
	if(target == 0){
		ans.push_back(ds);
		return; 
	}
	for(int i=ind; i<arr.size(); i++){
		if(i > ind && arr[i] == arr[i-1]) continue;
		if(arr[i] > target) break;
		ds.push_back(arr[i]);
		f(i+1, target-arr[i], ds, arr, n, ans);
		ds.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	
	vector<vector<int>>ans;
	vector<int>ds;
	sort(arr.begin(), arr.end());
	f(0, target, ds, arr, n, ans);

	return ans;
}
