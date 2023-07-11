//Link - https://leetcode.com/problems/find-the-duplicate-number/submissions/988413756/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //floys tortoise and hare algo
        int fast = nums[0];
        int slow = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while(slow != fast);

        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
