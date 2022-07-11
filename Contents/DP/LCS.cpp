int LCS(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    int dp[n1 + 1][n2 + 1];
    memset(dp, 0, sizeof(dp)); 
    // dp[i][j] = s1的前 i 個字元和 s2 的前 j 個字元
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n1][n2];
}