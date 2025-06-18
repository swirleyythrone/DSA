class StockSpanner {
private:
    int ind;
    stack<pair<int,int>> st; 
public:
    StockSpanner() {
        ind=-1;
        
    }
    
    int next(int price) {
        ind+=1;
        int ans=0;
        while(!st.empty() && st.top().first<=price)st.pop();
        ans = ind - (st.empty() ? -1 : st.top().second);
        st.push({price,ind});
        return ans;
    }
};