//Link - https://www.codingninjas.com/studio/problems/0-1-knapsack_920542?source=youtube&campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h> 

// int f(int idx, int W, vector<int>& weight, vector<int>& value, vector<vector<int>>& dp){
// 		if(idx == 0){
// 			if(weight[0] <= W) return value[0];
// 			return 0;
// 		}
// 		if(dp[idx][W] != -1) return dp[idx][W];

// 		int nottake = 0 + f(idx-1, W, weight, value, dp);
// 		int take = INT_MIN;
// 		if(weight[idx] <= W) take = value[idx] + f(idx-1, W-weight[idx], weight, value);

// 		return dp[idx][W] = max(take, nottake);
// }

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<int> prev(maxWeight+1, 0);


	for(int i=weight[0]; i<=maxWeight; i++) prev[i] = value[0];

	for(int idx=1; idx<n; idx++){
		for(int W=maxWeight; W>=0; W--){
			int nottake = 0 + prev[W];
			int take = INT_MIN;
			if(weight[idx] <= W) take = value[idx] + prev[W-weight[idx]];
			prev[W] = max(take, nottake);
		}
	}

	return prev[maxWeight];
}
