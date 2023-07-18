#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <unordered_map>
using namespace std;
const int maxn = 1e5 + 5;
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> dict;
    vector<int> dp = vector<int>(s.size(), 0);
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (i == 0) {
            dp[i] = 1;
            dict[s[i]] = i + 1;
            ans = 1;
            continue;
        }
        if (dict[s[i]] >= (i - dp[i - 1] + 1)) dp[i] = i + 1 - dict[s[i]];
        else  dp[i] = dp[i - 1] + 1;
        dict[s[i]] = i  + 1;
        ans = max(ans, dp[i]);
    }
    return ans;
}


int main() {
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
}


// 题目链接 https://leetcode.cn/problems/longest-substring-without-repeating-characters/description
