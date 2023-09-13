//
// Created by luozu on 2023/9/12.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <unordered_map>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 迭代
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

ListNode *reverse(ListNode *currentNode, ListNode *nextNode) {
    if (nextNode == nullptr) return currentNode;
    ListNode *tempNode = nextNode->next;
    nextNode->next = currentNode;
    currentNode = nextNode;
    nextNode = tempNode;
    return reverse(currentNode, nextNode);
}

// 递归=>前序便利
ListNode* reverseList1(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode *newHead = reverse(head, head->next);
    head->next = nullptr;
    return newHead;
}


ListNode *newHead;

// 递归 => 后序遍历
ListNode *reverseList2(ListNode *head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode *newHead = reverseList2(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}



int main() {
    ListNode *node1 = new ListNode();
    ListNode *node2 = new ListNode();
    node1->next = node2;
    node2->next = node1;
    reverseList2(node1);
}