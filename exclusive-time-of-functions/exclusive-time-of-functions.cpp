class Solution {
public:
    
    typedef enum{
        none = -1,
        start,
        end
    }state;
    
    struct node{
        int id;
        int time;
        state st;
        node(int i, int t, state s) : id(i), time(t), st(s) {};
    };
    
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        
        int len = logs.size();
        vector<node> nodes;
        vector<int> out(n, 0);
        
        for(int i = 0; i < len; i++)
        {
            size_t ind = logs[i].find(":");
            size_t ind1 = logs[i].find_last_of(":");
            
            node n(-1, -1, none);
            n.id = stoi(logs[i].substr(0, ind));
            n.st = (("start" == logs[i].substr(ind+1, ind1 - ind - 1)) ? start : end);
            n.time = stoi(logs[i].substr(ind1+1));
            
            // cout<<n.id<<" "<<n.st<<" "<<n.time<<endl;
            
            nodes.push_back(n);
        }
        logs.clear();
        
        stack<node> s;
        int elapsedTime = 0;
        for(int i = 0; i < len; i++)
        {
            if(nodes[i].st == start)
            {
                if(!s.empty())
                    out[s.top().id] += (nodes[i].time - elapsedTime);
                s.push(nodes[i]);
                elapsedTime = nodes[i].time;
            }
            else
            {
                if(!s.empty())
                {
                    node tmp = s.top();
                    s.pop();
                    out[tmp.id] += (nodes[i].time - elapsedTime + 1);
                    elapsedTime = (nodes[i].time + 1);
                }
                else
                {
                    out[nodes[i].id] += 1;
                    elapsedTime += 1;
                }
            }
        }
        
        return out;
    }
};
