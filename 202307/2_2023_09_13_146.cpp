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

    // 如果是中间节点
    if ()




}

void put(int key, int value) {

}

int main() {

}