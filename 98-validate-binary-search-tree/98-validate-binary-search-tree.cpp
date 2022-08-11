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
//     bool validate(TreeNode* root, int Min, int Max) {
        
//         if (!root)
//             return true;

//         if (root->val < Min || root->val > Max)
//             return false;
        
//         bool left =  true;
//         bool right = true;
//         if (root->left) {
//             left = validate(root->left, Min, root->val - 1);
//         }
        
//         if (root->right) {
//             right = validate(root->right, root->val + 1, Max);
//         }
        
//         if (left == false || right == false)
//             return false;
//         return true;
//     };
    
//     bool isValidBST(TreeNode* root) {
//         long Min = INT_MIN, Max = INT_MAX;
//         return validate(root, Min, Max);
//     }
    
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
};