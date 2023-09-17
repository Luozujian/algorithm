### [215.数组中的第K个最大元素](https://leetcode.cn/problems/kth-largest-element-in-an-array/description/)


##### 题意:
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。





##### 思路1 => 快速排序
时间复杂度o(n)，空间复杂度O(1)

注意事项:

1. 注意特殊case，有序 & 很多一样的

```c++
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
```


#### 思路2 => 堆排序
整体思路: 

构建大顶堆，执行k - 1次删除堆顶操作，之后堆顶就是第k大

```c++
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

```



##### 参考资料:

1. [ ] [1.BFPTR算法](https://zhuanlan.zhihu.com/p/291206708)