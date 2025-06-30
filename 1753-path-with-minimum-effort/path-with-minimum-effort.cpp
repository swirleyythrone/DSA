class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        ios_base::sync_with_stdio(false);
        //{diff,{row,col}}
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>> >,greater<pair<int,pair<int,int>>>>pq;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> d(n,vector<int>(m,1e9));
        d[0][0]=0;
        pq.push({0,{0,0}});
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(row==n-1 && col == m-1)return diff;
            for(int i = 0 ; i < 4 ; i++){
                int nrow = row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m ){
                    int new_effort=max(abs(heights[nrow][ncol]-heights[row][col]),diff);
                    if(new_effort<d[nrow][ncol]){
                        d[nrow][ncol]=new_effort;
                        pq.push({new_effort,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;

    }
};