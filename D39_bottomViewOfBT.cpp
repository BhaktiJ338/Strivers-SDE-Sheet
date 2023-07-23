vector<int> bottomView(BinaryTreeNode<int> * root){
    if(!root) return {};
    vector<int>ans;
    
    map<int, int>mp;
    queue<pair<BinaryTreeNode<int> *, int>>q;
    q.push({root, 0});

    while(!q.empty()){
        auto node = q.front().first;
        int level = q.front().second;
        q.pop();
        mp[level] = node->data;

        if(node->left) q.push({node->left, level-1});
        if(node->right) q.push({node->right, level+1});
    }

    for(auto it:mp){
        ans.push_back(it.second);
    }
    return ans;
}
