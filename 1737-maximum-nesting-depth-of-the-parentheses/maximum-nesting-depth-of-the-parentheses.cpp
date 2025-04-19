class Solution {
public:
    int maxDepth(string s) {
        ios_base::sync_with_stdio(false);
        int h = 0,n=s.size(),l=0;
        for(int i = 0 ; i < n ; i++){
            if(s[i]=='(')l++;
            if(s[i]==')'){
                h=max(h,l);
                l--;
            }
        }
        return h;
    }
};