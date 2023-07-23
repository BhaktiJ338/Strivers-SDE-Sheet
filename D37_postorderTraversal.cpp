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
vector<int> getPostOrderTraversal(TreeNode *root)
{
    if(!root) return {};
    vector<int>ans;
    stack<TreeNode*>st;
    TreeNode * curr = root;

    while(!st.empty() || curr){
        //go , push leftmost nodes
        while(curr){
            st.push(curr);
            curr = curr->left;
        }
        //now curr is NULL i.e No left child
        //check right child
        TreeNode *temp = st.top()->right;//leftmost->right

        if(temp){
            curr = temp;
        }
        else{
            temp = st.top();
            st.pop();
            ans.push_back(temp->data); 
            //done with left, right & node, go to parent

            while(!st.empty() && temp==st.top()->right){
                //st.top()->right = parent
                temp = st.top();
                st.pop();
                ans.push_back(temp->data); 
            }
        }
    }
    return ans;
}
