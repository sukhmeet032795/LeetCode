class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> out(2, -1);
        map<int, int> m;
        for(int i = 0; i < nums.size(); i++) {
            if (m.find(target - nums[i]) != m.end()) {
                out[0] = m[target - nums[i]];
                out[1] = i;
                return out;
            }
            m[nums[i]] = i;
        }
        return out;
    }
};