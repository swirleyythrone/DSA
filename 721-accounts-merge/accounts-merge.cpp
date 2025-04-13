class DisjointSet{
     public:
     vector<int>rank,parent,size;
     int count;
     DisjointSet(int n){
         rank.resize(n,0);
         parent.resize(n);
         size.resize(n);
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        ios_base::sync_with_stdio(false);
        int n =accounts.size();
        unordered_map<string,int>mpp; 
        DisjointSet ds(n);
        for(int i = 0 ; i< n ; i++){
           for(int j = 1 ;j < accounts[i].size(); j++){
             string mail = accounts[i][j];
             if(mpp.find(mail)==mpp.end()){
                mpp[mail]=i;//if email hasn't been accounted , map it to account i
             }else{
                ds.unionBySize(i,mpp[mail]);//it's already linked to another account (mpp[mail]), so union the current account with the one it’s already linked to — they’re the same person!
             }
           }
        }
        vector<vector<string>> mergeMail(n);
        for(auto it:mpp){
            string mail=it.first;
            int node=ds.findUPar(it.second);//Loop through each email and find the ultimate parent (group leader) of its account.
            mergeMail[node].push_back(mail);//Push the email into that parent’s group.

        }
        vector<vector<string>> ans;
        for(int i = 0 ;i< n ; i++){
            if(mergeMail[i].size()==0)continue;
            sort(mergeMail[i].begin(),mergeMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergeMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};