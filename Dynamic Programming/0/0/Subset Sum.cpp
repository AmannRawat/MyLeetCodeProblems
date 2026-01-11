//Memoization
class Solution {
public:
    int dp[1001][1001];

    bool solve(int n, vector<int>& arr, int s) {
        if (s == 0) return true;
        if (n == 0) return false;

        if (dp[n][s] != -1) return dp[n][s];

        if (s >= arr[n-1]) {
            return dp[n][s] =
                solve(n-1, arr, s-arr[n-1]) ||
                solve(n-1, arr, s);
        } else {
            return dp[n][s] = solve(n-1, arr, s);
        }
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        return solve(n, arr, sum);
    }
};

//Tabulation
class Solution {
public:
    bool isSubsetSum(int N, int arr[], int sum) {
        bool dp[N+1][sum+1];

       for (int i = 0; i <= N; i++) {
         for (int j = 0; j <= sum; j++) {
         if (j == 0) dp[i][j] = true;
         else if (i == 0) dp[i][j] = false;
         else if (arr[i-1] <= j)
            dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
         else
            dp[i][j] = dp[i-1][j];
        }
        }
        return dp[N][sum];
    }
};
