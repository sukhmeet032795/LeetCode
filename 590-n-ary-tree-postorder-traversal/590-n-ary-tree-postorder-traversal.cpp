/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
//     void postOrder(Node* root, vector<int>& output) {
        
//         if (!root)
//             return;
        
//         for(int i = 0; i < root->children.size(); i++) {
//               postOrder(root->children[i], output);  
//         };
//         output.emplace_back(root->val);
//     };
    
//     vector<int> postorder(Node* root) {
        
//         vector<int> output;
//         postOrder(root, output);
//         return output;
//     }
    
    vector<int> postorder(Node* root) {
        
        vector<int> output;
        if (!root) return output;
        
        stack<Node*> ss;
        ss.push(root);
        
        while(!ss.empty()) {
            
            auto top = ss.top();
            ss.pop();
            for(auto itr : top->children) { ss.push(itr); }
            output.emplace_back(top->val);
        };
        
        reverse(output.begin(), output.end());
        return output;
    }
};