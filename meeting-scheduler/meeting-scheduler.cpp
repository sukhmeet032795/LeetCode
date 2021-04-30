class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        
        int i = 0, j = 0, len1 = slots1.size(), len2 = slots2.size();
        
        while(i < len1 && j < len2)
        {
            int Max = max(slots1[i][0], slots2[j][0]);
            int Min = min(slots1[i][1], slots2[j][1]);
            
            if(Max < Min)
            {
                if((Min - Max) >= duration)
                {
                    return {Max, (Max + duration)};
                }
            }
            
            if(slots1[i][1] > slots2[j][1])
                j++;
            else if(slots1[i][1] < slots2[j][1])
                i++;
            else{
                i++;
                j++;
            }
        };
        
        return {};
    }
};