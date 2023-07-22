//Link - https://leetcode.com/problems/reverse-pairs/description/

class Solution {
public:
    void merge(int start, int end, int mid, vector<int>& nums, int& cnt){
        vector<int> ans;
        int left = start;
        int right = mid+1;
        int it = mid+1;
        for(int i=start; i<=mid; i++){
            while(it <= end and nums[i] > 2 * (long long)nums[it]){
                it++;
            }
            cnt += it - (mid + 1);
        }

        while(left <= mid and right <= end){
            if(nums[left] <= nums[right]){
                ans.push_back(nums[left]);
                left++;
            }
            else{
                ans.push_back(nums[right]);
                right++;
            }
        }
        while(left <= mid){
            ans.push_back(nums[left]);
            left++;
        }
        while(right <= end){
            ans.push_back(nums[right]);
            right++;
        }
        for(int i=start; i<=end; i++){
            nums[i] = ans[i-start];
        }
    }  

    void divide(int start, int end, vector<int>& nums, int& cnt){
        if(start >= end) return;
        int mid = (start + end)/2;
        divide(start,mid,nums,cnt);
        divide(mid+1,end,nums,cnt);
        merge(start,end,mid,nums,cnt);
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        divide(0,n-1,nums,cnt);
        return cnt;
    }
};
