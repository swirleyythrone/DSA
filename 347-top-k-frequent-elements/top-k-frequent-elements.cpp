class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        map<int,int>mpp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i = 0 ; i < nums.size() ; i++){
            mpp[nums[i]]++;
        }

        for(auto &i:mpp){
              pq.push({i.second,i.first});
              if(pq.size()>k)pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};