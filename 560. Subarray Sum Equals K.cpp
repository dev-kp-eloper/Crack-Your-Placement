//Link - https://leetcode.com/problems/subarray-sum-equals-k/description/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int prefix[n];
        prefix[0] = nums[0];
        for(int i = 1; i<n; i++){
            prefix[i] = nums[i] + prefix[i-1];
        }
        unordered_map<int,int> mp;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(prefix[i] == k) cnt++;

            if(mp.count(prefix[i] - k)){
                cnt += mp[prefix[i] - k];
            }

            mp[prefix[i]]++;
        }
        return cnt;
    }
};
