class Solution {
public:
map<int,int>mpp;

    int f(int i,int k,vector<int> &stones,vector<vector<int>> &dp,int n){
        if(i ==n-1)return true;
        if(dp[i][k]!=-1)return dp[i][k];
        bool k0=false,k1=false,k2=false;
        if(k>1 && mpp.find(stones[i] +k-1)!=mpp.end()){
            k0 = f(mpp[stones[i]+k-1],k-1,stones,dp,n);
        }
        if(mpp.find(stones[i]+k)!=mpp.end()){
            k1 = f(mpp[stones[i]+k],k,stones,dp,n);
        }
        if(mpp.find(stones[i]+k+1)!=mpp.end()){
            k2 = f(mpp[stones[i]+k+1],k+1,stones,dp,n);
        }
        return dp[i][k] = k0||k1||k2;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n,vector<int>(2001,-1));

        if(stones[1]-stones[0]!=1)return false;
        for(int i = 0 ; i < n ; i++){
            mpp[stones[i]]=i;
        }
        
        return f(1,1,stones,dp,n);
    }
};