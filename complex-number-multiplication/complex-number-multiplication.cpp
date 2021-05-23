class Solution {
public:
    
    void getNumbers(int &num1, int &num2, string &num1Str)
    {
        size_t index = num1Str.find("+");
        num1 = stoi(num1Str.substr(0, index));
        string tmp = num1Str.substr(index+1);
        tmp.erase(tmp.end() - 1);
        num2 = stoi(tmp);
        // cout<<num1<<" "<<num2<<endl;
    };
    
    string complexNumberMultiply(string num1Str, string num2Str) {
        
        int a, b, c, d;
        getNumbers(a, b, num1Str);
        getNumbers(c, d, num2Str);
        
        int num1 = ((a*c) - (b*d)), num2 = ((a*d) + (b*c));
        string out = "";
        out += to_string(num1);
        out += "+";
        out += to_string(num2);
        out += "i";
        return out;
    }
};