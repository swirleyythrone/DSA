class DisjointSet{
    
    public:
    vector<int> rank,parent,size;
      DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1);
        for(int i = 0 ; i < n ; i++){
            parent[i]=i;
            size[i]=1;
        }
     }

     int findUPar(int node){
        if(node==parent[node])return node;
        return parent[node] = findUPar(parent[node]);
     }

     void unionBySize(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u==ulp_v)return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
     }

};


class Solution {

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extra=0;
        for(auto it:connections){
            int u = it[0];
            int v = it[1];
            if(ds.findUPar(u)==ds.findUPar(v)){
                 extra++;
            }else{
                ds.unionBySize(u,v);
            }
        }
        int c = 0;
        for(int i = 0 ; i < n; i++){
            if(ds.parent[i]==i)c++;
        }
        int ans = c-1;
        if(extra>=ans)return ans;
        return -1;

    }
};