class Solution {
public:
    bool rotateString(string s, string goal) {
        ios_base::sync_with_stdio(false);
        if(s.length()!=goal.length())return false;
        return (s+s).find(goal)<(s+s).length();
    }
};