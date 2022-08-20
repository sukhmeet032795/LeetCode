class Solution {
public:
    
    vector<string> parenthesis;
    
    void generateParen(int sBraces, int eBraces, string curr) {
        
        if (sBraces == 0 && eBraces == 0) {
            parenthesis.emplace_back(curr);
            return;
        };
        
        if (sBraces > 0) generateParen(sBraces - 1, eBraces, curr + '(');
        if (eBraces > sBraces) {
            generateParen(sBraces, eBraces - 1, curr + ')');
        };
    };
    
    vector<string> generateParenthesis(int n) {
        
        parenthesis.clear();
        if (n == 0) { return parenthesis; }
        generateParen(n, n, "");
        return parenthesis;
    }
};