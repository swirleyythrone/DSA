class Solution {
public:
    int f(int r1,int c1,int r2,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
        int n = grid.size();
        if(r1==n-1 && c1==n-1)return grid[r1][c1];
        int c2 = r1+c1-r2;
        if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1)return INT_MIN;
        if(dp[r1][c1][r2]!=-1)return dp[r1][c1][r2];
        int cherries=0;
        if(r1==r2 && c1==c2)cherries+=grid[r1][c1];
        else cherries+=grid[r1][c1]+grid[r2][c2];
        int temp = max({
            f(r1+1,c1,r2,grid,dp),
            f(r1+1,c1,r2+1,grid,dp),
            f(r1,c1+1,r2,grid,dp),
            f(r1,c1+1,r2+1,grid,dp)
        });
        return dp[r1][c1][r2]=cherries+temp;
    }
    int cherryPickup(vector<vector<int>>& grid) {
       int n = grid.size();
       vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
       return f(0,0,0,grid,dp)<0 ? 0: f(0,0,0,grid,dp);
    }
};