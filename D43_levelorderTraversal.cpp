vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    if(!root) return {};
    vector<int>ans;
    queue<BinaryTreeNode<int> *>q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            ans.push_back(it->val);
            if(it->left) q.push(it->left);
            if(it->right) q.push(it->right);
        }
    }
    return ans;
}
