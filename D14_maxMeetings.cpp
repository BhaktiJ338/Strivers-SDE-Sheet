#include <bits/stdc++.h> 
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();
    vector<vector<int>>meets(n);

    for(int i=0; i<n; i++){
        meets[i] = {end[i], start[i], i+1};
    }

    sort(meets.begin(), meets.end());

    vector<int>res;
    res.push_back(meets[0][2]);
    int prevEnd = meets[0][0];

    for(int i=1; i<n; i++){
        if(meets[i][1]>prevEnd){
            prevEnd = meets[i][0];
            if(i+1<n && meets[i][0]==meets[i+1][0]){
                if(meets[i][2]<meets[i+1][2]) res.push_back(meets[i][2]); 
                else res.push_back(meets[i+1][2]); 
            }
            else{
                res.push_back(meets[i][2]); 
            }
        }
    }

    return res;
}
