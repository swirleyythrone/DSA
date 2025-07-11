class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int lmax = height[0] , rmax = height[n-1];
        int total=0;
        while(l<r){
            if(height[l]<height[r]){
                if(height[l]<lmax){
                    total+=lmax-height[l];
                }else{
                    lmax=height[l];
                }
                l++;
            }
            else{
                if(height[r]<rmax){
                    total+=rmax-height[r];
                }else{
                    rmax=height[r];
                }
                r--;
            }
        }
        return total;
    }
};