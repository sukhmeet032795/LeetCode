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
    struct customSort{
        bool operator()(const pair<TreeNode*, int> &p1, const pair<TreeNode*, int> &p2) {
            if (p1.second == p2.second) {
                return p1.first->val > p2.first->val;
            };
            return p1.second > p2.second;
        };
    };
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> output;
        unordered_map<int, vector<int>> m;
        
        priority_queue<pair<TreeNode*, int>, vector<pair<TreeNode*, int>>, customSort> q;
        priority_queue<pair<TreeNode*, int>, vector<pair<TreeNode*, int>>, customSort> q1;
        q.push(make_pair(root, 0));
        
        int Max = INT_MIN, Min = INT_MAX;
        
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                auto tmp = q.top();
                q.pop();
                
                if (tmp.first->left)
                    q1.push(make_pair(tmp.first->left, tmp.second - 1));
                
                if (tmp.first->right)
                    q1.push(make_pair(tmp.first->right, tmp.second + 1));
                
                m[tmp.second].push_back(tmp.first->val);
                Max = max(Max, tmp.second);
                Min = min(Min, tmp.second);
            };
            q = q1;
            while(!q1.empty()) q1.pop();
        };
        
        for(int i = Min; i <= Max; i++) {
            auto val = m[i];
            output.push_back(val);
        };
                
        return output;
    }
};