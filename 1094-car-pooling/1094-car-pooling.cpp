class Solution {
public:
    
    struct customSort{
        bool operator()(vector<int>& vec1, vector<int>& vec2) {
            return vec1[1] < vec2[1];
        };
    };
    
    struct customSort2{
        bool operator()(pair<int, int>& p1, pair<int, int>&p2) {
            return p1.first > p2.first;
        }
    };
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        sort(trips.begin(), trips.end(), customSort());
        priority_queue<pair<int, int>, vector<pair<int, int>>, customSort2> p;
        
        for(int i = 0; i < trips.size(); i++) {
            if(p.empty()) {
                if (capacity < trips[i][0])
                    return false;
                capacity -= trips[i][0];
                p.push(make_pair(trips[i][2], trips[i][0]));
            }
            else {
                while(!p.empty() && p.top().first <= trips[i][1]) {
                    capacity += p.top().second;
                    p.pop();
                }
                
                if (capacity < trips[i][0])
                    return false;
                capacity -= trips[i][0];
                p.push(make_pair(trips[i][2], trips[i][0]));
            }
        }
        
        return true;
    };
};