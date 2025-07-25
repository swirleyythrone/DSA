class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> s;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            s.insert(nums[i]);
        }
        int maxSum = INT_MIN, currSum = 0;
        for(auto &it : s){
            currSum += it;
            maxSum = max(maxSum,currSum);
            if(currSum<0)currSum = 0;
        }
        return maxSum;
    }
};