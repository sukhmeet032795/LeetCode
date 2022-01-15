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
    
    void traverseTree(TreeNode* root, bool &ans, int &targetSum, int sum) {
        
        if(root == NULL) {
            if(sum == targetSum)
                ans = true;
            return;
        }
        
        sum += root->val;
        if(root->left == NULL && root->right == NULL)
        {
            if(sum == targetSum)
                ans = true;
            return;
        }
        
        if(root->left)
            traverseTree(root->left, ans, targetSum, sum);
        
        if(root->right)
            traverseTree(root->right, ans, targetSum, sum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root == NULL)
            return false;
        
        bool check = false;
        traverseTree(root, check, targetSum, 0);
        return check;
    }
};