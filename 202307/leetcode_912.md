### [912.排序数组](https://leetcode.cn/problems/sort-an-array/description/)


##### 题意:

给你一个整数数组 nums，请你将该数组升序排列。


#### 思路1 => 快速排序
快速排序，特点：

1. 原地排序算法
2. 时间复杂度最差o(n^2)，最好o(logn)，平均o(log(n))

优化特殊case:
1. 加入随机取pivot
2. 注意全是一样值的case

快速排序更加优雅的写法:

前提: 我们维护两个指针i和j,使得i和j满足以下条件:
1. 下标l~i之间的值，都小于等于nums[pivot]，下标i + 1 ~ r之间的值都大于nums[pivot]

当nums[j] > nums[pivot] 则j++，当nums[j] <= nums[pivot]，则++i，再交换nums[i]和nums[j]，然后再++j，这样
就可以满足条件1。

最后交换nums[i + 1]和nums[r]，这样就可以保证l到i的值都小于等于nums[pivot]，i + 2到r的值都大于nums[pivot]；



**算法具体步骤**:

1. 随机取pivot，将nums[pivot]与nums[r] 交换
2. 遍历l~r - 1
3. 当nums[j] > nums[pivot] 则j++，当nums[j] <= nums[pivot]，则++i，再交换nums[i]和nums[j]，然后再++j，这样
   就可以满足条件1。





```c++
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
```


#### 堆排序 => 大顶堆从小到大排序

堆排序步骤:

1. 建堆： 从倒数第二层的节点开始，不断进行向下调整动作，直到第0个元素
2. 排序: 交换栈顶和最后一个元素，然后再对栈顶进行向下调整动作

向下调整:
1. 对比当前元素和两个子节点的大小，如果当前元素大，则无需交换，如果lson大，则和lson交换，继续比较，如果lson大则和rson
交换，继续比较


取堆顶元素:
1. 将堆顶元素和最后一个元素交换，然后删除最后一个元素返回
2. 向下调整第0个元素

添加元素:
1. 在末尾添加
2. 向上调整，只要比父节点大，就交换，递归重复此动作


```c++
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
```
时间复杂度： 建堆时间复杂度o(n)，插入和删除都是o(n) 时间复杂度，拿堆顶是o(1)
建堆: 第一层1个元素，需要交换h(高度)次，第二层2^1个元素，需需要交换h - 1次

s = 1 * h + 2^1 * (h - 1) + ... +2^h * (1)   ----- a

2*s = 2 * h + 2^2 * (h - 1) + ... + 2^h * 2  + 2^(h+1)  ------ b

b-a = 2^(h + 1) + 2^(h) + 2^(h - 1) + 2 - h 等比求和 h = logn 最后求出来是时间复杂度是o(n)



#### 归并排序
归并排序思路，不断从中间划分，然后从最后开始合并成有序的数组，需要借助额外的空间

特点:
1. 稳定、额外空间o(n)、时间复杂度o(logn)



```c++
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
```





#### 参考资料:
1. [ ] [1.官方题解](https://leetcode.cn/problems/sort-an-array/description/)
2. [ ] [2.大顶堆讲解](https://juejin.cn/post/7007610680891146271?searchId=20230917155609D9F3BF885C6CB7416753)