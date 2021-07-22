// https://web.stanford.edu/class/cs97si/04-dynamic-programming.pdf
// interval dp
int longestPalindromeSubseq(string s)
{
    int n = s.size();
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof dp);
    for (int len = 1; len <= n; len++)
    {
        for (int start = 0, end = start + len - 1; end < n; start += 1, end += 1)
        {
            if (len == 1)
                dp[start][end] = 1;
            else
            {
                dp[start][end] = max(dp[start + 1][end], dp[start][end - 1]);
                if (s[start] == s[end])
                {
                    dp[start][end] = max(dp[start][end], dp[start + 1][end - 1] + 2);
                }
            }
        }
    }

    return dp[0][n - 1];
}

bool kpalindrome(string s, int k)
{
    int t = longestPalindromeSubseq(s);
    return t + k >= s.size();
}
