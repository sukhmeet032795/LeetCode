class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> al(n);
        for(const auto& e: edges)
            al[e[0]].emplace_back(e[1]);
        vector<int> visited(n, -1);
        return dfs(al, source, destination, visited);
    }
    
private:
    bool dfs(const vector<vector<int>>& al, const int cur, const int dest, vector<int>& visited) {
        cout << " cur:" << cur << endl;
        if(al[cur].empty()) return cur == dest;
        if(visited[cur] != -1) return visited[cur]; //  visited[cur] can be 0 or 1, indicating visiting again or reaching end. ??
        //if(visited[cur] == 0) return visited[cur]; //  ok
        visited[cur] = 0; // false, visiting
        for(const auto& next: al[cur])
            if(!dfs(al, next, dest, visited)) return false; // all paths starting from source end at destination eventually?
        
        return visited[cur] = true;
    }
};