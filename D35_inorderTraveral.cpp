#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getInOrderTraversal(TreeNode *root)
{

    vector<int>res;
    if(!root) return res;
    stack<TreeNode*>st;

    while(root || !st.empty()){
        while(root){
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        res.push_back(root->data);
        root = root->right;
    }

    return res;
}
