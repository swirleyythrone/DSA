class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        sort(intervals.begin(),intervals.end(),[](const auto& a,const auto& b){
            return a[1]<b[1];
        });
        int prev_end=intervals[0][1];
        for(int i =1 ; i < intervals.size() ; i++){
            if(prev_end>intervals[i][0])ans++;
            else prev_end=intervals[i][1];
        }
        return ans;
    }
};