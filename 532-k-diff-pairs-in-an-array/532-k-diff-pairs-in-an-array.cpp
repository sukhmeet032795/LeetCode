class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        int len = nums.size();
        set<int> m;
        
        set<pair<int, int>> s;
        
        for(int i = 0; i < len; i++) {
            
            int tmp1 = nums[i] - k, tmp2 = nums[i] + k;
            
            if(m.find(tmp1) != m.end()) {
                
                if(tmp1 < nums[i])
                    s.insert(make_pair(tmp1, nums[i]));
                else
                    s.insert(make_pair(nums[i], tmp1));
            }
            
            if(m.find(tmp2) != m.end()) {
                
                if(tmp2 < nums[i])
                    s.insert(make_pair(tmp2, nums[i]));
                else
                    s.insert(make_pair(nums[i], tmp2));
            }
            
            m.insert(nums[i]);
        }
        
        return s.size();
    }
};
