class Solution {
public:
 
    string frequencySort(string s) {
        ios_base::sync_with_stdio(false);
        map<char,int> mpp;
        for(char c: s){
            mpp[c]++;
        }
        vector<pair<char,int>> v(mpp.begin(),mpp.end());
        sort(v.begin(), v.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second > b.second; // Sorting based on frequency
    });
        string ans="";
        for(auto &it:v){
            ans+=string(it.second,it.first);
        }
        return ans;

    }
};