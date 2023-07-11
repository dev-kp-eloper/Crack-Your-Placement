//Link - https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            s.insert(nums[i]);
        }
        int ns = s.size();
        int i=0;
        for(auto it: s){
            nums[i++] = it;
        }
        return ns;
    }
};
