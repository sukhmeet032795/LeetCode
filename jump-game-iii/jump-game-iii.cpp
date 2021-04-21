class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        int len = arr.size();
        vector<bool> visited(len, false);
        stack<int> s;
        
        if(arr[start] == 0)
            return true;
        
        visited[start] = true;
        s.push(start);
        
        while(!s.empty())
        {
            int tmp = s.top();
            s.pop();
            
            if(arr[tmp] == 0)
                return true;
            
            if(tmp - arr[tmp] >= 0 && visited[tmp - arr[tmp]] != true)
            {
                visited[tmp -arr[tmp]] = true;
                s.push(tmp - arr[tmp]);
            }
            
            if(tmp + arr[tmp] < len && visited[tmp + arr[tmp]] != true)
            {
                visited[tmp + arr[tmp]] = true;
                s.push(tmp + arr[tmp]);
            }
        }
        
        return false;
    }
};