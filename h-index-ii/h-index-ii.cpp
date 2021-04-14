class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        reverse(citations.begin(), citations.end());
        int Max = 0, ind = 1;
        for(int i = 0; i < citations.size(); i++)
        {
            if(citations[i] >= ind)
                Max = max(Max, ind);
            ind++;
        }
        
        return Max;
    }
};