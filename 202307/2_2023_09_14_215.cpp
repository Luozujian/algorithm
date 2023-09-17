//
// Created by luozu on 2023/9/14.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <unordered_map>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;

int partition(vector<int> &nums, int l, int r) {
    int index = rand() % (r - l + 1) + l;
    swap(nums[index], nums[r]);
    int i = l - 1;
    for (int j = l; j <= r - 1; ++j) {
        if (nums[j] >= nums[r]) {
            ++i;
            swap(nums[j], nums[i]);
        }
    }
    swap(nums[i + 1], nums[r]);
    return i + 1;
}


int quickSort(vector<int> &nums, int l, int r, int k) {
    int pivot = partition(nums, l, r);
    int newLEnd = pivot - 1, newRStart = pivot + 1;
    while(pivot > k - 1 && nums[newLEnd] == nums[pivot] && newLEnd >= l) {
        if (newLEnd == k - 1) return nums[newLEnd];
        --newLEnd;
    }

    while(pivot < k - 1 && nums[newRStart] == nums[pivot] && newRStart <= r) {
        if (newRStart == k - 1) return nums[newRStart];
        ++newRStart;
    }

    if (pivot == k - 1) return nums[pivot];
    if (pivot < k - 1) return quickSort(nums, newRStart, r, k);
    else return quickSort(nums, l, newLEnd, k);
}

int findKthLargest(vector<int>& nums, int k) {
    srand((unsigned) time(nullptr));
    return quickSort(nums, 0, nums.size() - 1, k);
}


