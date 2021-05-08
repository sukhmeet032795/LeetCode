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
    void insert(TreeNode* root, int value)
    {
        TreeNode* curr = root, *prev = NULL;
        while(true)
        {
            if(curr == NULL)
            {
                if(value < prev->val)
                {
                    TreeNode* left = new TreeNode(value);
                    prev->left = left;
                    return;
                }
                else
                {
                    TreeNode* right = new TreeNode(value);
                    prev->right = right;
                    return;
                }
            }
            
            if(curr->val > value)
            {
                prev = curr;
                curr = curr->left;
            }
            else
            {
                prev = curr;
                curr = curr->right;
            }
        }
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int len = preorder.size();
        
        if(len == 0)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[0]);
        
        for(int i = 1; i < len; i++)
            insert(root, preorder[i]);
        
        return root;
    }
};