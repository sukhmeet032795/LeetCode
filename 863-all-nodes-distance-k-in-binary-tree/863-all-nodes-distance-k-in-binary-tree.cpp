/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    vector<int> output;
    unordered_set<TreeNode*> visited;
    
    unordered_map<TreeNode*, TreeNode*> getParents(TreeNode* curr) {
        
        unordered_map<TreeNode*, TreeNode*> um;
        um[curr] = nullptr;
        
        queue<TreeNode*> q;
        q.push(curr);
        while(!q.empty()) {
            
            TreeNode* tmp = q.front();
            q.pop();
            
            if (tmp->left) {
                um[tmp->left] = tmp;
                q.push(tmp->left);
            };
            
            if (tmp->right) {
                um[tmp->right] = tmp;
                q.push(tmp->right);
            };
        };
        return um;
    };
    
    void getNodesAtDist(TreeNode* curr, int k, unordered_map<TreeNode*, TreeNode*>& parents) {
        
        if (k < 0)
            return;
        
        if (k == 0) {
            output.emplace_back(curr->val);
            return;
        };
        
        k--;
        if (curr->left && visited.find(curr->left) == visited.end()) {
            visited.insert(curr->left);
            getNodesAtDist(curr->left, k, parents);
        }
        
        if (curr->right && visited.find(curr->right) == visited.end()) {
            visited.insert(curr->right);
            getNodesAtDist(curr->right, k, parents);
        }
        
        if (parents[curr] != nullptr && visited.find(parents[curr]) == visited.end()) {
            visited.insert(parents[curr]);
            getNodesAtDist(parents[curr], k, parents);
        }
    };
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        output.clear();
        visited.clear();
        if (root == nullptr || target == nullptr)
            return output;
        
        unordered_map<TreeNode*, TreeNode*> parents = getParents(root);
        visited.insert(target);
        getNodesAtDist(target, k, parents);
        
        return output;
    };
};