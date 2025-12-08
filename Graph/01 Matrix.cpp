class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dis(n, vector<int>(m, 0));

        queue<pair<pair<int,int>, int>> q;

        // Push all zeros first
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int r = it.first.first;
            int c = it.first.second;
            int d = it.second;

            dis[r][c] = d;

            for(int k = 0; k < 4; k++){
                int nr = r + drow[k];
                int nc = c + dcol[k];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0){
                    vis[nr][nc] = 1;
                    q.push({{nr,nc}, d + 1});
                }
            }
        }

        return dis;
    }
};
