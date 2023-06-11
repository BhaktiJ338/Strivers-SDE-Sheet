//--------------approach 1--------------------------
#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {
  int n = arr.size();
  int maxlen = 0, j;
  for(int i=0; i<n; i++){
    int sum = 0;
    for(j=i; j<n; j++){
      sum += arr[j];
      if(sum==0) 
        maxlen = max(maxlen, j-i+1);
    }
  }
  return maxlen;
}

//--------------approach2--------------------------
#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {
  int n = arr.size();
  int maxlen = 0, sum=0;
  map<int, int>mp;
  for(int i=0; i<n; i++){
    sum += arr[i];
    if(sum==0) maxlen = i+1;
    else{
      if(mp.find(sum)==mp.end())
        mp[sum] = i;
      else
        maxlen = max(maxlen, i-mp[sum]);
    }
  }
  return maxlen;
}
