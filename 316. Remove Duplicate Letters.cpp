//Link - https://leetcode.com/problems/remove-duplicate-letters/description/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last_idx(26,0);

        for(int i=0; i<s.size(); i++){
            last_idx[s[i] - 'a'] = i;
        }

        vector<bool> flag(26, false);
        stack<int> st;

        for(int i=0; i<s.size(); i++){
            int curr = s[i] - 'a';
            if(flag[curr]) continue;
            while(!st.empty() and st.top() > s[i] and i < last_idx[st.top() - 'a']){
                flag[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            flag[curr] = true;
        }

        string str = "";
        while(!st.empty()){
            char c = st.top();
            str = c + str;
            st.pop();
        }

        return str;
    }
};
