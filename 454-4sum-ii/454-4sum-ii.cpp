class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        unordered_map<int, int> s1, s2;
        int n = nums1.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                s1[nums1[i] + nums2[j]]++;
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                s2[nums3[i] + nums4[j]]++;
            }
        }
        
        int ans = 0;
        for(auto val : s1) {
            int tmp = 0 - val.first;
            if (s2.find(tmp) != s2.end()) {
                ans += (val.second * s2[tmp]);
            }
        }
        
        return ans;
    }
};