#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    int cnt1=0, cnt2=0, cand1, cand2, n=arr.size();

    for(auto it:arr){
        if(it==cand1){
            cnt1++;
        }
        else if(it==cand2){
            cnt2++;
        }
        else if(cnt1==0){
            cand1=it;
            cnt1=1;
        }
        else if(cnt2==0){
            cand2=it;
            cnt2=1;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }
    vector<int>v;
    cnt1=cnt2=0;
    for(auto it:arr){
        if(it==cand1) cnt1++;
        if(it==cand2) cnt2++;
    }
    if(cnt1>(n/3)) v.push_back(cand1);
    if(cnt2>(n/3)) v.push_back(cand2);
    return v;
}
