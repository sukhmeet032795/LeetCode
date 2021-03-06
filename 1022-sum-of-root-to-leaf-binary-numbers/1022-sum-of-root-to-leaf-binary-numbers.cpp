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
    int ans;
    void traverseTree(TreeNode* root, int val) {
        if(root == NULL) {
            ans += val;
            return;
        }
        
        val = val << 1 | root->val;
        
        if(root->left == NULL && root->right == NULL) {
            ans += val;
            return;
        }
        
        if(root->left)
            traverseTree(root->left, val);
        
        if(root->right)
            traverseTree(root->right, val);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        ans = 0;
        traverseTree(root, 0);
        return ans;
    }
};