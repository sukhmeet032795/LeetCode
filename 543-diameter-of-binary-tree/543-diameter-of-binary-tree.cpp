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
    int diameter(TreeNode* root, int &maxDiameter) {
        
        if (root == NULL)
            return 0;
        
        int leftDia = diameter(root->left, maxDiameter);
        int rightDia = diameter(root->right, maxDiameter);
        
        int dia = 1 + leftDia + rightDia;
        maxDiameter = max(maxDiameter, dia);
        
        return max(1 + leftDia, 1 + rightDia);
    };
    
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        diameter(root, maxDiameter);
        return (maxDiameter - 1);
    };
};