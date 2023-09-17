//
// Created by luozu on 2023/9/14.
//
#include <cstdio>
#include <cmath>
#include <unordered_map>
#include <vector>
#include <time.h>
using namespace std;
const int maxn = 1e5 + 5;


int partition(vector<int> &nums, int l, int r) {
    int randomIndex = rand() % (r - l + 1) + l;
    swap(nums[r], nums[randomIndex]);
    int i = l - 1;
    for (int j = l; j <= r - 1; ++j) {
        if (nums[j] <= nums[r]) {
            ++i;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[r]);
    return i + 1;
}

// 快速排序
void randomQuickSort(vector<int> &nums, int l, int r) {
    if (r <= l) return;
    int pivot = partition(nums, l, r);
    int newLEnd = pivot - 1, newRStart = pivot + 1;
    while(newLEnd >= l && nums[newLEnd] == nums[pivot]) --newLEnd;
    while(newRStart <= r && nums[newRStart] == nums[pivot]) ++newRStart;
    randomQuickSort(nums, l, newLEnd);
    randomQuickSort(nums, newRStart, r);
}


void maxHeap(vector<int> &nums, int i, int len) {
    for (; (i << 1) + 1 <= len;) {
        int lson = (i << 1) + 1;
        int rson = (i << 1) + 2;
        int large = i;
        if (lson <= len && nums[lson] > nums[i]) large = lson;
        if (rson <= len && nums[rson] > nums[large]) large = rson;
        if (large != i) {
            swap(nums[large], nums[i]);
            i = large;
        } else return;
    }
}


void buildHeap(vector<int> &nums, int len) {
    for (int i = len/2; i >= 0; --i) {
        maxHeap(nums, i, len);
    }
}

// 堆排序
void headSort(vector<int> &nums) {
    int len = nums.size() - 1;
    buildHeap(nums, len);
    int i = len;
    for (; i >= 1; --i) {
        swap(nums[i], nums[0]);
        len = len - 1;
        maxHeap(nums, 0, len);
    }
}

vector<int> tmp;
// 归并排序
void mergeSort(vector<int> &nums, int l, int r) {
    if(r <= l) return ;
    int mid = (l + r) >> 1;
    mergeSort(nums, l, mid);
    mergeSort(nums, mid + 1, r);
    int i = l, j = mid + 1, index = 0;
    while(i <= mid && j <= r) {
//        printf("1: %d %d %d\n", i, j, index);
        if (nums[i] <= nums[j]) tmp[index++] = nums[i++];
        else tmp[index++] = nums[j++];
        // printf("2：%d %d %d\n", i, j, index);
    }
    while(i <= mid) tmp[index++] = nums[i++];
    while(j <= r) tmp[index++] = nums[j++];
    for (int k = 0; k < index; ++k) {
        nums[l + k] = tmp[k];
    }
}




vector<int> sortArray(vector<int>& nums) {
    srand((unsigned ) time(NULL));
//    randomQuickSort(nums, 0, nums.size() - 1);
//    headSort(nums);
    tmp.resize(nums.size(), 0);
    mergeSort(nums, 0, nums.size() - 1);
    for (int i = 0; i < nums.size(); ++i) {
        printf("%d%c", nums[i], i == nums.size() - 1 ? '\n':' ');
    }
    return nums;
}


void down(vector<int> &nums, int i, int len) {
    for (; (i << 1) + 1 <= len; ) {
        int lson = (i << 1) + 1;
        int rson = (i << 1) + 2;
        int large = i;
        if (lson <= len && nums[lson] > nums[large]) large = lson;
        if (rson <= len && nums[rson] > nums[large]) large = rson;
        if (large == i) break;
        swap(nums[i], nums[large]);
        i = large;
    }
}

// 构建大顶堆
void buildMaxHeap(vector<int> &nums, int len) {
    for (int i = len/2; i >= 0; --i) {
        down(nums, i, len);
    }
}


int findKthLargest(vector<int>& nums, int k) {
    srand((unsigned) time(nullptr));
    buildMaxHeap(nums, nums.size() - 1);
    int len = nums.size() - 1, endIndex = len - k + 2;
    for (int i = len; i >= endIndex; --i) {
        swap(nums[i], nums[0]);
        len = len - 1;
        down(nums, 0, len);
    }
    return nums[0];
}



int main() {
    vector<int> nums = {1,2,6,5};
    sortArray(nums);
}