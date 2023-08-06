//Link - https://www.codingninjas.com/studio/problems/rod-cutting-problem_800284?source=youtube&campaign=striver_dp_videos&leftPanelTab=0

int f(int idx, int N, vector<int> &price, vector<vector<int>>& dp){
	if(idx == 0)  return N*price[0];

	if(dp[idx][N] != -1) return dp[idx][N];

	int nottake = 0 + f(idx - 1, N, price, dp);
	int take = -1e9;
	int rod = idx+1;
	if(rod <= N) take = price[idx] + f(idx, N - rod, price, dp);

	return dp[idx][N] = max(take, nottake);
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	int l = price.size();
	vector<int> prev(n+1, 0);

	for(int N=0; N<=n; N++) prev[N] = N * price[0];

	for(int idx=1; idx<l; idx++){
		for(int N=0; N<=n; N++){
			int nottake = 0 + prev[N];
			int take = -1e9;
			int rod = idx+1;
			if(rod <= N) take = price[idx] + prev[N - rod];

			prev[N] = max(take, nottake);
		}
	}

	return prev[n];
}
