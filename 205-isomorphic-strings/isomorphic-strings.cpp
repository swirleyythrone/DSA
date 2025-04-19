class Solution {
public:
    bool isIsomorphic(string s, string t) {
        ios_base::sync_with_stdio(false);
        if(s.length()!=t.length())return false;
        vector<int> in_s(200,0);
        vector<int> in_T(200,0);
        for(int i = 0 ;i<s.length() ; i++){
            if(in_s[s[i]]!=in_T[t[i]]){
                return false;

            }
            in_s[s[i]]=i+1;
            in_T[t[i]]=i+1;
        }
        return true;

    }
};