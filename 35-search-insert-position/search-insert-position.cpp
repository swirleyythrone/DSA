class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=0,hi=n;
        if(target>nums[hi-1])return hi;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target)return mid;
            if(target<nums[mid])hi=mid-1;
            else lo=mid+1;

        }
        return lo;
    }
};