//Link - https://leetcode.com/problems/majority-element/description/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int element; 
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(cnt == 0){
                element = nums[i];
                cnt++;
            }
            else if(nums[i] == element){
                cnt++;
            }
            else 
                cnt--;
        }
        return element;
    }
};
