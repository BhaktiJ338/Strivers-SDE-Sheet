int longestSubSeg(vector<int> &arr , int n, int k){
    int maxlen=0, start=0, zerocnt=0;

    for(int end=0; end<n; end++){
        if(arr[end]==0){
            zerocnt++;
            while(zerocnt>k){
                if(arr[start]==0){
                    //shrink window from start
                    zerocnt--;
                }
                start++;           
            }
        }
        maxlen = max(maxlen, end-start+1);
    }
    return maxlen;
}
