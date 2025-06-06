class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>next(2,vector<int>(3,0)),curr(2,vector<int>(3,0));
        
        for(int ind = n-1 ; ind >= 0 ; ind--){
            for(int buy = 0 ; buy <= 1 ; buy++){
                for(int cap = 1 ; cap <=2 ; cap++){
                 if(buy){
                   curr[buy][cap]=max(-prices[ind]+next[0][cap],next[1][cap]);

                 }
                else curr[buy][cap] = max(prices[ind]+next[1][cap-1],next[0][cap]);
                }
                next=curr;
            }
        }
        return next[1][2];
    }
};