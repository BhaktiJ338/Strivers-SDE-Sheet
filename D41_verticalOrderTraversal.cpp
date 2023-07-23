vector<int> verticalOrderTraversal(TreeNode<int> *root){
    if(!root) return {};
    map<int, vector<int>>mp;
    queue<pair<int, TreeNode<int> *>>q;
    vector<int>ans;
    q.push({0, root});

    while(!q.empty()){
        int level = q.front().first;
        auto node = q.front().second;
        q.pop();

        mp[level].push_back(node->data);
        if(node->left) q.push({level-1, node->left});
        if(node->right) q.push({level+1, node->right});
    }

    for(auto it:mp){
        vector<int>curr = it.second;
        for(auto it:curr) ans.push_back(it);
    }
    return ans;
}
