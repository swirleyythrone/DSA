class Solution {
public:
    vector<int> Nse(vector<int> &arr){
        int n = arr.size();
        vector<int> v(n,0);
        stack<int> st;
        for(int i = n-1 ; i >= 0 ; i--){
             while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
             v[i] = st.empty() ? n : st.top();
             st.push(i);
        }
        return v;
    }
    vector<int> Pse(vector<int> &arr){
        int n = arr.size();
        vector<int> v(n,0);
        stack<int> st;
        for(int i = 0 ; i < n ; i++){
             while(!st.empty() && arr[st.top()]>arr[i])st.pop();
             v[i] = st.empty() ? -1 : st.top();
             st.push(i);
        }
        return v;
    }
    int sumSubarrayMins(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        vector<int> nse = Nse(arr);
        vector<int> pse = Pse(arr);
        long long total = 0 ;
        int m = 1e9 + 7;
        for(int i = 0 ; i < arr.size() ; i++){
            long long l = i-pse[i];
            long long r = nse[i]-i;
            total = (total + (l*r*arr[i])%m)%m;
        }
        return total;
    }
};