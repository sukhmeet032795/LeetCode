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
class BSTIterator {
public:
    list<int> l;
    BSTIterator(TreeNode* root) {
        
        l.clear();
        stack<TreeNode*> q;
        TreeNode* curr = root;
        
        while(curr != nullptr || !q.empty()) {
            
            if (curr) {
                q.push(curr);
                curr = curr->left;
            } else {
                curr = q.top();
                q.pop();
                l.push_back(curr->val);
                curr = curr->right;
            }
        };
    }
    
    int next() {
        
        int top = l.front();
        l.pop_front();
        return top;
    }
    
    bool hasNext() {
        return !(l.size() == 0);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */