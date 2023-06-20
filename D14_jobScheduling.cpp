#include <bits/stdc++.h> 
int jobScheduling(vector<vector<int>> &jobs)
{
    //jobs[i] = {deadline, profit}
    int n = jobs.size();
    int maxDeadline = INT_MIN, maxpro=0;
    vector<pair<int, int>>arr;
    for(auto it:jobs){
        arr.push_back({it[1], it[0]});
        maxDeadline = max(maxDeadline, it[0]);
    }
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());

    vector<int>days(maxDeadline+1, -1); //days[i] = assigned job's index

    for(int i=0; i<n; i++){
        int dead = arr[i].second;
        for(int j=dead; j>=1; j--){
            if(days[j]==-1){
                days[j] = 1;
                maxpro += arr[i].first;
                break;
            }
        }
    }
    return maxpro;
}
