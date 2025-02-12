class Solution {
private:
    void dfs(vector<vector<int>>&ans,vector<vector<int>>&image,int sr,int sc,int in_color,int color,int del_row[],int del_col[]){
              ans[sr][sc]=color;
              int n=image.size();
              int m=image[0].size();
              for(int i = 0 ; i < 4 ; i++){
                int nrow=sr+del_row[i];
                int ncol=sc+del_col[i];
                if(ncol>=0 && ncol<m && nrow>=0 && nrow<n && image[nrow][ncol]==in_color && ans[nrow][ncol]!=color){
                    dfs(ans,image,nrow,ncol,in_color,color,del_row,del_col);
                }
              }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        ios_base::sync_with_stdio(false);
        int in_color=image[sr][sc];
        vector<vector<int>>ans=image;
        int del_row[4]={-1,0,1,0};
        int del_col[4]={0,1,0,-1};
        dfs(ans,image,sr,sc,in_color,color,del_row,del_col);
        return ans;
    }
};