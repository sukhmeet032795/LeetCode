class Solution {
public:
    
    struct customSort{
        bool operator()(pair<int, int>& trip1, pair<int, int>& trip2) {
            return trip1.first > trip2.first;
        }
    };
    
    struct customSort1{
        bool operator()(vector<int>& trip1, vector<int>& trip2) {
            return trip1[1] < trip2[1];
            if(trip1[1] == trip2[1])
                return trip1[2] < trip2[2];
        }
    };
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        sort(trips.begin(), trips.end(), customSort1());
        priority_queue<pair<int, int>, vector<pair<int, int>>, customSort> q;
            
        for(int i = 0; i < trips.size(); i++) {
            
            if(q.empty()) {
                if (capacity < trips[i][0])
                    return false;
                capacity -= trips[i][0];
                q.push(make_pair(trips[i][2], trips[i][0]));
            }
            else {
                while (!q.empty() && q.top().first <= trips[i][1]) {
                    capacity += q.top().second;
                    q.pop();
                }
                if (capacity < trips[i][0])
                    return false;
                capacity -= trips[i][0];
                q.push(make_pair(trips[i][2], trips[i][0]));
            }
        }
        return true;
    }
};