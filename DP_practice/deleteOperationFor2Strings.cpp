class Solution
{
public:
    int longestCommonSubsequence(string s, string t)
    {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (s[i] == t[j])
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        return dp[0][0];
    }
    int minDistance(string word1, string word2)
    {
        if (word1.compare(word2) == 0)
            return 0;

        int ans = longestCommonSubsequence(word1, word2);
        return word1.size() - ans + word2.size() - ans;
    }
};