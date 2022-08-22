class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);

        for(auto itr : prerequisites) {
            graph[itr[1]].emplace_back(itr[0]);
            inDegree[itr[0]]++;
        };
        
        queue<int> q;
        for(int itr = 0; itr < inDegree.size(); itr++) {
            if (inDegree[itr] == 0) {
                q.push(itr);
            };
        };
        
        vector<int> output;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            output.emplace_back(curr);
            for(auto itr1 : graph[curr]) {
                inDegree[itr1]--;
                if (inDegree[itr1] == 0)
                    q.push(itr1);
            };
        };
        
        return (output.size() == numCourses);
    }
};