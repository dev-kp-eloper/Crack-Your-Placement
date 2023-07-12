//Link - https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        vector<int> count(k, 0);
        int sum = 0;
        count[0] = 1;

        for(int i=0; i<n; i++){
            sum = (sum + nums[i]) % k;
            if(sum < 0){
                sum += k;
            }
            ans += count[sum];
            count[sum]++;
        }

        return ans;
    }
};
