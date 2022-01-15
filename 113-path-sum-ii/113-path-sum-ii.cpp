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
    
    vector<vector<int>> ans;
    
    void traverseTree(TreeNode* root, int &sum, vector<int> &path, int &targetSum) {
        
        sum += root->val;
        path.push_back(root->val);
        
        if(root->left == NULL && root->right == NULL)
        {
            if (sum == targetSum) {
                ans.push_back(path);
            }
        }
        
        if(root->left)
            traverseTree(root->left, sum, path, targetSum);
        
        if(root->right)
            traverseTree(root->right, sum, path, targetSum);
        
        sum -= root->val;
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        ans.clear();
        if(root == NULL)
            return ans;
        
        int sum = 0;
        vector<int> path;
        traverseTree(root, sum, path, targetSum);
        return ans;
    }
};