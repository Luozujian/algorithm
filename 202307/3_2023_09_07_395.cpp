//
// Created by luozu on 2023/9/7.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <unordered_map>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;


// 递归寻找字符串s索引从start到end， 每个字符至少出现k次的最长子串
int maxLength(string s, int start, int end, int k) {
    // 记录每个字符出现的次数
    vector<int> dict = vector<int>(26, 0);
    // 记录出现次数少于k的字符
    vector<int> lessKDict = vector<int>(26, 0);
    bool isExist = false;

    for (int i = start; i <= end; ++i) dict[s[i] - 'a']++;
    for (int i = 0; i < 26; ++i) {
//        printf("%d\n", dict[i]);
        if (dict[i] < k && dict[i] > 0) {
            lessKDict[i] = 1;
            isExist = true;
        }
    }

    int ans = 0;
    // 如果不存在少于k的字符，直接返回子串长度
    if (!isExist) return end - start + 1;
    if (start == end) return 0;
    while(start <= end) {
        // first: 子串头，tailf: 子串尾部
        int first = start, tailf;
        while(first <= end && lessKDict[s[first] - 'a']) ++first;

        tailf = first;
        while(tailf <= end && !lessKDict[s[tailf] - 'a']) ++tailf;
        ans = max(ans, maxLength(s, first, tailf - 1, k));
        printf("%d %d %d %d %d\n", ans, first, tailf, start, end);
        start = tailf + 1;
    }
    return ans;
}


int longestSubstring(string s, int k) {
    return maxLength(s, 0, s.length() - 1, k);
}



int main() {
    cout << longestSubstring("aaabb", 3) << endl;
//    cout << longestSubstring("ababbc", 2) << endl;
//    cout << longestSubstring("a", 1) <<endl;
}