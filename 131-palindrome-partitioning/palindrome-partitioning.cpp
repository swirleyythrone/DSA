class Solution {
public:
    bool isPalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;

            }
        }
        return true;
    }
    void f(int index,string s,vector<string> &path,vector<vector<string>> &res){
        if(index==s.size()){
            res.push_back(path);
            return;
        }
        for(int i = index ; i < s.size() ; i++){
            if(isPalindrome(s,index,i)){
                path.push_back(s.substr(index,i-index+1));
                f(i+1,s,path,res);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        ios_base::sync_with_stdio(false);
        vector<vector<string>>ans;
        vector<string>path;
        f(0,s,path,ans);
        return ans;
    }

};