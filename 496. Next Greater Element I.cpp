//Link - https://leetcode.com/problems/next-greater-element-i/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int , int> mp;

        for(int i=0; i<nums2.size(); i++){
            int curr = nums2[i];
            while(stk.size() > 0 and stk.top() < curr){
                mp[stk.top()] = curr;
                stk.pop();
            }
            stk.push(curr);
        }

        vector<int> ans(nums1.size(), -1);
        for(int i=0; i<nums1.size(); i++){
            int curr = nums1[i];
            if(mp.count(curr)){
                ans[i] = mp[curr];
            }
        }
        return ans;
    }
};
