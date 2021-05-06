class Solution {
public:
    bool judgeCircle(string moves) {
        
        int len = moves.length();
        int x = 0, y = 0, itr = 0;
        
        while(itr != len)
        {
            switch(moves[itr])
            {
                case 'U':
                    {
                        y += 1;
                    }
                    break;
                case 'D':
                    {
                        y -= 1;
                    }
                    break;
                case 'L':
                    {
                        x -= 1;
                    }
                    break;
                case 'R':
                    {
                        x += 1;
                    }
                    break;
            };
            itr++;
        };
        
        return ((x == 0 && y == 0) ? true : false);
    }
};