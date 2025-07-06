class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev2=0;
        int prev= nums[0];
        for(int ind = 1 ; ind < n ; ind++){
            int pick = nums[ind];
            if(ind>1)pick += prev2;
            int notPick = prev;
            int curr = max(pick,notPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;

    }
};