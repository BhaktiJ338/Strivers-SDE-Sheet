#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long currsum=0, maxsum=INT_MIN;

    for(int i=0; i<n; i++){
        currsum += arr[i];
        if(currsum<0) currsum=0;
        if(currsum>maxsum){
            maxsum = currsum;
        }
    }
    return maxsum;
}
