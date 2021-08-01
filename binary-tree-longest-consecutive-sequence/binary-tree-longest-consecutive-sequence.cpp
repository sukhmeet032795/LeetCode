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
    tuple<int, int> getAnswer(TreeNode* root, int &Max)
    {
        if(root == NULL)
            return {0, 0};
        
        if(root->left == NULL && root->right == NULL){
            Max = max(Max, 1);
            return {1, 1};
        }
        
        auto lef = getAnswer(root->left, Max);
        auto right = getAnswer(root->right, Max);
        
        int lefVal = 1, rigVal = 1;
        
        if(root->left != NULL && (root->left->val-1 == root->val))
        {
            lefVal = 1 + max(get<0>(lef), get<1>(lef));
        }
        
        if(root->right != NULL && (root->right->val-1 == root->val))
        {
            rigVal = 1 + max(get<0>(right), get<1>(right));
        }
        
        Max = max(Max, max(lefVal, rigVal));
        return {lefVal, rigVal};
    }
    
    int longestConsecutive(TreeNode* root) {
        
        int Max = 0;
        getAnswer(root, Max);
        return Max;
    }
};