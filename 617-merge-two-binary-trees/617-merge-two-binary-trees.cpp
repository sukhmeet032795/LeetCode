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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        if (!root1 && !root2)
            return NULL;
        
        int val = ((root1 != nullptr) ? root1->val : 0) + ((root2 != nullptr) ? root2->val : 0);
        
        if (root1 == nullptr)
            root1 = new TreeNode(val);
        else
            root1->val = val;
        
        root1->left = mergeTrees(root1->left, (root2 != nullptr ? root2->left : nullptr));
        root1->right = mergeTrees(root1->right, (root2 != nullptr ? root2->right : nullptr));
        
        return root1;
    }
};