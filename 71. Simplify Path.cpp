//Link - https://leetcode.com/problems/simplify-path/description/

class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack<string> s;
        string ans = "";
        for(int i=0; i<n; i++){
            if(path[i] == '/') continue;
            string temp = "";
            while(i<n and path[i] != '/'){
                temp += path[i];
                i++;
            }
            if(temp == ".") continue;
            if(temp == ".."){
                if(!s.empty()){
                    s.pop();
                }
            }
            else{
                s.push(temp);
            }
        }

        while(!s.empty()){
            ans = "/" + s.top() + ans; //This will put all the stack members in a correct way 
            s.pop();
        }

        if(ans.size() == 0) return "/";

        return ans;
    }
};
