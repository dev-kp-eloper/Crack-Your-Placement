//Link - https://www.codingninjas.com/studio/problems/partitions-with-given-difference_3751628?source=youtube&campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h> 
int mod = int(1e9+7);

int findWays(vector<int> &num, int tar){
     int n = num.size();

    vector<int> prev(tar+1,0);
    
    if(num[0] == 0) prev[0] =2;  // 2 cases -pick and not pick
    else prev[0] = 1;  // 1 case - not pick
    
    if(num[0]!=0 && num[0]<=tar) prev[num[0]] = 1;  // 1 case -pick
    
    for(int ind = 1; ind<n; ind++){
        vector<int> cur(tar+1,0);
        for(int target= 0; target<=tar; target++){
            int notTaken = prev[target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = prev[target-num[ind]];
        
            cur[target]= (notTaken + taken)%mod;
        }
        prev = cur;
    }
    return prev[tar];
}

// int findWays(vector<int>& arr, int k)
// {
// 	// Write your code here.
// 	int n = arr.size();
// 	vector<vector<int>> dp(n, vector<int>(k+1, 0));

// 	if(arr[0] == 0) dp[0][0] = 2;
// 	else dp[0][0] = 1;

// 	if(arr[0] != 0 and arr[0] <= k) dp[0][arr[0]] = 1;

// 	for(int idx=1; idx<n; idx++){
// 		for(int tar=0; tar<=k; tar++){
// 			int nottake = dp[idx - 1][tar];
// 			int take = 0;
// 			if(arr[idx] <= tar) take = dp[idx - 1][tar - arr[idx]];
// 			dp[idx][tar] = (take + nottake) % mod;
// 		}
// 	}

// 	return dp[n-1][k];
// }

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int totalsum = 0;
    for(int i=0; i<n; i++) totalsum += arr[i];

    if(((totalsum - d) < 0) or ((totalsum - d) % 2)) return 0;
    return findWays(arr, (totalsum - d)/2);
}


