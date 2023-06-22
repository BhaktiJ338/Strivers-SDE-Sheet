
void solve(int ind, int sum, vector<int> arr, int k, 
vector<vector<int>>&ans, vector<int>&ds){
    if(ind==arr.size()){
        if(sum==k){
            ans.push_back(ds);
        }
        return;
    }

    ds.push_back(arr[ind]);
    sum += arr[ind];
    solve(ind+1, sum, arr, k, ans, ds);
    ds.pop_back();
    sum -= arr[ind];
    solve(ind+1, sum, arr, k, ans, ds);
}


vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>>ans;
    vector<int>ds;

    solve(0, 0, arr, k, ans, ds);
    return ans;
}
