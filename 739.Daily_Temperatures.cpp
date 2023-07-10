//Link - https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        int n = temperatures.size();
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            int curr = temperatures[i];
            while(!stk.empty() and temperatures[stk.top()] < curr){
                ans[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.empty()){
            ans[stk.top()] = 0;
            stk.pop();
        }
        return ans;
    }
};
