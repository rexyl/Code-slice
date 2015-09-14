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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<vector<TreeNode*>> noderesult;
        if(root == NULL)
            return result;

        vector<TreeNode *> treelevel;
        treelevel.push_back(root);
        while(!treelevel.empty() )
        {
            int level_len = treelevel.size();
            vector<TreeNode*> treeleveltemp;
            
            for(int i = 0 ; i < level_len ; i++)
            {
                TreeNode *tn = treelevel[i];
                if(tn->left!=NULL)
                {
                    treeleveltemp.push_back(tn->left);
                }
                if(tn->right!=NULL)
                {
                    treeleveltemp.push_back(tn->right);
                }        
            }
            if(!treeleveltemp.empty())
            	noderesult.push_back(treeleveltemp);
            treelevel = treeleveltemp;
        }

        for(int i = noderesult.size()-1 ; i>=0 ; i--)
        {
        	vector<TreeNode*> vtn = noderesult[i];
        	vector<int> levelresult;
        	for(int j=0;j<vtn.size();j++)
        	{
        		TreeNode *tn = vtn[j];
        		levelresult.push_back(tn->val);
        	}
        	if(!levelresult.empty())
        		result.push_back(levelresult);
        }
        
        return result;
    }
};

//void test(vector<int> &v) {v.push_back(1); return;}
//int main()
//{
//	Solution s;
//	vector<int> v;
//	test(v);
//	cout<<v.size();
//
//	int iww;
//	cin>>iww;
//	return 0;
//}