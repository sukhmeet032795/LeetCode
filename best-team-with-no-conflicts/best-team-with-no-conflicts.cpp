class Solution {
public:
    struct node{
        int age;
        int score;
        node(int a, int s) : age(a), score(s) {};
    };
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
        vector<node> nodes;
        for(int i = 0; i < scores.size(); i++)
            nodes.push_back(node(ages[i], scores[i]));
        
        sort(nodes.begin(), nodes.end(), [](const node &n1, const node &n2){ if(n1.age == n2.age) {return n1.score < n2.score;} return (n1.age < n2.age); });
        
        // for(int i = 0; i < ages.size(); i++)
        // {
        //     cout<<nodes[i].age<<" "<<nodes[i].score<<endl;
        // }
        
        vector<node> dp(ages.size(), {0,0});
        int Max = 0;
        
        for(int i = 0; i < ages.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nodes[j].age <= nodes[j].age && nodes[j].score <= nodes[i].score && dp[j].score > dp[i].score)
                {
                    dp[i].score = dp[j].score;
                }
            }
            dp[i].age = nodes[i].age;
            dp[i].score += nodes[i].score;
            Max = max(Max, dp[i].score);
        }
        
        return Max;
    }
};