class Solution {
public:
    void dfs(int i, vector<vector<int>>& g, vector<int>& vis) {
        vis[i] = 1;
        int n = g.size();
        for(int j = 0; j < n; j++) {
            if(g[i][j] == 1 && !vis[j]) {
                dfs(j, g, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConn) {
        int n = isConn.size();
        vector<int> vis(n, 0);
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                count++;
                dfs(i, isConn, vis);
            }
        }
        return count;
    }
};
