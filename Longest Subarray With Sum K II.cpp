//Link - https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_5713505?leftPanelTab=0

#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& nums, int k){
    // Write your code here
    int n = nums.size();
    map<long long, int> mp;
    long long sum = 0;
    int maxi = 0;
    for(int i=0; i<n; i++){
        sum += nums[i];
        if(sum == k){
            maxi = max(maxi, i+1);
        }
        int rem = sum - k;
        if(mp.count(rem)){
            int len = i - mp[rem];
            maxi = max(maxi, len);
        }

        if(!mp.count(sum)) mp[sum] = i;
    }

    return maxi;
}
