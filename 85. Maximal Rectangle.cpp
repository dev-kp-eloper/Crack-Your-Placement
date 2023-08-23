//Link - https://leetcode.com/problems/maximal-rectangle/description/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        int maxA = 0;
        for(int i=0; i<=n; i++){
            while(!s.empty() and (i==n or heights[s.top()] >= heights[i])){
                int h = heights[s.top()];
                s.pop();
                int width;
                if(s.empty()) width = i;
                else width = i - s.top() - 1;
                maxA = max(maxA, width * h);
            }
            s.push(i);
        }
        return maxA;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxArea = 0;
        vector<int> height(n , 0);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }

            int area = largestRectangleArea(height);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};
