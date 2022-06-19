class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        int len1 = nums1.size(), len2 = nums2.size();
    
        auto getMap = [&](vector<int> & nums) -> unordered_map<int, int> {
            unordered_map<int, int> m;
            for (auto num : nums) {
                m[num]++;
            }
            return m;
        };
        
        unordered_map<int, int> ele = (len1 <= len2) ? getMap(nums1) : getMap(nums2);
        
        vector<int> out;
        for(auto num : ((len1 <= len2) ? nums2 : nums1)) {
            if(ele.find(num) != ele.end() && ele[num] != 0) {
                out.push_back(num);
                ele[num]--;
            }
        }
        
        return out;
    }
};