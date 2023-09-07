### [无重复字符的最长子串](https://leetcode.cn/problems/longest-substring-without-repeating-characters/)




#### 解题思路1 => 动态规划:

记dp[i]表示以下标i为结尾的无重复最长子串，记pre[i]表示str[i]上一次出现的位置，记pre[i]表示str[i]上一次出现的位置，记dp[i - 1]首字符位置为firstDp[i - 1]，
如果pre[i] < firstDp[i - 1]，则dp[i] = dp[i - 1] + 1，否则dp[i] = i - pre[i]

时间复杂度：o(N),空间复杂度: o(N)

```c++
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <unordered_map>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;
int lengthOfLongestSubstring(string s) {
    int ans = 0;
    unordered_map<char, int> dict;
    vector<int> dp(maxn, 0);
    for (int i = 1; i <= s.size(); ++i) {
        if (dict[s[i - 1]] == 0) dp[i] = dp[i - 1] + 1;
        else if (dict[s[i - 1]] < i - dp[i - 1]) dp[i] = dp[i - 1] + 1;
        else dp[i] = i - dict[s[i - 1]];
        dict[s[i - 1]] = i;
        ans = max(ans, dp[i]);
    }
    return ans;
}


int main() {
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
    cout << lengthOfLongestSubstring("bbbbb") << endl;
    cout << lengthOfLongestSubstring("pwwkew") << endl;
}


```


#### 解题思路2 => dp优化
计算dp[i]最多只会用到dp[i - 1]，因此没必要申明一个数组，只需要用一个变量currentAns记录以i为结尾的最长无重复子串

时间复杂度o(N)，空间复杂度常量
```c++
int lengthOfLongestSubstring1(string s) {
    int ans = 0, currentAns = 0;
    unordered_map<char, int> dict;
    for (int i = 1; i <= s.size(); ++i) {
        if (dict[s[i - 1]] == 0) currentAns = currentAns + 1;
        else if (dict[s[i - 1]] < i - currentAns) currentAns = currentAns + 1;
        else currentAns = i - dict[s[i - 1]];
        ans = max(ans, currentAns);
        dict[s[i - 1]] = i;
    }
    return ans;
}
```


#### 解题思路3 => 常量优化
以下标i为结尾的最长无重复子串，为该子串所有字符上一次出现下标的最大值到当前位置

**时间复杂度o(N)，空间复杂度o(138)**


```c++
int lengthOfLongestSubstring2(string s) {
    vector<int> dict(138,0);
    int maxPos = 0, ans = 0;
    for (int i = 1; i <= s.size(); ++i) {
        maxPos = max(maxPos, dict[s[i - 1]]);
        dict[s[i - 1]] = i;
        ans = max(ans, i - maxPos);
    }
    return ans;
}
```



#### 子串&子序列类似题目
1. 结尾为索引i的子问题



#### 名词解释
1. [ ] 子串: 字符串某一段连续的序列
2. [ ] 子序列：字符串可以连续也可以不连续的序列


参考资料：
1. [ ] 最优解 https://leetcode.cn/problems/longest-substring-without-repeating-characters/submissions/464045058/
