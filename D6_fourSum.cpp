#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    sort(arr.begin(), arr.end());
    for(int i=0; i<=n-4; i++){
        for(int j=i+1; j<=n-3; j++){
            int x=j+1, y=n-1;
            int sum2 = arr[i]+arr[j];
            while(x<y){
                int curr = sum2+arr[x]+arr[y];
                if(curr==target) return "Yes";
                else if(curr<target) x++;
                else y--;
            }
        }
    }
    return "No";
}
