class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        ios_base::sync_with_stdio(false);
        priority_queue<pair<int,int>>pq;
        vector<int> ans;
        for(int i = 0 ; i < arr.size() ; i++){
            pq.push({abs(arr[i]-x),arr[i]});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
             int ele=pq.top().second;
             ans.push_back(ele);
             pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};