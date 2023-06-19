#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    long ans=0, lmax=0, rmax=0, l=0, r=n-1;

    while(l<=r){
        if(arr[l]<=arr[r]){//there is a higher bar on right 
            if(arr[l]>=lmax) lmax = arr[l]; //need to update lmax
            else ans += lmax-arr[l];  //lmax is already greater, update answer
            l++;
        } else {
          if (arr[r] >= rmax)
            rmax = arr[r];
          else
            ans += rmax - arr[r];
          r--;
        }
    }
    return ans;
}
