int singleNonDuplicate(vector<int>& arr)
{
	int l=0, r=arr.size()-1;
	//first occurance - even index
	//second occurance - odd index

	while(l<r){
		int mid = l+(r-l)/2;

		if((mid%2==0 && arr[mid]==arr[mid+1]) || (mid%2==1 && arr[mid]==arr[mid-1])){
			l = mid+1;
		}
		else r = mid;
	}

	return arr[l];
}
