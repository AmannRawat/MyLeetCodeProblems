// Recursion TLE
class Solution {
  public:
    int Solveknapsack(int W,int n, vector<int> &val, vector<int> &wt){
        if(n==0 || W==0){
            return 0;
        }
        
        if(wt[n-1]<=W){
            return max(val[n-1]+ Solveknapsack(W-wt[n-1],n-1, val,wt),Solveknapsack(W,n-1, val,wt));
        }
        else {
            return Solveknapsack(W,n-1, val,wt);
        }
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=val.size();
        int ans=Solveknapsack(W,n, val,wt);
        return ans;
    }
};

// Memoization
class Solution {
  public:
       int dp[1001][1001];
    int Solveknapsack(int W,int n, vector<int> &val, vector<int> &wt){
        if(n==0 || W==0){
            return 0;
        }
        
        if(dp[n][W]!=-1) return dp[n][W];
        
        if(wt[n-1]<=W){
            return dp[n][W]= max(val[n-1]+ Solveknapsack(W-wt[n-1],n-1, val,wt),Solveknapsack(W,n-1, val,wt));
        }
        else {
            return dp[n][W]=Solveknapsack(W,n-1, val,wt);
        }
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=val.size();
        memset(dp, -1, sizeof(dp));
        int ans=Solveknapsack(W,n, val,wt);
        return ans;
    }
};

// Tabulation
class Solution {
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        int dp[n+1][W+1];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= W; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
                else if (wt[i-1] <= j) {
                    dp[i][j] = max(
                        val[i-1] + dp[i-1][j - wt[i-1]],
                        dp[i-1][j]
                    );
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][W];
    }
};
