class Solution
{
public:
    int lcs(string s, string t)
    {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (s[i] == t[j])
                {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                    //cout<<m<<" "<<n<<endl;
                }
                else
                { //cout<<dp[i+1][j]<<" "<<dp[i][j+1]<<endl;
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        // for(int i = 0; i <= m; i++)
        // {
        //     for(int j = 0; j <= n; j++)
        //         cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2)
    {

        int ans = lcs(text1, text2);
        return ans;
    }
};