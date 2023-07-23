#include <bits/stdc++.h> 

void preorder(TreeNode<int>*node, int level, vector<int>&ans){
    if(!node) return;
    if(level==ans.size()) ans.push_back(node->data);

    if(node->left) preorder(node->left, level+1, ans);
    if(node->right) preorder(node->right, level+1, ans);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int>ans;
    if(!root) return ans;
    preorder(root, 0, ans);
}
