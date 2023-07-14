//Link - https://www.codingninjas.com/studio/problems/subset-sum_3843086?leftPanelTab=0

void bigsum(vector<int>& num, vector<int>& ans,
 int sum, int idx, int n){
	if(idx == n){
		ans.push_back(sum);
		return;
	}

	bigsum(num,ans,sum+num[idx],idx+1,n);
	bigsum(num,ans,sum,idx+1,n);
}

vector<int> subsetSum(vector<int> &num){
	// Write your code here.
	int n = num.size();
	vector<int> ans;
	bigsum(num,ans,0,0,n);
	sort(ans.begin(),ans.end());
	return ans;
}
