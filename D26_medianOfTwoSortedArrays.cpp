double median(vector<int>& a, vector<int>& b) {
	int n = a.size(), m = b.size();
	if(n>m){ 
		return median(b, a);
	}
	int total = (n+m+1)/2;
	int low=0, high=n;

	while(low<=high){
		int mid1 = low+(high-low)/2;
		int mid2 =  total-mid1;

		int l1 = (mid1==0) ? INT_MIN : a[mid1-1];
		int l2 = (mid2==0) ? INT_MIN : b[mid2-1];
		int r1 = (mid1==n) ? INT_MAX : a[mid1];
		int r2 = (mid2==m) ? INT_MAX : b[mid2];

		if(l1<=r2 && l2<=r1){
			if((n+m)%2==1) return max(l1, l2); //even length
			else{
				float ans = (max(l1, l2) + min(r1, r2))/2.0;
				return ans;
			}
		} 
		else if(l1>r2){
			high=mid1-1;
		}
		else {
			low=mid1+1;
		}
	}
}
