#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root) {
    if(!root) return {};
    vector<int>ans;
    
    map<int, int>mp;
    queue<pair<TreeNode<int> *, int>>q;
    q.push({root, 0});

    while(!q.empty()){
        auto node = q.front().first;
        int level = q.front().second;
        q.pop();
        if(mp[level]==0) mp[level] = node->val;

        if(node->left) q.push({node->left, level-1});
        if(node->right) q.push({node->right, level+1});
    }

    for(auto it:mp){
        ans.push_back(it.second);
    }
    return ans;

}
