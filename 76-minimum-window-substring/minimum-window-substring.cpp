class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> target(256, 0), window(256, 0);
        for(char ch : t) target[ch]++;

        int have = 0, need = t.size();
        int l = 0, minLen = INT_MAX, start = 0;

        for(int r = 0; r < s.size(); ++r) {
            if(target[s[r]] > 0) {
                window[s[r]]++;
                if(window[s[r]] <= target[s[r]]) have++;
            }

            while(have == need) {
                if(r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                if(target[s[l]] > 0) {
                    window[s[l]]--;
                    if(window[s[l]] < target[s[l]]) have--;
                }
                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
