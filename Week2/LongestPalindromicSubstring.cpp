class Solution
{
public:
    string longestPalindrome(string s)
    {

        int start = 0, maxlen = 1;

        int m = s.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int i = 0; i < m; i++)
        {
            dp[i][i] = 1;
        }

        for (int i = 0; i < m - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = 1;
                start = i;
                maxlen = 2;
            }
        }

        for (int k = 3; k <= m; k++)
        {
            for (int i = 0; i < m - k + 1; i++)
            {
                int j = i + k - 1;

                if (s[i] == s[j] && dp[i + 1][j - 1] == 1)
                {
                    dp[i][j] = 1;
                    if (k > maxlen)
                    {
                        maxlen = k;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxlen);
    }
};