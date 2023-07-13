//Link - https://leetcode.com/problems/koko-eating-bananas/description/

class Solution {
public:
    long long calhours(vector<int>&piles, int mid)
    {
        long long hours = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            int hoursToEatPile = ceil(piles[i] / (double)mid);
            hours += hoursToEatPile;
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int start = 1;
        int end = piles[n-1];
        int ans = -1;

        while(start <= end){
            int mid = start + (end - start)/2;
            long long hours = calhours(piles,mid);
            if(hours <= h){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
    }
};
