vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    map<int, int>mp;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

    for (auto it:arr){
        mp[it]++;
    }

    for(auto it:mp){
        pq.push({it.second, it.first});

        if(pq.size() > k) pq.pop();
    }

    vector<int>res;

    while(!pq.empty()){
        res.push_back(pq.top().second);
        pq.pop();
    }

    return res;
}
