//Link - https://www.codingninjas.com/studio/problems/number-of-inversions_6840276?leftPanelTab=0

int merge(vector<int>& arr, int l, int r, int mid){
    int cnt = 0;
    vector<int> ans;
    int left = l;
    int right = mid + 1;
    while(left <= mid and right <= r){
        if(arr[left] <= arr[right]){
            ans.push_back(arr[left]);
            left++;
        }
        else{
            ans.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }
    while(left <= mid){
        ans.push_back(arr[left]);
        left++;
    }
    while(right <= r){
        ans.push_back(arr[right]);
        right++;
    }
    for(int i=l; i<=r; i++){
        arr[i] = ans[i-l];
    }
    return cnt;
}

int mergeSort(vector<int>& arr, int l, int r) {
    int cnt = 0;
    if(l == r){
        return cnt;
    }
    int mid = (l + r)/2;

    cnt += mergeSort(arr, l, mid);    
    cnt += mergeSort(arr, mid+1, r);
    cnt += merge(arr,l,r,mid);
    return cnt;

}

int numberOfInversions(vector<int>&a, int n) {
    // Write your code here.
    return mergeSort(a, 0, n-1);
    
}
