//Link - https://leetcode.com/problems/basic-calculator-ii/description/

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        int currnumber = 0;
        int lastnumber = 0;
        int ans = 0;
        char operation = '+';
        for(int i=0; i<n; i++){
            char currchar = s[i];
            if(isdigit(currchar)){
                currnumber = (currnumber * 10) + (currchar - '0');
            }
            if(!isdigit(currchar) and !iswspace(currchar) or (i == n-1)){
                if(operation == '+'){
                    ans += lastnumber;
                    lastnumber = currnumber;
                } 
                else if(operation == '-'){
                    ans += lastnumber;
                    lastnumber = -currnumber;
                }
                else if(operation == '*'){
                    lastnumber *= currnumber;
                }
                else if(operation == '/'){
                    lastnumber /= currnumber;
                }
                operation = currchar;
                currnumber = 0;
            }
        }
        ans += lastnumber;
        return ans;
    }
};
