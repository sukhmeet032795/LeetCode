class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int tGas = 0, tCost = 0, len = gas.size();
        for(int i = 0; i < len; i++) {
            tGas += gas[i];
            tCost += cost[i];
        };
        
        if(tGas < tCost)
            return -1;
        
        int sCost = 0, start = 0;
        for(int i = 0; i < len; i++) {
            sCost += (gas[i] - cost[i]);
            
            if(sCost < 0) {
                start = i + 1;
                sCost = 0;
            }
        }
        
        return start;
    }
};