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
    int closestValue(TreeNode* root, double target) {
        double minDiff = numeric_limits<double>::max();
        int closestValue = INT_MIN;
        TreeNode* n = root;

        while (n) {
            double currentDiff = abs(n->val - target);
            if (currentDiff < minDiff) {
                closestValue = n->val;
                minDiff = currentDiff;
            }

            if (target < n->val)
                n = n->left;
            else
                n = n->right;
        }
        
        return closestValue;
    }
};