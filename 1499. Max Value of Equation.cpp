//Link - https://leetcode.com/problems/max-value-of-equation/description/

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        int maxsum = INT_MIN;
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<n; i++){
             while (!pq.empty() && points[i][0] - pq.top().second > k) {
                pq.pop();
            }
            if (!pq.empty()) {
                maxsum = max(maxsum, points[i][0] + points[i][1] + pq.top().first);
            }
            pq.push(make_pair(points[i][1] - points[i][0], points[i][0]));
        }
        return maxsum;

    }
};
