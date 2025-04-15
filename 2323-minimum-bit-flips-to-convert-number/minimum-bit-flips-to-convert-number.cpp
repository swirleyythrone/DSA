class Solution {
public:
    int minBitFlips(int start, int goal) {
        ios_base::sync_with_stdio(false);
        int ans=start^goal;
        int c=0;
        while(ans!=0){
            ans=(ans&(ans-1));
            c++;
        }
        return c;
    }
};