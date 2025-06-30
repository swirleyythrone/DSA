class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        ios_base::sync_with_stdio(false);
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0LL,0});
        vector<long long> dist(n,LONG_MAX),ways(n,0);
        dist[0] = 0;
        ways[0] = 1;
        int m = 1e9 + 7;
        while(!pq.empty()){
            auto it = pq.top();
            long long time = it.first;
            int node = it.second;
            pq.pop();
            for(auto &x : adj[node]){
                int adjNode = x.first;
                int wt = x.second;
                long long newTime = time + 1LL*wt;
                if(newTime < dist[adjNode]){
                    dist[adjNode] = newTime;
                    pq.push({dist[adjNode],adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(newTime == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node])%m;
                }
            }
        }
        return ways[n-1]%m;

    }
};