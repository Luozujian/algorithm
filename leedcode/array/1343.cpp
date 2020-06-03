#include <bits/stdc++.h>

using namespace std;


int numOfSubarrays(vector<int> &arr, int k, int threshold) {
    double sum = 0.0;
    int number = 0;
    for (int i = 0; i < arr.size(); i++) {
        if(i + 1 < k){
            sum += arr[i];
            continue;
        }
        sum += arr[i];
        if(sum/k >= threshold) number ++;
        sum -= arr[i-k+1];
    }
    return number;
}

int main() {
    vector<int> arr{4,4,4,4};
    numOfSubarrays(arr,4,1);
    return 0;
}
