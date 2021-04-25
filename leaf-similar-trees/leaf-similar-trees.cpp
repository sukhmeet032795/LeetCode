/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<int> getLeaves(TreeNode* root1)
    {
        if(root1 == NULL)
            return {};
        
        vector<int> output;
        stack<TreeNode*> s;
        s.push(root1);
        
        while(!s.empty())
        {
            TreeNode *tmp = s.top();
            s.pop();
            
            if(tmp->left == NULL && tmp->right == NULL)
            {
                output.push_back(tmp->val);
            }
            else
            {
                if(tmp->left)
                    s.push(tmp->left);
                
                if(tmp->right)
                    s.push(tmp->right);
            }
        }
        
        return output;
    };
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> out1 = getLeaves(root1);
        vector<int> out2 = getLeaves(root2);
        
        if(out1.size() != out2.size())
            return false;
        
        for(int i = 0; i < out1.size(); i++)
        {
            // cout<<out1[i]<<" "<<out2[i]<<endl;
            if(out1[i] != out2[i])
                return false;
        }
        return true;
    }
};