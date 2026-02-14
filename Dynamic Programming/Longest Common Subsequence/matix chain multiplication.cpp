class Solution {
  public:
    int solve(int i,int j,vector<int> &arr){
        if(i>=j)return 0;
        
        int minAns=INT_MAX;
        for(int k=i;k<j;k++){
            int temp= solve(i,k,arr) + solve(k+1,j,arr) + arr[i-1] * arr[k] * arr[j];
            minAns=min(minAns,temp);
        }
        return minAns;
    }
    int matrixMultiplication(vector<int> &arr) {
        int n=arr.size();
        int ans=solve(1,n-1,arr);
        return ans;
    }
};

//Memoization
class Solution {
  public:
    int dp[1001][1001];
    int solve(int i,int j,vector<int> &arr){
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int minAns=INT_MAX;
        for(int k=i;k<j;k++){
            int temp= solve(i,k,arr) + solve(k+1,j,arr) + arr[i-1] * arr[k] * arr[j];
            minAns=min(minAns,temp);
        }
        dp[i][j]=minAns;
        return minAns;
    }
    int matrixMultiplication(vector<int> &arr) {
        int n=arr.size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(1,n-1,arr);
        return ans;
    }
};