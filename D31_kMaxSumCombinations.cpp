#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	
	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end(), greater<int>());

	set<pair<int, int>>st;
	vector<int>ans;
	priority_queue<pair<int, pair<int, int>>>pq;
	pq.push({a[0]+b[0], {0, 0}});
	st.insert({0, 0});

	int i=0, j=0;

	while(k--){
		int sum = pq.top().first;
		int i = pq.top().second.first;
		int j = pq.top().second.second;
		pq.pop();

		ans.push_back(sum);

		if(i+1 < n && st.count({i+1, j})==0){
			pq.push({a[i+1]+b[j], {i+1, j}});
			st.insert({i+1, j});
		}
		if(j+1 < n && st.count({i, j+1})==0){
			pq.push({a[i]+b[j+1], {i, j+1}});
			st.insert({i, j+1});
		}
	}

	return ans;
}
