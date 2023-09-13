//
// Created by luozu on 2023/9/13.
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
    ListNode *pre;
    ListNode *next;
    ListNode() {}
    ListNode(int val, ListNode *pre, ListNode *next) : val(val), pre(pre), next(next) {}
};


ListNode *head = new ListNode(), *tail = new ListNode();
unordered_map<int, ListNode*> dict;

int currentLength = 0, cap = 0;
void LRUCache(int capacity) {
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
    // 如果key不存在
    if (!dict[key]) {
        ListNode *tempNode = new ListNode(value, nullptr, nullptr);
        // 如果没有节点
        if (head->next == nullptr) {
            head->next = tempNode;
            return;
        }

        tempNode->next = head->next;
        head->next->pre = tempNode;
        head->next = tempNode;
        dict[key] = tempNode;
        return;
    }

    // 如果key存在
    ListNode *tempNode = dict[key];
    tempNode->val = value;
    // 如果是头节点
    if (!tempNode->pre) return;

    // 如果是尾节点
    if (!tempNode->next) {
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

int main() {

}