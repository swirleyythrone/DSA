class Solution {
public:
    int firstOccurence(vector<int>& nums, int x,int s,int e){
        int first = -1;
        int mid = s+(e-s)/2;
        while(s<=e){
            if(nums[mid]==x){
                first = mid;
                e = mid - 1;
            }
            else if(nums[mid]<x)s=mid+1;
            else e  = mid - 1;
            mid = s + (e-s)/2;
        }
        return first;

    }
    int lastOccurence(vector<int>& nums, int x,int s,int e){
        int last = -1;
        int mid = s+(e-s)/2;
        while(s<=e){
            if(nums[mid]==x){
                last = mid;
                s = mid + 1;
            }
            else if(nums[mid]<x)s=mid+1;
            else e  = mid - 1;
            mid = s + (e-s)/2;
        }
        return last;

    }
    bool searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0, e = n-1;
        int first = firstOccurence(nums,target,s,e);
        int last = lastOccurence(nums,target,s,e);
        return (first==last);
    }
    int singleNonDuplicate(vector<int>& nums) {
        int flag = 0;
        for(int i = 0 ; i < nums.size() ; i++){
           if(searchRange(nums,nums[i]))return nums[i];
           
        }
        return -1;
    }
};