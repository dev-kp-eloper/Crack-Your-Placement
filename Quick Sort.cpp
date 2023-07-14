//Link - https://www.codingninjas.com/studio/problems/quick-sort_5844?leftPanelTab=1

int partitionArray(int input[], int start, int end) {
	int pivot = input[start];
	int low = start;
	int high = end;
	while(low < high){
		while(input[low] <= pivot and low <= end - 1){
			low++;
		}
		while(input[high] > pivot and high >= start + 1){
			high--;
		}
		if(low < high) swap(input[low],input[high]);
	}
	swap(input[start],input[high]);
	return high;
}

void quickSort(int input[], int start, int end) {
	if(start < end){
		int pivot = partitionArray(input,start,end);
		quickSort(input,start,pivot-1);
		quickSort(input,pivot+1,end);
	}
}
