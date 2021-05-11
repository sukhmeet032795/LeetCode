class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> s;
        int len = asteroids.size();
        
        s.push(asteroids[0]);
        for(int i = 1; i < len;)
        {
            if(!s.empty())
            {
                int tmp = s.top();
                if(tmp > 0 && asteroids[i] > 0){
                    s.push(asteroids[i]);
                    i++;
                    continue;
                }

                if(tmp < 0 && asteroids[i] < 0){
                    s.push(asteroids[i]);
                    i++;
                    continue;
                }

                if(tmp > 0 && asteroids[i] < 0)
                {
                    int num1 = abs(asteroids[i]);
                    if(num1 >= tmp)
                    {
                        s.pop();
                        if(num1 == tmp) { i++; }
                        continue;
                    }
                    i++;
                    continue;
                }

                if(tmp < 0 && asteroids[i] > 0){
                    s.push(asteroids[i]);
                    i++;
                    continue;
                }
            }
            else
                s.push(asteroids[i++]);
        }
        
        asteroids.clear();
        while(!s.empty())
        {
            asteroids.insert(asteroids.begin(), s.top());
            s.pop();
        }
        
        return asteroids;
    }
};