class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        
        int len = items.size();
        map<int, priority_queue<int, vector<int>, greater<int>>> m;
        sort(items.begin(), items.end());
        
        for(int i = 0; i < len; i++)
        {
            if(m[items[i][0]].size() < 5)
                m[items[i][0]].push(items[i][1]);
            else
            {
                if(m[items[i][0]].top() < items[i][1])
                {
                    m[items[i][0]].pop();
                    m[items[i][0]].push(items[i][1]);
                }
            }
        }
        
        vector<vector<int>> out;
        for(auto itr : m)
        {
            int sum = 0;
            int size = itr.second.size();
            while(!itr.second.empty())
            {
                sum += itr.second.top();
                itr.second.pop();
            }
            
            out.push_back({itr.first, (sum / size)});
        }
        
        return out;
    }
};