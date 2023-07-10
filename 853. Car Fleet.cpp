//Link - https://leetcode.com/problems/car-fleet/description/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>> time;
        for(int i=0; i<n; i++){
            double t = (double)(target - position[i])/speed[i];
            time.push_back(make_pair(position[i], t));
        }
        sort(time.begin(),time.end());
        double maxt = 0.0;
        int ans = 0;
        stack<double> s;
        for(int i=n-1; i>=0; i--){
            double temp = time[i].second;
            if(s.empty() or s.top() < temp){
                s.push(temp);
            }
        }
        return s.size();
    }
};
