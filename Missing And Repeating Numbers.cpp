//Link - https://www.codingninjas.com/studio/problems/missing-and-repeating-numbers_6828164?leftPanelTab=0

#include <unordered_map>

vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // Write your code here
    int n = a.size();
    int xr = 0;
    for(int i=0; i<n; i++){
        xr = xr ^ a[i] ^ i+1;
    }
    int bitno = 0;
    while(1){
        if((xr & 1<<bitno) != 0){
            break;
        }
        bitno++;
    }

    int zero = 0;
    int one = 0;

    for(int i=0; i<n; i++){
        if((a[i] & 1<<bitno) == 0){
            zero = zero ^ a[i];
        }
        else{
            one = one ^ a[i];
        }
    }

    for(int i=1; i<n+1; i++){
        if((i & 1<<bitno) == 0){
            zero = zero ^ i;
        }
        else{
            one = one ^ i;
        }
    }

    int cnt = 0;
    for(int i=0; i<n; i++){
        if(a[i] == zero) cnt++;
    }
    if (cnt == 2) return {zero, one};
    return {one, zero};

}

