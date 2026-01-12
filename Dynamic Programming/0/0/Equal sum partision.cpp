class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        for (int n : nums)
            sum += n;
        bool ans = false;
        if (sum % 2 != 0)
            return false;
        else {
            bool dp[n + 1][sum / 2 + 1];
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= sum / 2; j++) {
                    if (j == 0)
                        dp[i][j] = true;
                    else if (i == 0)
                        dp[i][j] = false;

                    else if (nums[i - 1] <= j)
                        dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                    else
                        dp[i][j] = dp[i - 1][j];
                }
            }
            ans = dp[n][sum / 2];
        }
        return ans;
    }
};