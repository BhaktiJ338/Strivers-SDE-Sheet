#include <bits/stdc++.h>
#define ll long long int

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	ll s=(n*(n+1))/2;	//sum[1..n]
	ll p=(n*(n+1)*(2*n+1))/6;	//sum[1^2...n^2]

	for(auto it:arr){
		s -= (ll)it;
		p -= (ll)it*(ll)it;
	}

	int mis = (s+p/s)/2;
	int dup = mis-s;

	return {mis, dup};
}
