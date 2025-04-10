class DisjointSet{
   
    public:
     vector<int>rank,parent,size;
     int count;
     DisjointSet(int n){
         rank.resize(n+1,0);
         parent.resize(n+1);
         size.resize(n+1);
         count=n;
         for(int i = 0 ; i< n ; i++){
             parent[i]=i;
             size[i]=1;
         }
     }
     
     int findUPar(int node){
         if(node==parent[node])return node;
         return parent[node]=findUPar(parent[node]);
     }
     
     void unionByRank(int u,int v){
     int ul_u=findUPar(u);
     int ul_v=findUPar(v);
     if(ul_u==ul_v) return;
     if(rank[ul_u]<rank[ul_v]){
         parent[ul_u]=ul_v;
    }
     else if(rank[ul_v]<rank[ul_u]){
         parent[ul_v]=ul_u;
    }
    else{
        parent[ul_v]=ul_u;
        rank[ul_u]++;
    }
    count--;
    }
    
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
     
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        ios_base::sync_with_stdio(false);
        int n=stones.size();
        DisjointSet ds(n);
        for(int i= 0 ; i < n ; i++){
            for(int j = 0; j < n ; j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    ds.unionByRank(i,j);
                }
            }
        }
        return n-ds.count;

    }
};