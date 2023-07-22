//Link - https://leetcode.com/problems/merge-sorted-array/description/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = n-1;
        int j = m-1;
        int k = (m+n)-1;
        while(i>=0 and j>=0){
            if(nums2[i] > nums1[j]){
                nums1[k] = nums2[i];
                k--;
                i--;
            }
            else{
                nums1[k] = nums1[j];
                j--;
                k--;
            }
        }
        while(i>=0){
            nums1[k--] = nums2[i--];
        }
        
    }
};
