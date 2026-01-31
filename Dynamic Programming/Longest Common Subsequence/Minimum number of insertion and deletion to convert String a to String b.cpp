class Solution {

  public:
  int LCS(string &s1, string &s2){
        int n=s1.length();
        int m=s2.length();
        int dp[n+1][m+1];
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
                else if(s1[i-1]==s2[j-1])dp[i][j]= 1+ dp[i-1][j-1];
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    int minOperations(string &s1, string &s2) {
        int lcs=LCS(s1,s2);
        int n=s1.length();
        int m=s2.length();
        int del= n-lcs;
        int ins= m-lcs;
        int ansOpr= ins + del;
        return ansOpr;
    }
}; 