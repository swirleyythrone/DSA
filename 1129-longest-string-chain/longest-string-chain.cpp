class Solution {
public:
    bool compare(string &s1,string &s2){
         if (s1.size() != s2.size() + 1) return false;
        int i = 0, j = 0;
        while (i < s1.size()) {
            if (j < s2.size() && s1[i] == s2[j]) {
                i++; j++;
            } else {
                i++;
            }
        }
        return j == s2.size();

    }

    static bool comp(string &s1,string &s2){
        return s1.size()<s2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),comp);
        vector<int> dp(n,1);
        int maxi=1;
        for(int i =1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(compare(words[i],words[j]) && dp[j]+1>dp[i]){
                    dp[i]=1+dp[j];
                }
            }
            maxi=max(dp[i],maxi);
        }
        return maxi;
    }
};