class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        if (n == 0) {
            return 0;
        }
        // the minimum sum of costs to reach the top from the i-th stair
        vector<int> sum_cost(n, 0);
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1 || i == n - 2) {
                // already one step away from the top
                sum_cost[i] = cost[i];
            } else {
                // choose the smaller one from taking one stop and taking two steps
                sum_cost[i] = min(cost[i] + sum_cost[i + 1], cost[i] + sum_cost[i + 2]);
            }
        }
        // can choose to start from the 0th or 1st step
        return min(sum_cost[0], sum_cost[1]);
    }
};