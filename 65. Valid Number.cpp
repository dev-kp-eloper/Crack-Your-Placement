//Link - https://leetcode.com/problems/valid-number/description/

class Solution {
public:
    bool isNumber(string s) {
        bool digitseen = false, Eseen = false, dotseen = false;
        int countMP = 0;
        int n = s.size();

        for(int i=0; i<n; i++){
            char ch = s[i];

            if(isdigit(ch)){
                digitseen = true;
            }
            else if(ch == '+' or ch == '-'){
                if(countMP == 2){
                    return false;
                }
                if(i>0 and s[i-1] != 'e' and s[i-1] != 'E'){
                    return false;
                }
                if(i == n-1){
                    return false;
                }
                countMP++;
            }
            else if(ch == '.'){
                if(Eseen or dotseen){
                    return false;
                }
                if(i == n-1 and !digitseen){
                    return false;
                }
                dotseen = true;
            }
            else if(ch == 'e' or ch == 'E'){
                if(Eseen or !digitseen or i == n-1){
                    return false;
                }
                Eseen = true;
            }
            else
                return false;
        }
        return true;
    }
};
