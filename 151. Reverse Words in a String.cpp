//Link - https://leetcode.com/problems/reverse-words-in-a-string/description/

class Solution {
public:
    void reverse(string& s, int i, int j){
        while(i<=j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }

    string reverseWords(string s) {
        int i=0; 
        int j=0, l=0;
        int wordcount = 0;
        int n = s.size();
        while(true){
            while(i<n and s[i] == ' ') i++;
            if(i == n) break;
            if(wordcount) s[j++] = ' ';
            l = j;
            while(i<n and s[i] != ' '){
                s[j++] = s[i++];
            }
            reverse(s,l,j-1); //word ends at j-1 and starts at l
            wordcount++;
        }
        s.resize(j);
        reverse(s,0,j-1);
        return s;
    }
};
