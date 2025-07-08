class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int len =INT_MAX;
        int l=0, sum=0;
        for(int r = 0 ; r < n ; r++){
            sum+=nums[r];
            while(sum>=target){
               len = min(r-l+1,len);
               sum -= nums[l];
               l++;
            }
        }
        return  (len==INT_MAX)? 0:len;
    }
};