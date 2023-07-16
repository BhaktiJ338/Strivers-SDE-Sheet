#include <bits/stdc++.h> 

bool isPossible(int dist, int c, vector<int> &positions){
	int lastPlayerPos = positions[0];
	int playerCnt=1;

	for(int i=1; i<positions.size(); i++){
		if(positions[i] - lastPlayerPos >= dist){
			playerCnt++;
			lastPlayerPos = positions[i];
		}
		if(playerCnt==c) return true;
	}
	return false;
}

int chessTournament(vector<int> positions , int n ,  int c){
	sort(positions.begin(), positions.end());

	int l = 1, h = positions[n-1]-positions[0]; //low = min dist, high = max dist

	while(l<=h){
		int mid = l+(h-l)/2;

		if(isPossible(mid, c, positions)) l = mid+1;
		else h = mid-1;
	}

	return h;
}
