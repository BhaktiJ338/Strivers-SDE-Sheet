#include <bits/stdc++.h> 

bool isPalindrome(int i, int j, string s){
    // int i=0, j=s.size()-1;

    while(i<=j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
void f(int start, string &s, 
vector<vector<string>>&ans, vector<string>&curr){
    if(start==s.length()){
        ans.push_back(curr);
        return;
    }

    for(int end=start; end<s.length(); end++){
        if(isPalindrome(start, end, s)){
            curr.push_back(s.substr(start, end-start+1));
            f(end+1, s, ans, curr);
            curr.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s) 
{
    vector<vector<string>>ans;
    vector<string>curr;

    f(0, s, ans, curr);
    return ans;
}
