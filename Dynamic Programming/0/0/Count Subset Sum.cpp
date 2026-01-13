class Solution {
  public:
  int solve(int N, vector<int>& arr, int sum) {
        int dp[N+1][sum+1];

       for (int i = 0; i <= N; i++) {
         for (int j = 0; j <= sum; j++) {
         
         if(j == 0 && i == 0) dp[i][j] = 1;
        else if(i == 0) dp[i][j] = 0;
         else if (arr[i-1] <= j)
            dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
         else
            dp[i][j] = dp[i-1][j];
        }
        }
        return dp[N][sum];
    }
    int perfectSum(vector<int>& arr, int target) {
        int n=arr.size();
        return solve(n,arr,target);
    }
};