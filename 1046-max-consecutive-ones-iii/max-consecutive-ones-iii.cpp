class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        int n = nums.size();
        int l = 0, r = 0, zeros = 0, maxlen = 0;
        while(r<n){
            if(nums[r]==0)zeros++;
            if(zeros>k){
                if(nums[l]==0)zeros--;
                l++;
            }else{
                int len = r-l+1;
                maxlen = max(len,maxlen);
            }
            r++;
        }
        return maxlen; 
    }
};