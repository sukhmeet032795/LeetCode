class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int tGas = 0, tCost = 0;
        tGas = accumulate(gas.begin(), gas.end(), tGas);
        tCost = accumulate(cost.begin(), cost.end(), tCost);
        
        if (tGas < tCost)
            return -1;
        
        int start = 0, dist = 0;
        for(int i = 0; i < cost.size(); i++) {
            dist += (gas[i] - cost[i]);
            if (dist < 0) {
                start = (i+1);
                dist = 0;
            }
        };
        return start;
    }
};