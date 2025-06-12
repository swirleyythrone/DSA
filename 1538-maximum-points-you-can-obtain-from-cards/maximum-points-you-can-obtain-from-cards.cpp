class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        ios_base::sync_with_stdio(false);
        int n = cardPoints.size();
        int lsum = 0, rsum = 0, maxSum=0;
        for(int i = 0 ; i < k ; i++)lsum+=cardPoints[i];
        maxSum=lsum;
        int rind=n-1;
        for(int i = k-1 ; i >= 0 ; i--){
            lsum=lsum-cardPoints[i];
            rsum+=cardPoints[rind];
            rind--;
            maxSum = max(maxSum,lsum+rsum);
        }
        
        return maxSum;
    }
};