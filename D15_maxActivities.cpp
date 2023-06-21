#include <bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n = start.size();
    vector<vector<int>>task(n);

    for(int i=0; i<n; i++){
        task[i] = {finish[i], start[i]};
    }

    sort(task.begin(), task.end());

    int cnt=1, prevFinish=task[0][0];

    for(int i=1; i<n; i++){
        if(task[i][1]>=prevFinish){
            cnt++;
            prevFinish = task[i][0];
        }
    }
    return cnt;
}
