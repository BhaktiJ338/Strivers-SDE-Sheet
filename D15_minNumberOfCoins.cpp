#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    vector<int>coins = {1,2,5,10,20,50,100,500,1000};
    int i=coins.size()-1, cnt=0;

    while(amount>0){
        if(amount>=coins[i]){
            cnt++;
            amount -= coins[i];
        }
        else i--;
    }
    return cnt;
}
