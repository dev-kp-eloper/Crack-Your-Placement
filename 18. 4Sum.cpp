//Link - https://leetcode.com/problems/4sum/description/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        long long int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(long long int i=0; i<n-3; i++){
            if(i>0 and nums[i] == nums[i-1]){
                continue;
            }
            long long int sum3 = target - nums[i];
            for(long long int j=i+1; j<n-2; j++){
                if(j>i+1 and nums[j] == nums[j-1]){
                    continue;
                }
                long long int sum2 = sum3 - nums[j];
                long long int start = j+1;
                long long int end = n-1;
                while(start < end){
                    long long int sum = nums[start] + nums[end];
                    if(sum == sum2){
                        ans.push_back({nums[i], nums[j], nums[start], nums[end]});

                        while(start < end and nums[start] == nums[start+1]){
                            start++;
                        }
                        while(start < end and nums[end] == nums[end-1]){
                            end--;
                        }
                        start++;
                        end--;
                    }
                    else if(sum < sum2){
                        start++;
                    }
                    else{
                        end--;
                    }
                }
            }
        }
        return ans;
    }
};
