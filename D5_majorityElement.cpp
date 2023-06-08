#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	int cnt=0, candidate=arr[0];
    for(int i=1; i<n; i++){
        if(cnt==0) candidate=arr[i];
        if(arr[i]==candidate) cnt++;
        else cnt--;
    }
    cnt=0;
    for(int i=0; i<n; i++){
        if(arr[i]==candidate) cnt++;
    }
    if(cnt>floor(n/2)) return candidate;
    return -1;
}
