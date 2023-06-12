#include <bits/stdc++.h> 
int uniqueSubstrings(string s)
{
    int i=0, j=0, len=0;
    vector<int>mp(256, -1);

    while(j<s.length()){
        if(mp[s[j]]!=-1) //seen before
            i = max(i, mp[s[j]]+1);
        
        mp[s[j]] = j;
        len = max(len, j-i+1);
        j++;
    }
    return len;
    
}
