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
    
    struct Info {
 
        int max;
        int min;
        bool isBST;
        int sum;
        int currmax;
    };

    // Returns information about subtree such as
    // subtree with maximum sum which is also a BST
    Info MaxSumBSTUtil(TreeNode* root, int& maxsum)
    {
        // Base case
        if (root == NULL)
            return { INT_MIN, INT_MAX, true, 0, 0 };

        if (root->left == NULL && root->right == NULL) {
            maxsum = max(maxsum, root->val);
            return { root->val, root->val, true, root->val, maxsum };
        }

        // Store information about the left subtree
        Info L = MaxSumBSTUtil(root->left, maxsum);

        // Store information about the right subtree
        Info R = MaxSumBSTUtil(root->right, maxsum);

        Info BST;

        // If the subtree rooted under the current node
        // is a BST
        if (L.isBST && R.isBST && L.max < root->val && R.min > root->val) {

            BST.max = max(root->val, max(L.max, R.max));
            BST.min = min(root->val, min(L.min, R.min));

            maxsum = max(maxsum, R.sum + root->val + L.sum);
            BST.sum = R.sum + root->val + L.sum;

            // Update the current maximum sum
            BST.currmax = maxsum;

            BST.isBST = true;
            return BST;
        }

        // If the whole tree is not a BST then
        // update the current maximum sum
        BST.isBST = false;
        BST.currmax = maxsum;
        BST.sum = R.sum + root->val + L.sum;

        return BST;
    }

    // Function to return the maximum
    // sum subtree which is also a BST
    int MaxSumBST(TreeNode* root)
    {
        int maxsum = 0;
        return MaxSumBSTUtil(root, maxsum).currmax;
    }

    int maxSumBST(TreeNode* root) {
        
        int sum = MaxSumBST(root);
        return sum;
    }
};