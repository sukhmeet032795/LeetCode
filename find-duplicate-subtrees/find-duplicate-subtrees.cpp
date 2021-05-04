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
    
    string generateLibrary(TreeNode* root, unordered_map<string, vector<TreeNode *> > &library)
    {
        if(root == NULL)
            return "null,";
        
        string tmp = to_string(root->val) + ",";
        
        tmp += generateLibrary(root->left, library);
        tmp += generateLibrary(root->right, library);
        
        library[tmp].push_back(root);
        
        return tmp;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        unordered_map<string, vector<TreeNode *> > library;

        generateLibrary(root, library);			

        vector<TreeNode *> output;
        for (auto it = library.begin(); it != library.end(); ++it)
        {
            if (it->second.size() > 1)
                output.push_back(it->second[0]);
        }
        
        return output;
    }
};