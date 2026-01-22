class Solution {
public:
    long long solve(int N, vector<int>& arr, int sum) {
        // long long dp[N + 1][sum + 1]; // can get risky so use vector in
        // leetcode
        vector<vector<long long>> dp(N + 1, vector<long long>(sum + 1, 0));

        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= sum; j++) {
                if (j == 0 && i == 0)
                    dp[i][j] = 1;
                else if (i == 0)
                    dp[i][j] = 0;
                else if (arr[i - 1] <= j)
                    // dp[i][j] = dp[i][j - arr[i - 1]] + dp[i - 1][j];
                    // Giving overflow sp->
                    dp[i][j] = (long long)((__int128)dp[i][j - arr[i - 1]] +
                                           (__int128)dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[N][sum];
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return solve(n, coins, amount);
    }
};