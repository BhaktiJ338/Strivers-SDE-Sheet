#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int top=0, left=0, right=m-1, bottom=n-1;

    while(top<bottom && left<right){
        int temp = mat[top][left];
        //shift leftmost column up
        for(int i=top; i<bottom; i++)
            mat[i][left] = mat[i+1][left];
        
        //shift bottommost row
        for(int i=left; i<right; i++) 
            mat[bottom][i] = mat[bottom][i+1];
        
        //shift rightmost column down
        for(int i=bottom; i>top; i--)
            mat[i][right] = mat[i-1][right];
        
        //shift topmost row
        for(int i=right; i>left+1; i--)
            mat[top][i] = mat[top][i-1];
        

        mat[top][left+1] = temp;
        left++, top++, right--, bottom--;
    }
}
