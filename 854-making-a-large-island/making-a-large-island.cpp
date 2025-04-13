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
private:
    bool isValid(int nrow,int ncol,int n){
        return (nrow>=0 && nrow<n && ncol>=0 && ncol<n);
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        for(int i = 0 ; i< n ; i++){
            for(int j = 0;j <n ; j++){
                if(grid[i][j]==0)continue;
                int dr[4]={-1,0,1,0};
                int dc[4]={0,-1,0,1};
                for(int ind = 0; ind<4 ;ind++){
                   int nrow=i+dr[ind];
                   int ncol=j+dc[ind];
                   if(isValid(nrow,ncol,n) && grid[nrow][ncol]==1){
                     int nodeNo=i*n+j;
                     int adjNo=nrow*n+ncol;
                     ds.unionBySize(nodeNo,adjNo);
                   }
                }
            }
        }
        
        int mx=0;
        for(int i = 0 ;i <n ; i++){
            for(int j = 0;j<n ; j++){
                if(grid[i][j]==1)continue;
                set<int> components;
                int dr[4]={-1,0,1,0};
                int dc[4]={0,-1,0,1};
                for(int ind = 0; ind<4 ;ind++){
                   int nrow=i+dr[ind];
                   int ncol=j+dc[ind];
                   if(isValid(nrow,ncol,n)){
                     if(grid[nrow][ncol]==1){
                        components.insert(ds.findUPar(nrow*n+ncol));
                     }
                   }
                }
                int size_total=0;
                for(auto it:components){
                    size_total+=ds.size[it];
                }
                mx=max(mx,size_total+1);
            }
        }
        for(int nodeNo=0 ;nodeNo<n*n; nodeNo++){
            mx=max(mx,ds.size[ds.findUPar(nodeNo)]);
        }
        return mx;
    }
};