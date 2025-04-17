class Solution {
public:
    int xorOperation(int n, int start) {
        int ans=0;
        vector<int> nums(n);
        for(int i = 0; i< n ; i++){
           nums[i]=start+2*i;
           ans^=nums[i];
        }
        return ans;
    }
};