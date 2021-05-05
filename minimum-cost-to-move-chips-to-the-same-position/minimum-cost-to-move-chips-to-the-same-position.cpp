class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        
        int len = position.size();
        int odd = 0, even = 0;
        
        for(int i = 0; i < len; i++)
        {
            if(position[i] % 2)
                even++;
            else
                odd++;
        }
        
        return min(odd, even);
    }
};