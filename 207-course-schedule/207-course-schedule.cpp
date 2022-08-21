class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        
        for(auto itr : prerequisites) {
            graph[itr[0]].emplace_back(itr[1]);
            inDegree[itr[1]]++;
        };
        
        vector<int> ans;
        queue<int> nodes;
        for(int itr = 0; itr < inDegree.size(); itr++) {
            if (inDegree[itr] == 0) { 
                nodes.push(itr);
            };
        };
        
        if (nodes.size() == 0) { return false; }
        
        while(!nodes.empty()) {
            
            int curr = nodes.front();
            nodes.pop();
            ans.emplace_back(curr);
            for(int i = 0; i < graph[curr].size(); i++) {
                inDegree[graph[curr][i]]--;
                if (inDegree[graph[curr][i]] == 0) {
                    nodes.push(graph[curr][i]);
                };
            };
        };
        
        return (ans.size() == numCourses);
    }
};