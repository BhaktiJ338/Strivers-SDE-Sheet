int height(BinaryTreeNode<int>* root){
    if(!root) return 0;

    int left = height(root->left);
    int right = height(root->right);

    return 1 + max(left, right);
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    if(!root) return true;

    int left = height(root->left);
    int right = height(root->right);
    if(abs(left-right) <= 1 && isBalancedBT(root->left) && isBalancedBT(root->right))
        return true;

    return false;
}
