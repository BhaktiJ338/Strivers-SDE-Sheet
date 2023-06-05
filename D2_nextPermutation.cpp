#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    int ind1=0, ind2=0;
    for(ind1=n-2; ind1>=0; ind1--){
        if(permutation[ind1]<permutation[ind1+1]){
            break;
        }
    }
    if(ind1==-1){
        reverse(permutation.begin(), permutation.end());
        return permutation;
    }

    for(ind2=n-1; ind2>ind1; ind2--){
        if(permutation[ind2]>=permutation[ind1]){
            swap(permutation[ind1], permutation[ind2]);
            reverse(permutation.begin()+ind1+1, permutation.end());
            return permutation;
        }
    }
}
