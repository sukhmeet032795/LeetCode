class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> m;
        for(auto num : nums) {
            m[num]++;
        };
        
        for(auto ele : m) {
            if (ele.second >= ceil((float)nums.size()/2))
                return ele.first;
        }
        
        return -1;
    }
};