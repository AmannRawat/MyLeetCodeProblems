//Not Subsequence but Substring
class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        int n=s1.size();
        int m=s2.size();
        int dp[n+1][m+1];
        int res=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
                else if(s1[i-1]==s2[j-1]){
                    dp[i][j]= 1 + dp[i-1][j-1];
                }else{
                    dp[i][j]= 0;
                }
                 res = max (res, dp[i][j]);
            }
        }
        return res;
    }
};