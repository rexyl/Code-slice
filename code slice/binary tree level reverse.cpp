//class Solution {
//public:
//    vector<vector<int>> levelOrderBottom(TreeNode* root) {
//        vector<vector<int>> result;
//        vector<vector<TreeNode*>> noderesult;
//        if(root == NULL)
//            return result;
//
//        vector<TreeNode *> treelevel;
//
//        vector<TreeNode*> v(1,root);
//        noderesult.push_back(v);
//
//        treelevel.push_back(root);
//        while(!treelevel.empty() )
//        {
//            int level_len = treelevel.size();
//            vector<TreeNode*> treeleveltemp;
//            
//            for(int i = 0 ; i < level_len ; i++)
//            {
//                TreeNode *tn = treelevel[i];
//                if(tn->left!=NULL)
//                {
//                    treeleveltemp.push_back(tn->left);
//                }
//                if(tn->right!=NULL)
//                {
//                    treeleveltemp.push_back(tn->right);
//                }        
//            }
//            if(!noderesult.empty())
//            	noderesult.push_back(treeleveltemp);
//            treelevel = treeleveltemp;
//        }
//
//        for(int i = noderesult.size()-1 ; i>=0 ; i--)
//        {
//        	vector<TreeNode*> vtn = noderesult[i];
//        	vector<int> levelresult;
//        	for(int j=0;j<vtn.size();j++)
//        	{
//        		TreeNode *tn = vtn[j];
//        		levelresult.push_back(tn->val);
//        	}
//        	if(!levelresult.empty())
//        		result.push_back(levelresult);
//        }
//        
//        return result;
//    }
//};