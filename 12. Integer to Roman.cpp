//Link - https://leetcode.com/problems/integer-to-roman/description/

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> symbols = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},        {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
        string ans = "";
        for(int i=0; i<symbols.size(); i++){
            while(num >= symbols[i].first){
                ans += symbols[i].second;
                num -= symbols[i].first;
            }
        }
        return ans;
    }
};
