class Solution {
public:
    int search(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        int n=nums.size();
        int s=0,e=n-1;
        int mid;
        while(s<=e){
           mid=s+(e-s)/2;
           if(nums[mid]==target)return mid;
           else if(nums[mid]>target)e=mid-1;
           else s=mid+1;
        }
        return -1;
    }
};