//Link - https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        int j = 0;
        int i = 0;
        while(i<needle.size() and j<haystack.size()){
            if(haystack[j] == needle[i]){
                i++;
                j++;
                if(i == needle.size()){
                    return j - needle.size();
                }
            }
            else{
                j = j - i + 1;
                i = 0;
            }
        }
        return -1;
    }
};
