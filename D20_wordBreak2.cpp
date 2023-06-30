#include <bits/stdc++.h> 

void f(int ind, string &curr, string &s, vector<string> &dict, 
vector<string>&ans){
    if(ind==s.size()){
        if(curr.size()>=s.size()) ans.push_back(curr);
        return;
    } 

    for(int i=ind; i<s.size(); i++){
        string temp = s.substr(ind, i-ind+1);
        string prevCurr = curr;
        if(find(dict.begin(), dict.end(), temp) != dict.end()){
            if(curr.size()==0) curr = temp;
            else curr = curr+" "+temp;
            f(i+1, curr, s, dict, ans);
            curr = prevCurr;
        }
    }

}
vector<string> wordBreak(string &s, vector<string> &dict)
{
    
vector<string>ans;
    string curr = "";
    f(0, curr, s, dict, ans);
    return ans;
}
