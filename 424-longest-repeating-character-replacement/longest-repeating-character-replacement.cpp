class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxlen = 0, maxf = 0;
        int hsh[26]={0};
        map<char,int>mpp;
        
        while(r<s.size()){
            hsh[s[r]-'A']++;
            maxf=max(maxf,hsh[s[r]-'A']);
            if((r-l+1)-maxf>k){
                hsh[s[l]-'A']--;
                maxf=0;
                for(int i=0 ; i < 26 ; i++)maxf=max(maxf,hsh[i]);
                l++;
            }
            else{
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};