bool searchMatrix(vector<vector<int>>& mat, int target) {
    int r = mat.size(), c = mat[0].size();
    int low = 0, high = (r*c)-1;

    while(low<=high){
        int mid = low + (high-low)/2;
        int mid_val = mat[mid/c][mid%c];

        if(mid_val==target) return true;
        else if(target<mid_val) high = mid-1;
        else low = mid+1;
    }
    return false;
}
