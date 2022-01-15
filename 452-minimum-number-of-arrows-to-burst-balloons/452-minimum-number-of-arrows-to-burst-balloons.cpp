class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(), points.end());
        stack<int> s;
        int arrows = 0;
        
        for(int i = 0; i < points.size(); i++) {
            if(s.empty()) {
                s.push(points[i][1]);
                arrows++;
            }
            else{
                if (s.top() >= points[i][0]) {
                    int ele = s.top();
                    s.pop();
                    s.push(min(ele, points[i][1]));
                }
                else {
                    arrows++;
                    s.push(points[i][1]);
                }
            }
        }
        
        return arrows;
    }
};