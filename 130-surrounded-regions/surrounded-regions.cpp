class Solution {
private:
    int r,c;
    void dfs(int i, int j, vector<vector<char>>& board){
        if(i<0 || i>=r || j<0 || j>=c || board[i][j]=='X' || board[i][j]=='-')return;
        board[i][j]='-';
        dfs(i-1, j, board);
        dfs(i, j-1, board);
        dfs(i+1, j, board);
        dfs(i, j+1, board);
    }
public:
    void solve(vector<vector<char>>& board) {
        this->r = board.size();
        this->c = board[0].size();

        for(int j=0; j<c; j++){
            if(board[0][j]=='O')dfs(0, j, board);

            if(board[r-1][j]=='O')dfs(r-1, j, board);
        }
        for(int i=0; i<r; i++){
            if(board[i][0]=='O')dfs(i, 0, board);
            if(board[i][c-1]=='O')dfs(i, c-1, board);
        }

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(board[i][j]=='-')board[i][j]='O';
                else board[i][j]='X';
            }
        }
    }
};