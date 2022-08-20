class Solution {
public:
    
    vector<string> combinations;
    void generateCombinations(int index, const string& digits, string &curr, unordered_map<char, string>& um) {
        
        if (index == digits.size()) { combinations.emplace_back(curr); return; }
        
        for(auto itr : um[digits[index]]) {
            curr.push_back(itr);
            generateCombinations(index + 1, digits, curr, um);
            curr.pop_back();
        };
    };
    
    vector<string> letterCombinations(string digits) {
        
        if (digits.empty())
            return {};
        
        string curr = "";
        combinations.clear();
        unordered_map<char, string> um = { {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
                                           {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} };
        
        generateCombinations(0, digits, curr, um);
        return combinations;
    }
};