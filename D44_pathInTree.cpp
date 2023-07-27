#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/
bool findPath(TreeNode<int> *root, int x, vector<int>&ds){
	if(!root) return false;
	
	if(root->data == x){
		ds.push_back(root->data);
		return true;
	}

	ds.push_back(root->data);
	if(findPath(root->left, x, ds) || findPath(root->right, x, ds) ) return true;
	ds.pop_back();

	return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
	if(root->data == x) return {x};
    vector<int>ds;
	findPath(root, x, ds);
	return ds;
}
