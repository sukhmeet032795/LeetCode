class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> p;
        for(auto stone : stones)
            p.push(stone);
        
        while(!p.empty()) {
            
            if (p.size() == 1)
                break;
            
            int stone1 = p.top();
            p.pop();
            int stone2 = p.top();
            p.pop();
            
            if ((stone1 - stone2) != 0)
                p.push((stone1 - stone2));
        };
        
        if (p.empty())
            return 0;
        
        return p.top();
    }
};