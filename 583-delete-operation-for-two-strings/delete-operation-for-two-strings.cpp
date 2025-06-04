class Solution {
public:
int longestCommonSubsequence(string text1, string text2) {
        ios_base::sync_with_stdio(false);
        int n = text1.size();
        int m = text2.size();
        vector<int> prev(m+1,0),curr(m+1,0);

        for(int j = 0 ; j <= m ; j++)prev[j]=0;

        for(int ind1 = 1 ; ind1 <= n ; ind1++){
            for(int ind2 = 1 ; ind2 <= m ; ind2++){

                if(text1[ind1-1]==text2[ind2-1]){
                    curr[ind2] = 1+prev[ind2-1];
                }

                else{
                 curr[ind2] = max(prev[ind2],curr[ind2-1]);
                }

            }
            prev=curr;
        }

        return prev[m];
    }
    int minDistance(string word1, string word2) {
        return word1.size()+word2.size()-2*longestCommonSubsequence(word1,word2);
    }
};