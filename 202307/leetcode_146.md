### [146 实现一个LRU缓存](https://leetcode.cn/problems/lru-cache/solutions/259678/lruhuan-cun-ji-zhi-by-leetcode-solution/)

##### 题意：
请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
实现 LRUCache 类：

1. LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
2. int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
3. void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。

函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。


##### 思路 => 底层数据结构使用map + 双向链表
整体思路很简单，但是需要考虑各种情况，小技巧
1. 建立虚拟头节点和尾节点，然后头尾节点相连
2. 将某一个节点移到最前面，分为两个步骤，删除节点，在添加节点
3. 删除尾节点，记得释放内存，加分项


```c++
class LRUCache {    
    struct ListNode {
        int val;
        int key;
        ListNode *pre;
        ListNode *next;
        ListNode() : pre(nullptr), next(nullptr) {}
        ListNode(int val, int key, ListNode *pre, ListNode *next) : val(val), key(key), pre(pre), next(next) {}
    };

    ListNode *head = new ListNode(), *tail = new ListNode();
    unordered_map<int, ListNode*> dict;

    int currentLength = 0, cap = 0;

public:
    LRUCache(int capacity) {
         cap = capacity;
    }
    
    int get(int key) {
        // 不存在
        if (!dict[key]) return -1;

        ListNode *tempNode = dict[key];

        // 如果是头节点
        if (!tempNode->pre) return tempNode->val;

        // 如果是尾节点
        if (!tempNode->next) {
            tail->next = tempNode->pre;
            tempNode->pre->next = nullptr;
            tempNode->pre = nullptr;

            tempNode->next = head->next;
            head->next->pre = tempNode;

            head->next = tempNode;
            return tempNode->val;
        }

        // 中间节点
        tempNode->pre->next = tempNode->next;
        tempNode->next->pre = tempNode->pre;

        tempNode->pre = nullptr;
        tempNode->next = head->next;
        head->next->pre = tempNode;
        head->next = tempNode;
        return tempNode->val;
    }
    
    void put(int key, int value) {
        printf("%d %d\n", key, value);
        // 如果key不存在
        if (!dict[key]) {
            ListNode *tempNode = new ListNode(value, key, nullptr, nullptr);
            // 如果没有节点
            if (head->next == nullptr) {
                tail->next = tempNode;
                head->next = tempNode;
                ++currentLength;
                dict[key] = tempNode;
                return;
            }

            tempNode->next = head->next;
            head->next->pre = tempNode;
            head->next = tempNode;
            dict[key] = tempNode;
            ++currentLength;
            if (currentLength > cap) {
                printf("11: %d %d\n", dict[tail->next->val], tail->next->val);
                dict.erase(tail->next->key);
                printf("12: %d\n", dict[tail->next->val]);
                tail->next = tail->next->pre;
                tail->next->next = nullptr;
                --currentLength;
            }
            return;
        }

        // 如果key存在
        ListNode *tempNode = dict[key];
        tempNode->val = value;
        // 如果是头节点
        if (!tempNode->pre) return;

        // 如果是尾节点
        if (!tempNode->next) {
            tail->next = tempNode->pre;
            tempNode->pre->next = nullptr;
            tempNode->pre = nullptr;

            tempNode->next = head->next;
            head->next->pre = tempNode;

            head->next = tempNode;
            return;
        }

        // 中间节点
        tempNode->pre->next = tempNode->next;
        tempNode->next->pre = tempNode->pre;

        tempNode->pre = nullptr;
        tempNode->next = head->next;
        head->next->pre = tempNode;
        head->next = tempNode;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```

##### 相关题目：
1. [ ] [1.LFU缓存](https://leetcode.cn/problems/lfu-cache/description/)
2. [ ] [2.设置内存文件系统](https://leetcode.cn/problems/design-in-memory-file-system/description/)
3. [ ] [3.迭代压缩字符串](https://leetcode.cn/problems/design-compressed-string-iterator/description/)
