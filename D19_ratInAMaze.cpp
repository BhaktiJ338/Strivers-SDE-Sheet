#include <bits/stdc++.h> 

void f(int row, int col, vector<vector<int>>&vis, vector<vector<int>>&ans, vector<vector<int>>&maze,
vector<int>&temp, int n){
  
  if(row==n-1 && col==n-1){
    temp[0]=1;
    ans.push_back(temp);
    return;
  }

  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, 1, -1};
  
  for(int k=0; k<4; k++){
    int nrow = row + dx[k];
    int ncol = col + dy[k];
    
    if(nrow>=0 && ncol>=0 && nrow<n && ncol<n 
    && maze[nrow][ncol]==1 && vis[nrow][ncol]==0){
        vis[nrow][ncol] = 1;
        temp[(n*nrow)+ncol] = 1;
        f(nrow, ncol, vis, ans, maze, temp, n);
        vis[nrow][ncol] = 0;
        temp[(n*nrow)+ncol] = 0;
    }
  }
  return;
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  vector<vector<int>>vis(n, vector<int>(n, 0)), ans;
  vector<int>temp(n*n, 0);
  vis[0][0]=1;
  f(0, 0, vis, ans, maze, temp, n);
  return ans;
}
