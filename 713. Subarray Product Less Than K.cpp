//Link - https://leetcode.com/problems/subarray-product-less-than-k/description/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if(k <= 1) return 0;
        int i=0;
        int cnt = 0;
        int preproduct = 1;
        for(int j=0; j<n; j++){
            preproduct = preproduct * nums[j];
            while(preproduct >= k){
                preproduct = preproduct / nums[i];
                i++;
            }
            cnt += j - i + 1;
        }
        return cnt;
    }
};
