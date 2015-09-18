/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
    	if(root==NULL)
    		return 0;
    	if(root->left == NULL && root->right == NULL)
        {
        	if(root->val==sum)
        		return 1;
        	else
        		return 0;
        }
        else if(root->left != NULL && root->right == NULL)
        {
        	return hasPathSum(root->left,sum-root->val);
        }
        else if(root->left == NULL && root->right != NULL)
        	return hasPathSum(root->right,sum-root->val);
        else
        {
        	return hasPathSum(root->right,sum-root->val) || hasPathSum(root->left,sum-root->val);
        }
    }
};*/