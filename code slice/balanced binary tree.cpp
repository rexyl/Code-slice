#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int depth(TreeNode* n)
    {
        if(n==NULL)
            return 0;
        else
            return 1+max(depth(n->left) , depth(n->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return 1;
        else
        {
            int leftdepth = depth(root->left) , rightdepth = depth(root->right) ;
            if(abs(leftdepth-rightdepth)>1)
                return 0;
            else
            {
                return isBalanced(root->left) && isBalanced(root->right) ;
            }
        }
    }
};

//int main()
//{
//	Solution s;
//	
//	int iww;
//	cin>>iww;
//	return 0;
//}
