//Link - https://www.codingninjas.com/studio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&leftPanelTab=0

int mod = int(1e9 + 7);

// int f(int idx, int k, vector<int>& arr, vector<vector<int>>& dp){
// 	if(k == 0) return 1;
// 	if(idx == 0) return arr[0] == k;

// 	if(dp[idx][k] != -1) return dp[idx][k];
	
// 	int nottake = f(idx - 1, k, arr, dp) % mod;
// 	int take = 0;
// 	if(arr[idx] <= k) take = f(idx - 1, k - arr[idx], arr, dp) % mod;

// 	return dp[idx][k] = take + nottake;
// }

// int findWays(vector<int>& arr, int k)
// {
// 	// Write your code here.
// 	int n = arr.size();
// 	vector<vector<int>> dp(n, vector<int>(k+1, 0));

// 	for(int i=0; i<n; i++) dp[i][0] = 1;
// 	if(arr[0] <= k) dp[0][arr[0]] = 1;

// 	for(int idx=1; idx<n; idx++){
// 		for(int tar=1; tar<=k; tar++){
// 			int nottake = dp[idx - 1][tar] % mod;
// 			int take = 0;
// 			if(arr[idx] <= tar) take = dp[idx - 1][tar - arr[idx]] % mod;
// 			dp[idx][tar] = take + nottake;
// 		}
// 	}

// 	return dp[n-1][k] % mod;
// }

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n = arr.size();
	vector<int> prev(k+1, 0);
	vector<int> curr(k+1, 0);


	prev[0] = curr[0] = 1;
	if(arr[0] <= k) prev[arr[0]] = 1;

	for(int idx=1; idx<n; idx++){
		for(int tar=1; tar<=k; tar++){
			int nottake = prev[tar] % mod;
			int take = 0;
			if(arr[idx] <= tar) take = prev[tar - arr[idx]] % mod;
			curr[tar] = take + nottake;
		}
		prev = curr;
	}

	return prev[k] % mod;
}
