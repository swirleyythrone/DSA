class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int max_Val = INT_MIN;
        int k = nums.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        for(int i = 0 ; i < k ; i++){
            max_Val= max(max_Val,nums[i][0]);
            pq.push({nums[i][0],i,0});
        }
        int min_l=0,max_r=INT_MAX;
        
        while(1){
            auto it = pq.top();
            
            int curr_Val = it[0];
            int r = it[1];
            int c = it[2];
            pq.pop();
            if(max_r-min_l>max_Val-curr_Val){
                max_r = max_Val;
                min_l = curr_Val;
            }
            if(c<nums[r].size()-1){
                pq.push({nums[r][c+1],r,c+1});
                max_Val = max(max_Val,nums[r][c+1]);
            }else {
                break;
            }
        }
        return {min_l,max_r};
    }
};