class Solution {
public:
    
    void merge(int &start, int &mid, int &end, vector<int> &nums) {
        
        int i = start, j = mid+1;
        vector<int> tmp;
        for( ; i <= mid && j <= end; ) {
            if (nums[i] <= nums[j]) {
                tmp.emplace_back(nums[i++]);
            } else {
                tmp.emplace_back(nums[j++]);
            }
        };
        
        while(i <= mid) {
            tmp.emplace_back(nums[i++]);
        }
        
        while(j <= end) {
            tmp.emplace_back(nums[j++]);
        }
        
        int ind = 0;
        for(int i = start; i <= end; i++) {
            nums[i] = tmp[ind++];
        };
    };
    
    void mergeSort(int start, int end, vector<int>& nums) {
        
        if (start >= end)
            return;
        
        int mid = (start + end) >> 1;
        mergeSort(start, mid, nums);
        mergeSort(mid+1, end, nums);
        merge(start, mid, end, nums);
    };
    
    vector<int> sortArray(vector<int>& nums) {
        
        int start = 0, end = (nums.size() - 1);
        mergeSort(start, end, nums);
        return nums;
    };
};