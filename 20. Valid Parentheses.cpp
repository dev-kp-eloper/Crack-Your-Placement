//Link - https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char> temp;

        for(int i=0; i<s.length(); i++){
            if(s[i] == '(' or s[i] == '{' or s[i] == '['){
                temp.push(s[i]);
            }
            else if(s[i] == ')'){
                if(temp.empty() or temp.top() != '('){
                    return false;
                }
                temp.pop();
            }
            else if(s[i] == '}'){
                if(temp.empty() or temp.top() != '{'){
                    return false;
                }
                temp.pop();
            }
            else if(s[i] == ']'){
                if(temp.empty() or temp.top() != '['){
                    return false;
                }
                temp.pop();
            }
        }
        return temp.empty();
    }
};
