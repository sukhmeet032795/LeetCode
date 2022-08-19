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
    TreeNode* generate(int start, int end, vector<int>& nums) {
        
        if (start > end) return nullptr;
        
        int mid = (((end - start) >> 1) + start);
        TreeNode* curr = new TreeNode(nums[mid]);
        
        curr->left = generate(start, mid - 1, nums);
        curr->right = generate(mid + 1, end, nums);
        
        return curr;
    };
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int end = nums.size() - 1, start = 0;
        return generate(start, end, nums);
    };
};