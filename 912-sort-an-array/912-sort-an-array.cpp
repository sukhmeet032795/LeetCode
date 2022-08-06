class Solution {
public:
    
    void merge(int &start, int &mid, int &end, vector<int>& nums) {
        
        int i = start, j = (mid + 1);
        vector<int> out;
        while(i <= mid && j <= end) {
            if (nums[i] <= nums[j]) {
                out.emplace_back(nums[i++]);
            } else {
                out.emplace_back(nums[j++]);
            }
        };
        
        while(i <= mid) { out.emplace_back(nums[i++]); }
        while(j <= end) { out.emplace_back(nums[j++]); }
        
        int ind = 0;
        for(int i = start; i <= end; i++) {
            nums[i] = out[ind++];
        };
    };
    
    void mergeSort(int &start, int &end, vector<int>& nums) {
        
        if (start >= end)
            return;
        
        int mid = (start + end) >> 1;
        mergeSort(start, mid, nums);
        mid++;
        mergeSort(mid, end, nums);
        mid--;
        merge(start, mid, end, nums);
    };
    
    vector<int> sortArray(vector<int>& nums) {
        
        int len = nums.size(), start = 0, end = (len - 1);
        mergeSort(start, end, nums);
        return nums;
    }
};