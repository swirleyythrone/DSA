class Solution {
    
public:
    int lengthOfLongestSubstring(string s) {
        ios::sync_with_stdio(false);
        unordered_set<char>us;
        int maxLength=0,left=0;
        for(int right=0 ; right<s.length() ; right++){
            while(us.count(s[right])){
                us.erase(s[left]);
                left++;
            }
            us.insert(s[right]);
            maxLength=max(maxLength,right-left+1);
        }
        return maxLength;
    }
};