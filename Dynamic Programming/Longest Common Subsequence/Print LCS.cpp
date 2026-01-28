class Solution {
  public:
    vector<string> allLCS(string &s1, string &s2) {
        // Code here
        int n=s1.size();
        int m=s2.size();
        
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                
                if(i==0 || j==0)dp[i][j]=0;
                else if(s1[i-1]==s2[j-1])dp[i][j]=1 + dp[i-1][j-1];
                else dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        int i=n,j=m;
        vector<char> res;
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                 res.push_back(s1[i-1]);
                 i--;
                 j--;
            }
            else if(dp[i][j-1]>dp[i-1][j]) j--;
            else i--;
        }
        return ress;
    }
};
