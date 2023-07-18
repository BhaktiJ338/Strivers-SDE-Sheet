#include <bits/stdc++.h> 
#define ppi pair<int, pair<int, int>>

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<ppi, vector<ppi>, greater<ppi>> minh;
    vector<int>ans;

    for(int i=0; i<k; i++){
        minh.push({kArrays[i][0], {i, 0}});
    }

    while(!minh.empty()){
        auto it = minh.top();
        minh.pop();

        ans.push_back(it.first);
        int i = it.second.first;
        int j = it.second.second;

        if(j+1 < kArrays[i].size()) 
            minh.push({kArrays[i][j+1], {i, j+1}});
    }

    return ans;
}
