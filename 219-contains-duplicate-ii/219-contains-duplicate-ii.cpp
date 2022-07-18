class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int index = 0;
        for(auto num : nums) {
            if (m.find(num) == m.end()) {
                m[num] = index;
            } else {
                int prev = m[num];
                if (abs(prev - index) <= k)
                    return true;
                m[num] = index;
            }
            index++;
        };
        return false;
    };
};