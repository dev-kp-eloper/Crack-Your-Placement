//Link - https://leetcode.com/problems/champagne-tower/description/

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> prev(1,poured);
        
        for(int row=0; row<query_row; row++){
            vector<double> curr(row+2, 0.0);
            for(int i=0; i<prev.size(); i++){
                double extra = prev[i] - 1;
                if(extra > 0.0){
                    curr[i] += 0.5 * extra;
                    curr[i+1] += 0.5 * extra;
                }
            }
            prev = curr;
        }
        return min(1.0, prev[query_glass]);
    }
};
