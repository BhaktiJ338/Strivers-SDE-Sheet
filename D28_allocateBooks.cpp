#include <bits/stdc++.h> 

bool isPossible(long long int &t, int &n, vector<int>&time){

	int days=1, total_time=0;

	for(auto it:time){
		if(it>t) return false;
		if(total_time + it <= t){
			total_time += it;
		}
		else{
			days++;
			total_time = it;
		}
	}

	return days<=n;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// int total = 0;
	// for(auto it:time) {
	// 	total += it;
	// }
	long long int l=1, r=1e9;

	while(l<=r){
		long long int mid = l+(r-l)/2;

		if(isPossible(mid, n, time)) {r = mid;}
		else l = mid+1;
	}

	return l;
}
