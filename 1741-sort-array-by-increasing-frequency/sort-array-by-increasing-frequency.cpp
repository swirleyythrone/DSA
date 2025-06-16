class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mpp;
        for(int i = 0 ; i < nums.size() ; i++)mpp[nums[i]]++;
        auto cmp = [](pair<int,int> &a, pair<int,int> &b) {
            if (a.first == b.first) return a.second < b.second; // element descending
            return a.first > b.first; // frequency ascending
        };

                priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

        for(auto &i : mpp){
            pq.push({i.second,i.first});
        }
        vector<int> ans;
        while(!pq.empty()){
            int freq = pq.top().first;
            int ele = pq.top().second;
            for(int i = 1 ; i <= freq ; i++){
                ans.push_back(ele);
            }
            pq.pop();
        }
        return ans;
    }
};