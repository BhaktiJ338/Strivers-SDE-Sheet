#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int k)
{
    int n = arr.size();
    int cnt=0, curr=0;
    map<int, int>mp;//mp[xor] = no. of times xor appeared

    for(int i=0; i<n; i++){
        curr = curr^arr[i];
        if(curr==k) cnt++;
        cnt += mp[curr^k];
        mp[curr]++;
    }
    return cnt;
}
