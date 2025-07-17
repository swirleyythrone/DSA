class Solution {
public:
int n,m;
int dr[4] = {-1,0,+1,0};
int dc[4] = {0,+1,0,-1};
    bool find(int i,int j,int idx,vector<vector<char>>& board, string word){
        if(idx==word.length())return true;
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]!=word[idx] || board[i][j]=='$')return false;
        char temp = board[i][j];
        board[i][j]='$';
        for(int k = 0 ; k < 4 ; k++){
            int i_ = i + dr[k];
            int j_ = j + dc[k];
            if(find(i_,j_,idx+1,board,word))return true;
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
         m = board.size();
         n = board[0].size();
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j]==word[0] && find(i,j,0,board,word))return true;
            }
        }
        return false;
    }
};