class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int, vector<int>, greater<int>> v;
        int i = 0;
        
        for( ; i < k; i++) v.push(nums[i]);
        
        for( ; i < nums.size(); i++) {
            
            if (v.top() < nums[i]) {
                v.pop();
                v.push(nums[i]);
            }
        }
        
        return v.top();
    }
};