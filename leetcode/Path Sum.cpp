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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> v;
        if(root==NULL) return v;
        else
        {
            vector<vector<int>> result;
            vector<int> v;
            pathSumhelper(root,sum,v,result);
            return result;
        }
    }
    void pathSumhelper(TreeNode* root, int sum, vector<int> &v,vector<vector<int>> &result) {
        if(root->right==NULL && root->left==NULL)
        {
            if(root->val == sum)
            {
                v.push_back(sum);
                result.push_back(v);
                return;
            }
            else
            {
                v.clear();
                return;
            }
        }
        else if(root->right!=NULL && root->left==NULL) 
        {
        	vector<int> temp_v;
        	temp_v = v;
            v.push_back(root->val);
            pathSumhelper(root->right , sum - root->val,v,result);
            v = temp_v;
            return;
        }
        else if(root->left!=NULL && root->right==NULL) 
        {
        	vector<int> temp_v;
        	temp_v = v;
            v.push_back(root->val);
            pathSumhelper(root->left , sum - root->val,v,result);
            v = temp_v;
            return;
        }
        else
        {
        	vector<int> temp_v1;
            vector<int> temp_v2;
        	temp_v1 = v;
        	v.push_back(root->val);
            temp_v2 = v;
            pathSumhelper(root->left , sum - root->val,v,result);
            v=temp_v2;
            pathSumhelper(root->right , sum - root->val,v,result);
            v=temp_v1;
            return;
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