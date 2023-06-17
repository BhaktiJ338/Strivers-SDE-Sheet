#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int target) {
	if(n < 3) return {};
	vector<vector<int>>st;	
	sort(arr.begin(), arr.end());
	for(int i=0; i<n-2; i++){
		int l=i+1, h=n-1;
		int sum = target-arr[i];

		while(l<h){
			if(sum==arr[l]+arr[h]) {
				vector<int>v = {arr[i], arr[l], arr[h]};
				st.push_back(v);
				while(l<h && arr[l]==arr[l+1]) l++;
				while(h>l && arr[h-1]==arr[h]) h--;
				l++;
				h--;
			}
			else if(sum > arr[l]+arr[h]) l++;
			else h--;
		}

		while(i+1<n && arr[i]==arr[i+1]) i++;
	}
	
	return st;
}
