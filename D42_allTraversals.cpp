
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    if(!root) return {};
    stack<pair<BinaryTreeNode<int>*, int>>st;
    st.push({root, 1});
    // vector<vector<int>>ans;
    vector<int>pre, post, ino;
    while(!st.empty()){
        int vis = st.top().second;
        if(vis==1){
            pre.push_back(st.top().first->data);
            st.top().second++;
            if(st.top().first->left) st.push({st.top().first->left, 1});
        }
        else if(vis==2){
            ino.push_back(st.top().first->data);
            st.top().second++;
            if(st.top().first->right) st.push({st.top().first->right, 1});
        }
        else{
            post.push_back(st.top().first->data);
            st.pop();
        }
    }
    return {ino, pre, post};
}
