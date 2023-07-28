
int getMaxWidth(TreeNode<int> *root)
{
    if(!root) return 0;
    queue<TreeNode<int> *>q;
    q.push(root);
    int res = INT_MIN;

    while(!q.empty()){
        int sz = q.size();
        res = max(res, sz);

        while(sz--){
            auto curr = q.front();
            q.pop();
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
    return res;
}
