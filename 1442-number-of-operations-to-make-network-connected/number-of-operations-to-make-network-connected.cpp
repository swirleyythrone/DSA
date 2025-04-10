class DisjointSet{
    
    public:
    vector<int>rank,parent,size;
     DisjointSet(int n){
         rank.resize(n+1,0);
         parent.resize(n+1);
         size.resize(n+1);
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        ios_base::sync_with_stdio(false);
        DisjointSet ds(n);//for dynamic handling of graphs,we always use DSU
        int cntextra=0;
        for(auto it:connections){
            int u = it[0];
            int v = it[1];
            if(ds.findUPar(u)==ds.findUPar(v)){
                cntextra++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }
        int cntC=0;
        for(int i = 0 ; i < n ; i++){
            if(ds.parent[i]==i)cntC++;
        }
        int ans=cntC-1;
        if(cntextra>=ans)return ans;
        return -1;//If extraedges are less than the ans then the graph will be broken and there will be no connection
    }
};