class Solution {
public:
    
    void makeMove(int &x, int &y, int direction)
    {
        switch(direction)
        {
            case 1:
                {
                    y += 1;
                }
                break;
            case 2:
                {
                    x += 1;
                }
                break;
            case 3:
                {
                    y -= 1;
                }
                break;
            case 4:
                {
                    x -= 1;
                }
                break;
        }
    };
    
    bool isRobotBounded(string instructions) {
        
        int direction = 1, len = instructions.length(), x = 0, y = 0;
        for(int i = 0; i < len; i++)
        {
            if(instructions[i] == 'L')
            {
                direction -= 1;
                if(direction == 0)
                    direction = 4;
            }
            else if(instructions[i] == 'R')
            {
                direction += 1;
                if(direction == 5)
                    direction = 1;
            }
            else
            {
                makeMove(x, y, direction);
            }
        }
        
        if((x == 0 && y == 0) || direction != 1)
            return true;
        return false;
    }
};