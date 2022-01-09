class Solution {
public:
    
    void move(int &x, int &y, int& d) {
        
        switch(d) {
            case 0:
                y += 1;
                break;
            case 2:
                y -= 1;
                break;
            case 3:
                x += 1;
                break;
            case 1:
                x -= 1;
                break;
            default:
                break;
        }
    };
    
    bool isRobotBounded(string instructions) {
        
        int x = 0, y = 0;
        int d = 0;
        
        for(int i = 0; i < instructions.size(); i++) {
            
            if(instructions[i] == 'G')
                move(x, y, d);
            else if(instructions[i] == 'L')
            {
                d++;
                if(d == 4)
                    d = 0;
            }
            else
            {
                d--;
                if(d == -1)
                    d = 3;
            }
        }
        
        if(d != 0 || (x == 0 && y == 0))
            return true;
        
        return false;
    }
};