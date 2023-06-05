#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int currmin=INT_MAX, maxpro=0;

    for(int i=0; i<prices.size(); i++){
        currmin = min(currmin, prices[i]);
        maxpro = max(maxpro, prices[i]-currmin);
    }

    return maxpro;
}
