#include <bits/stdc++.h> 

bool comp(pair<int, int> i1, pair<int, int>i2){
    double v1 = (double)i1.second/(double)i1.first;
    double v2 = (double)i2.second/(double)i2.first;

    return v1>v2;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin(), items.end(), comp);
    int i=0;
    double profit = 0;
    while(i<n){
        if(items[i].first <= w){
            profit += items[i].second;
            w -= items[i].first;
        }
        else{
            double val = w * ((double)items[i].second/(double)items[i].first);
            profit += val;
            break;
        }
        i++;
    }
    return profit;
}
