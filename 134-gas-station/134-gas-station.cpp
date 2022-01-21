class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int tGas = 0, tCost = 0;
        for(int i = 0; i < gas.size(); i++) {
            tGas += gas[i];
            tCost += cost[i];
        }
        
        if(tGas < tCost)
            return -1;
        
        int start = 0, gasS = 0;
        for(int i = 0; i < gas.size(); i++) {
            gasS += gas[i] - cost[i];
            
            if(gasS < 0)
            {
                gasS = 0;
                start = i+1;
            }
        }
        
        if(start == gas.size())
            return -1;
        return start;
    }
};