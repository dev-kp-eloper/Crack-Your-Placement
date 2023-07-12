//Link - https://leetcode.com/problems/container-with-most-water/description/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0; 
        int j=n-1;
        int currsum = 0;
        int maxarea = INT_MIN;
        while(i<j){
            if(height[i] <= height[j]){
                currsum = height[i] * (j-i);
                i++;
            }
            else if(height[i] > height[j]){
                currsum = height[j] * (j-i);
                j--; 
            }
                maxarea = max(maxarea, currsum);
        }
        return maxarea;
    }
};
