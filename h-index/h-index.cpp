class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        priority_queue<int> p;
        for(int i = 0; i < citations.size(); i++)
        {
            p.push(citations[i]);
        }
        
        int ind = 1, Max = 0, len = citations.size();
        while(!p.empty())
        {
            int tmp = p.top();
            if(p.top() >= ind)
                Max = max(Max, ind);
            ind++;
            p.pop();
        }
        
        return Max;
    }
};