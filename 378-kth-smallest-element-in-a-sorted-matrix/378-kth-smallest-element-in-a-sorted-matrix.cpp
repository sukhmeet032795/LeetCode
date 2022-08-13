class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        priority_queue<int> p;
        for(auto mat : matrix) {
            for(auto itr : mat) {
                p.push(itr);
                if (p.size() > k)
                    p.pop();
            };
        };
        
        return p.top();
    };
};