//
// Created by luozu on 2023/9/14.
//
#include <cstdio>
#include <cmath>
#include <unordered_map>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;

int mainSort(vector<int> &nums, int start, int end) {
    int index = rand() % (end - start + 1) + start;
    int tempValue = nums[index], startValue = nums[start];
    while(start < end) {
        while(end > start && nums[end] >= tempValue) --end;
        if (end == start) break;
        nums[start] = nums[end];
        while(end > start && nums[start] < tempValue) ++start;
        if (end == start) break;
        nums[end] = nums[start];
    }

    if (startValue < nums[start])

    nums[start] = startValue;
    return start;
}


void quikSort(vector<int> &nums, int start, int end) {
    if (start == end) return;
    int index = mainSort(nums, start, end);
    if (index - 1 > start) quikSort(nums, start, index - 1);
    if (end > index + 1) quikSort(nums, index + 1, end);
}


vector<int> sortArray(vector<int>& nums) {


    quikSort(nums, 0, nums.size() - 1);
    for (int i = 0; i < nums.size(); ++i) {
        printf("%d%c", nums[i], i == nums.size() - 1 ? '\n':' ');
    }
    return nums;
}


int main() {
    vector<int> nums = {1,2,3,5};
    sortArray(nums);
}