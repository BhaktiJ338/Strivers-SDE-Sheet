

bool isPossible(int node, int col,  vector<vector<int>> &mat, vector<int>&color){
    for(int j=0; j<mat.size(); j++){
        if(mat[node][j]==1 && color[j]==col) return false;
    }

    return true;
}

bool f(int node, vector<vector<int>> &mat, vector<int>&color, int m, int n){
    if(node==n) return true;

    for(int col=1; col<=m ;col++){ //try every color
        if(isPossible(node, col, mat, color)){
            color[node] = col;
            if(f(node+1, mat, color, m, n)) return true;
            color[node] = 0;
        }
    }

    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int n=mat.size();
    vector<int>color(n, 0);
    
    return f(0, mat, color, m, n )? "YES" : "NO";
}
