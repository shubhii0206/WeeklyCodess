//https://leetcode.com/problems/decode-ways/
class Solution
{
public:
    int num(string &s, int idx, vector<int> &dp)
    {
        if (idx == s.size())
            dp[idx] = 1;
        if (s[idx] == '0')
            dp[idx] = 0;
        if (dp[idx] != -1)
            return dp[idx];
        int res = num(s, idx + 1, dp);

        if (idx < s.size() - 1 && (s[idx] == '1' || (s[idx] == '2' && s[idx + 1] < '7')))
            res += num(s, idx + 2, dp);
        dp[idx] = res;
        return dp[idx];
    }
    int numDecodings(string s)
    {
        vector<int> dp(s.size() + 1, -1);
        return num(s, 0, dp);
    }
};