#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    unordered_set<int>st;
    for(auto it:arr) st.insert(it);
    int len = 0;
    for(int i=0; i<n; i++){
        if(!st.count(arr[i]-1)){
            int clen = 1;
            int currnum = arr[i];
            while(st.count(currnum+1)){
                clen++;
                currnum++;
            }
            len = max(len, clen);
        }
       
    }
    return len;
}
