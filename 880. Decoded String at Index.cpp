//Link - https://leetcode.com/problems/decoded-string-at-index/description/

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long size = 0;

        
        for (char c : s) {
            if (isdigit(c)) {
                size *= (c - '0');
            } else {
                size++;
            }
        }

        
        for (int i = s.length() - 1; i >= 0; i--) {
            k %= size;
            if (k == 0 && isalpha(s[i])) {
                return string(1, s[i]);
            }
            if (isdigit(s[i])) {
                size /= (s[i] - '0');
            } else {
                size--;
            }
        }

        return "";
    }
};
