#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long int>>ans;
  ans.push_back({1});

  for(int i=1; i<n; i++){
    vector<long long int>v;
    for(int j=0; j<=i; j++){
      if(j==0 || j==i){
        v.push_back(1);
        continue;
      }
      v.push_back(ans[i-1][j-1]+ans[i-1][j]);
    }
    ans.push_back(v);
  }
  return ans;
}
