class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        ios_base::sync_with_stdio(false);
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it: times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k}); //{time,node}
        vector<int> dist(n+1,1e9);
        dist[k] = 0;
        while(!pq.empty()){
            auto it = pq.top();
            int time = it.first;
            int node = it.second;
            pq.pop();
            for(auto &x : adj[node]){
                int newNode = x.first;
                int newTime = x.second;
                if(time + newTime < dist[newNode]){
                    dist[newNode] = time + newTime;
                    pq.push({dist[newNode],newNode});
                }
            }
        }
        int ans = *max_element(dist.begin()+1,dist.end());
        return ans==1e9 ? -1 : ans;

    }
};