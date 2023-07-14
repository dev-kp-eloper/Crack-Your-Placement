//Link - https://www.codingninjas.com/studio/problems/merge-sort_5846

void merge(vector<int>& arr, int l, int r, int mid){
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
}

void mergeSort(vector<int>& arr, int l, int r) {
    if(l == r){
        return;
    }
    int mid = (l + r)/2;

    mergeSort(arr, l, mid);    
    mergeSort(arr, mid+1, r);
    merge(arr,l,r,mid);

}
