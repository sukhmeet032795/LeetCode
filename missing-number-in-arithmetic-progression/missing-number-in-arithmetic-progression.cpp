class Solution {
public:
    int missingNumber(vector<int>& arr) {
        
        int len = arr.size();
        int dist = INT_MAX;
        
        for(int i = 0; i < (len - 1); i++)
        {
            dist = min(dist, abs(arr[i] - arr[i+1]));
        };
        
        if(dist == 0)
            return arr[0];
        
        for(int i = 0; i < (len - 1); i++)
        {
            if(abs(arr[i] - arr[i+1]) > dist)
                return (min(arr[i], arr[i+1]) + dist);
        }
        
        return 0;
    }
};