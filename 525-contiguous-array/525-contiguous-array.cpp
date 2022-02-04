class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        unordered_map<int,int>mp; //Define a Hashmap
        mp.insert({0,-1}); // Insert 0 in map as initially the sum is 0(Explained below)
        int c = 0, mx = 0; // Define a count and a max veriable
        for(int i = 0;i<nums.size();i++){
            nums[i] == 1 ? c++ : c--; // If ith value in nums array is 1 increment count by 1, if it's 0 decrement count by 1
			/*
			If we find out that the count already exists in the hash map if check if the current is greater than the last one 
			Therefore we insert 0 at the start so we can get the in the conditional statement if after decrementing we get another 0
			Eg  1  1  1  0  0  0  0  1
			    1  2  3  2  1  0 -1  0
			  0                0     0
			  Hence we get the max subarray as we insert 0 at -1 index
			*/ 
            if(mp.find(c)!=mp.end()) mx = max(mx,i-mp[c]);
            else mp.insert({c,i}); // Or else we will insert the count
        }
        return mx; //Fina
    }
};