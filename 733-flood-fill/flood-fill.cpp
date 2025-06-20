class Solution {
public:
    void dfs(vector<vector<int>> &ans,vector<vector<int>>& image,int in_color,int color,int sr,int sc,int dr[],int dc[]){
        ans[sr][sc]=color;
        int n = ans.size();
        int m = ans[0].size();
        for(int i = 0 ; i < 4 ; i++){
            int nr = sr + dr[i];
            int nc = sc + dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==in_color && ans[nr][nc]!=color){
                dfs(ans,image,in_color,color,nr,nc,dr,dc);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int in_color=image[sr][sc];
        vector<vector<int>> ans=image;
        int dr[4] = {-1,0,+1,0};
        int dc[4] = {0,-1,0,+1};
        dfs(ans,image,in_color,color,sr,sc,dr,dc);
        return ans;
    }
};