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


int lengthOfLongestSubstring1(string s) {
    int ans = 0, currentAns = 0;
    vector<int> dict(135, 0);
    for (int i = 1; i <= s.size(); ++i) {
        if (dict[s[i - 1]] == 0) currentAns = currentAns + 1;
        else if (dict[s[i - 1]] < i - currentAns) currentAns = currentAns + 1;
        else currentAns = i - dict[s[i - 1]];
        ans = max(ans, currentAns);
        dict[s[i - 1]] = i;
    }
    return ans;
}


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



int main() {
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
    cout << lengthOfLongestSubstring("bbbbb") << endl;
    cout << lengthOfLongestSubstring("pwwkew") << endl;

    cout << lengthOfLongestSubstring1("abcabcbb") << endl;
    cout << lengthOfLongestSubstring1("bbbbb") << endl;
    cout << lengthOfLongestSubstring1("pwwkew") << endl;

    cout << lengthOfLongestSubstring2("abcabcbb") << endl;
    cout << lengthOfLongestSubstring2("bbbbb") << endl;
    cout << lengthOfLongestSubstring2("pwwkew") << endl;

}