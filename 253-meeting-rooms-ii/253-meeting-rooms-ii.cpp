class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> p;
        int rooms = 0;
        
        for(int i = 0; i < intervals.size(); i++) {
            if(p.empty()) {
                rooms++;
                p.push(intervals[i][1]);
            }
            else {
                if(!p.empty() && p.top() <= intervals[i][0]) {
                    p.pop();
                    p.push(intervals[i][1]);
                } else {
                    rooms++;
                    p.push(intervals[i][1]);
                }
            }
        }
        
        return rooms;
    }
};