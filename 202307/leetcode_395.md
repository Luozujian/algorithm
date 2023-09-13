### [至少有 K 个重复字符的最长子串](https://leetcode.cn/problems/longest-substring-with-at-least-k-repeating-characters/)



##### 题意:
给你一个字符串 s 和一个整数 k ，请你找出 s 中的最长子串， 要求该子串中的每一字符出现次数都不少于 k 。返回这一子串的长度。
如果不存在这样的子字符串，则返回 0。

##### 思路1 => 分治法
如果一个字符出现的次数少于k，那么最长子串一定不包含这个字符。那么就可以递归的去统计，不包含出现次数少于k次字母的子串

时间复杂度o(N * 26), 空间复杂度o(26 * 52)

最多递归26次，每次递归最多处理N个字符，所以时间复杂度是o(N * 26)
每层需要开辟 52个字符的空间，最多递归26层，所以空间复杂度为o(26 * 52)

```c++
// 递归寻找字符串s索引从start到end， 每个字符至少出现k次的最长子串
int maxLength(string s, int start, int end, int k) {
    vector<int> dict = vector<int>(26, 0);
    vector<int> lessKDict = vector<int> (26, 0);
    bool isExist = false;
    // 统计每个字符出现的次数
    for (int i = start; i <= end; ++i) {
        dict[s[i] - 'a']++;
    }

    // 统计下标从start 到 end，出现次数少于s的字符
    for (int i = 0; i < 26; ++i) {
        if (dict[i] < k && dict[i] > 0) {
            lessKDict[i] = 1;
            isExist = true;
        }
    }

    int ans = 0;
    if (!isExist) return end - start + 1;
    if (start == end) return 0;
    // first: 不包含出现次数少于K的子串头，不包含出现次数少于K的子串尾
    while(start <= end) {
        int first = start, tailf;
        while(first <= end && lessKDict[s[first] - 'a']) ++first;

        tailf = first;
        while(tailf <= end && !lessKDict[s[tailf] - 'a']) ++tailf;
        
        
        ans = max(ans, maxLength(s, first, tailf - 1, k));
        start = tailf + 1;
//        printf("%d %d\n", start, end);
    }

    return ans;

}


int longestSubstring(string s, int k) {
    return maxLength(s, 0, s.length() - 1, k);
}
```


#### 思路2 => 每次递归解决