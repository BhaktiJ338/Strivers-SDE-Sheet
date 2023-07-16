
#include <algorithm>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// priority_queue<int>maxh;
	// priority_queue<int, vector<int>, greater<int>>minh;

	// for(auto it:arr){
	// 	maxh.push(it);
	// 	if(maxh.size()>k) maxh.pop();
	// 	minh.push(it);
	// 	if(minh.size()>k) minh.pop();
	// }

	sort(arr.begin(), arr.end());

	int l = arr[k-1];
	int s = arr[n-k];

	vector<int>ans = {l , s};

	return ans;
}
