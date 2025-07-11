class Solution {
public:
    int dfs(int r,int c,vector<vector<int>>& matrix,vector<vector<int>> &dp){
         if(dp[r][c]!=-1)return dp[r][c];
         int n = matrix.size();
         int m = matrix[0].size();
         int dr[] = {-1,0,+1,0};
         int dc[] = {0,+1,0,-1};
         int maxi = 1;
         for(int i = 0 ; i < 4 ; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && matrix[nr][nc]>matrix[r][c]){
                int len = 1 + dfs(nr,nc,matrix,dp);
                maxi = max(maxi,len);
            }
         }
         return dp[r][c]=maxi;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        if( n == 0 || m == 0)return 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int maxPath=0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                maxPath = max(maxPath,dfs(i,j,matrix,dp));
            }
        }
        return maxPath;
    }
};