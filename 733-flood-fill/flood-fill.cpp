class Solution {
private:
   void dfs(vector<vector<int>> &ans,vector<vector<int>> &image, int sr,int sc,int in_color, int del_row[],int del_col[],int color){
     ans[sr][sc]=color;
     int n = image.size(),m= image[0].size();
     for(int i = 0 ;i < 4 ; i++){
        int nrow=sr+del_row[i];
        int ncol=sc+del_col[i];
        if(nrow>=0 && nrow <n && ncol>=0 && ncol<m && ans[nrow][ncol]!=color && image[nrow][ncol]==in_color){
            dfs(ans,image,nrow,ncol,in_color,del_row,del_col,color);
        }
     }
   }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         ios_base::sync_with_stdio(false);
        vector<vector<int>> ans =image;
        int in_color= image[sr][sc];
        int del_row[4]={-1,0,1,0};
        int del_col[4]={0,1,0,-1};
        dfs(ans,image,sr,sc,in_color,del_row,del_col,color);
        return ans;
    }
};