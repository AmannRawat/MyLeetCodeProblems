//Recursive Approach
class Solution {
public:
    int solve(int n,int m,string text1, string text2){
        if(n==0 || m==0){
            return 0;
        }

        if(text1[n-1]==text2[m-1]){
            return 1+ solve(n-1,m-1,text1,text2); // +1 when you found common
        }else{
            return max(solve(n-1,m,text1,text2) , solve(n,m-1,text1,text2));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1.size(),text2.size(),text1,text2);
    }
};
//Memoization Approach
class Solution {
public:
    int dp[1001][1001];
    int solve(int n, int m, string &text1, string &text2) { // Passing by refrence reduces TLE
        if (n == 0 || m == 0) {
            return 0;
        }
        if (dp[n][m] != -1)
            return dp[n][m];
        if (text1[n - 1] == text2[m - 1]) {
            return dp[n][m] = 1 + solve(n - 1, m - 1, text1,
                                        text2); // +1 when you found common
        } else {
            return dp[n][m] = max(solve(n - 1, m, text1, text2),
                                  solve(n, m - 1, text1, text2));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        return solve(text1.size(), text2.size(), text1, text2);
    }
};
//Tabulation Approach