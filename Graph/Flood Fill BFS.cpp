//BFS
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size();
        int m = image[0].size();
        int ini=image[sr][sc];
        if(ini==color)return image;
        image[sr][sc]=color;

        queue<pair<int, int>> q;
        q.push({sr, sc});
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;
            for (int k = 0; k < 4; k++) {
                int nr = r + drow[k];
                int nc = c + dcol[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    image[nr][nc] == ini) {
                    image[nr][nc] = color; //Color IT
                    q.push({nr, nc});
                }
            }
        }

        return image;
    }
};