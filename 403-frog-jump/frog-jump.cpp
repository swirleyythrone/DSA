class Solution {
public:
map<int,int>mpp;
    bool canCross(vector<int>& stones) {
        
        int n = stones.size();
        vector<vector<bool>> dp(n,vector<bool>(n+1,false));

        if(stones[1]-stones[0]!=1)return false;
        dp[1][1]=true;

        for(int i = 0 ; i < n ; i++){
            mpp[stones[i]]=i;
        }

        for(int i = 1 ; i < n ; i++){
            for(int k = 1 ; k <= n ; k++){
                if(dp[i][k]){
                    for(int jump = k-1 ; jump <= k+1 ; jump++){
                        if(jump>0 && mpp.find(stones[i]+jump)!=mpp.end()){
                            int nextInd = mpp[stones[i]+jump];
                            dp[nextInd][jump] = true;
                        }
                    }
                }
            }
        }
        for(int k = 1 ; k <= n ; k++){
            if(dp[n-1][k])return true;
        }
        
        return false;
    }
};