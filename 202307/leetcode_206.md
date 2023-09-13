### [206 反转链表](https://leetcode.cn/problems/reverse-linked-list/)

#### 题意：
给你一个单链表的头节点head，请你反转链表，并返回反转后的结果

#### 解题思路1 => 迭代法
明确一下节点之间的操作顺序即可
时间复杂度o(n)，空间复杂度o(1)
```c++
ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode *currentNode = head, *nextNode = head->next;
    while(nextNode != nullptr) {
        ListNode *tempNode = nextNode->next;
        nextNode->next = currentNode;
        currentNode = nextNode;
        nextNode = tempNode;
    }
    head->next = nullptr;
    return currentNode;
}
```

#### 解题思路2 => 递归法
```c++
ListNode *reverse(ListNode *currentNode, ListNode *nextNode) {
    if (nextNode == nullptr) return currentNode;
    ListNode *tempNode = nextNode->next;
    nextNode->next = currentNode;
    currentNode = nextNode;
    nextNode = tempNode;
    return reverse(currentNode, nextNode);
}

// 递归
ListNode* reverseList1(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode *newHead = reverse(head, head->next);
    head->next = nullptr;
    return newHead;
}
```


#### 解题思路3 => 更加牛逼的递归
时间复杂度o(n)，空间复杂度o(n)
```c++
ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
}
```