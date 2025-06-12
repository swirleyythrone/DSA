class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        ios_base::sync_with_stdio(false);
        map<int,int>mpp;
        int l = 0, r = 0, maxlen = 0;
        while(r<fruits.size()){
            mpp[fruits[r]]++;
            if(mpp.size()>2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0)mpp.erase(fruits[l]);
                l++;
            }else{
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};