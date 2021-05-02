class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int len = stations.size();
        int curr = startFuel, i = 0, steps = 0;
        
        sort(stations.begin(), stations.end());
        priority_queue<int> p;
        
        while(curr < target)
        {
            steps++;
            while(i < len && stations[i][0] <= curr)
            {
                p.push(stations[i][1]);
                i++;
            }
            
            if(p.empty())
                break;
            
            curr += p.top();
            p.pop();
        }
        
        return ((curr >= target) ? steps : -1);
    }
};