


bool isSafe(int r, int c, vector<vector<int>>&board){
    int n = board.size();

    for(int col=0; col<n; col++){
        if(board[r][col]==1) return false;
    }

    for(int i=r, j=c; i>=0&&j>=0; i--, j--){
        if(board[i][j]==1) return false;
    }
    for(int i=r, j=c; i<n && j>=0; i++, j--){
        if(board[i][j]==1) return false;
    }

    return true;
}

void addBoard(vector<vector<int>>&ans, vector<vector<int>>&board){
    vector<int>ds;
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board.size(); j++){
            ds.push_back(board[i][j]);
        }
    }
    ans.push_back(ds);
}

void f(int c, vector<vector<int>>&ans, vector<vector<int>>&board, 
vector<int>&ds, int n){
    if(c==n){
        addBoard(ans, board);
        return;
    }

    for(int r=0; r<n; r++){
        if(isSafe(r, c, board)){
            board[r][c] = 1;
            f(c+1, ans, board, ds, n);
            board[r][c] = 0;
        }
    }

}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>>board(n, vector<int>(n, 0));
    vector<vector<int>>ans;
    vector<int>ds;

    f(0, ans, board, ds, n);
    return ans;

}
