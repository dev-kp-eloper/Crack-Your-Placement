//Link - https://leetcode.com/problems/max-consecutive-ones/description/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        int j = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 1){
                maxi = max(maxi, (i-j+1));
            }
            else j = i+1;
        }

        return maxi;
    }
};
