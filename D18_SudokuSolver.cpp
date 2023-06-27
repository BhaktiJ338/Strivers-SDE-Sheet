
bool isPossible(int r, int c, int k, int matrix[][9]){

    for(int i=0; i<8; i++){
        if(matrix[i][c]==k) return false;
        if(matrix[r][i]==k) return false;
        if(matrix[3*(r/3)+(i/3)][3*(c/3)+(i%3)]==k) return false;
    }
    return true;
}

bool f(int i, int j, int matrix[][9]){

    for(int r=0; r<9; r++){
        for(int c=0; c<9; c++){
            if(matrix[r][c]==0){
                for(int k=1; k<=9; k++){
                    if(isPossible(r, c, k, matrix)){
                        matrix[r][c] = k;
                        if(f(r, c, matrix)) return true;
                        else matrix[r][c] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool isItSudoku(int matrix[9][9]) {
    return f(0, 0, matrix);
}
