class Solution {
public:
    int f(int n,vector<int> &dp){
        if(n==0 || n==1)return 1;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=f(n-1,dp)+f(n-2,dp);
    }
    int climbStairs(int n) {
        ios_base::sync_with_stdio(false);
        vector<int> dp(n+1,-1);
        int ways = f(n,dp);
        return ways;
    }
};