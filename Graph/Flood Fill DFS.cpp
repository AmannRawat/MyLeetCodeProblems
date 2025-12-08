//DFS
class Solution {
public:
    void dfs(int r, int c, int color, int start, vector<vector<int>>& img){
        if(r<0||c<0||r>=img.size()||c>=img[0].size()||img[r][c]!=start) return;
        img[r][c]=color;
        dfs(r+1,c,color,start,img);
        dfs(r-1,c,color,start,img);
        dfs(r,c+1,color,start,img);
        dfs(r,c-1,color,start,img);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color){
        int start = img[sr][sc];
        if(start == color) return img;
        dfs(sr, sc, color, start, img);
        return img;
    }
};
