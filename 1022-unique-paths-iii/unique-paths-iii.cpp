class Solution {
public:
int m,n;
int result;
int obstacleCount;
vector<vector<int>>directions = {
              {-1,0},

    {0,-1},              {0,+1},

              {+1,0},

};
    void f(int i,int j,int count,vector<vector<int>>& grid){
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j]==-1)return;

        if(grid[i][j]==2){
            if(count==obstacleCount){
                result++;
            }
            return;
        }
        int temp = grid[i][j];
        grid[i][j]=-1;
        for(auto &dir : directions){
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            f(i_,j_,count+1,grid);
        }
        grid[i][j]=temp;

    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int start_x=0,start_y=0;
             
        result=0,obstacleCount=0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j]==0)obstacleCount++;
                if(grid[i][j]==1){
                     start_x = i;
                     start_y = j;
                }
            }
        }
        obstacleCount+=1;
        f(start_x,start_y,0,grid);
        return result;
    }
};