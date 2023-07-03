
int getSmallerElements(int val, vector<int>&v){
    int l=0, r=v.size()-1;

    while(l<=r){
        int mid = (l+r)>>1;

        if(v[mid]<=val) l = mid+1;
        else r = mid-1;
    }
    
    return l;
}

int getMedian(vector<vector<int>> &matrix)
{
    int low=0, high=1e9;
    int n = matrix.size(), m=matrix[0].size();
    while(low<=high){
        int mid = low+(high-low)/2;
        int cnt=0;
        for(int i=0; i<n; i++){
            cnt += getSmallerElements(mid, matrix[i]);
        }

        cnt<=(n*m/2) ? low=mid+1 : high=mid-1;
    }

    return low;
}
