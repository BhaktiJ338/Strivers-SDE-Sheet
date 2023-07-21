#include <bits/stdc++.h>

vector<int> findMedian(vector<int> &arr, int n){
	
	priority_queue<int>maxh;
	priority_queue<int, vector<int>, greater<int>>minh;
	vector<int>res;

	for(auto it:arr){
		if(maxh.empty() || it<=maxh.top())
			maxh.push(it);
		else 
			minh.push(it);

		if(minh.size()+1 < maxh.size()){
			int temp = maxh.top();
			maxh.pop();
			minh.push(temp);
		}
		else if(maxh.size() < minh.size()){
			int temp = minh.top();
			minh.pop();
			maxh.push(temp);
		}

		if(minh.size()==maxh.size()){
			int k = (maxh.top()+minh.top())/2;
			res.push_back(k);
		}
		else{
			res.push_back(maxh.top());
		}
	}
	return res;
}
