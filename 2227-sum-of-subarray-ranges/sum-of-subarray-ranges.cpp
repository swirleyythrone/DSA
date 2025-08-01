class Solution {
public:
    vector<int> Nse(vector<int> &arr){
        int n = arr.size();
        vector<int> v(n,0);
        stack<int> st;
        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
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
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
            v[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return v;
    }
    long long sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = Nse(arr);
        vector<int> pse = Pse(arr);
        long long total = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            long long l = i - pse[i];
            long long r = nse[i] - i;
            total += l * r * arr[i];
        }
        return total;
    }

    vector<int> Nge(vector<int> &arr){
        int n = arr.size();
        vector<int> v(n,0);
        stack<int> st;
        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && arr[st.top()]<=arr[i]) st.pop();
            v[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return v;
    }
    vector<int> Pge(vector<int> &arr){
        int n = arr.size();
        vector<int> v(n,0);
        stack<int> st;
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()]<arr[i]) st.pop();
            v[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return v;
    }
    long long sumSubarrayMax(vector<int>& arr) {
        vector<int> nge = Nge(arr);
        vector<int> pge = Pge(arr);
        long long total = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            long long l = i - pge[i];
            long long r = nge[i] - i;
            total += l * r * arr[i];
        }
        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMax(nums) - sumSubarrayMins(nums);
    }
};
