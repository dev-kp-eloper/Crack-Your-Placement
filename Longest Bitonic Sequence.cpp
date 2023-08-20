//Link - https://www.codingninjas.com/studio/problems/longest-bitonic-sequence_1062688?leftPanelTab=0

#include<bits/stdc++.h>

int longestBitonicSubsequence(vector<int>& arr, int n)
{
        vector<int> dp1(n,1);
        for(int i=0; i<=n-1; i++){
            for(int prev_index = 0; prev_index <=i-1; prev_index++){
                if(arr[prev_index] < arr[i] and 1 + dp1[prev_index] > dp1[i]){
                    dp1[i] = 1 + dp1[prev_index];
                }
            }
        }

		vector<int> dp2(n,1);
        for(int i=n-1; i>=0; i--){
            for(int prev_index = n-1; prev_index > i; prev_index--){
                if(arr[prev_index] < arr[i] && 1 + dp2[prev_index] > dp2[i]){
                    dp2[i] = 1 + dp2[prev_index];
                }
            }
        }

		int maxi = 0;
		for(int i=0; i<n; i++){
			maxi = max(maxi, dp1[i] + dp2[i] - 1);
		}

		return maxi;
}
