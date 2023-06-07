#include <bits/stdc++.h> 


int merge(int l, int mid, int r, long long *arr){
    int cnt = 0;

    int i=l, j=mid+1, k=0;
    int temp[r-l+1];
    while(i<=mid && j<=r){
        if(arr[i]>arr[j]){
            temp[k++] = arr[j++];
            cnt += (mid-i+1);
        }
        else{
            temp[k++] = arr[i++];
        }
    }

    while(i<=mid) temp[k++] = arr[i++];
    while(j<=r) temp[k++] = arr[j++];
    for (i=0; i<k; i++) arr[l+i] = temp[i]; 

    return cnt;
}

int mergeSort(int l, int r, long long *arr){
    int ans=0;
    if(l>=r) return 0;
    int mid = l+(r-l)/2;
    
    ans += mergeSort(l, mid, arr);
    ans += mergeSort(mid+1, r, arr);
    ans += merge(l, mid, r, arr);

    return ans;
}
long long getInversions(long long *arr, int n){
    return mergeSort(0, n-1, arr);
}
