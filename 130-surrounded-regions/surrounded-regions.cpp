class Solution {
private:
    int r,c;
    void bfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>>&check){
        check[i][j]=true;
        queue<pair<int, int>>q;
        q.push({i, j});
        while(!q.empty()){
            auto [i, j]=q.front(); q.pop();
            if(i-1>=0 && board[i-1][j]=='O' && !check[i-1][j]){
                check[i-1][j]=true;
                q.push({i-1, j});
            }
            if(j-1>=0 && board[i][j-1]=='O' && !check[i][j-1]){
                check[i][j-1]=true;
                q.push({i, j-1});
            }
            if(i+1<r && board[i+1][j]=='O' && !check[i+1][j]){
                check[i+1][j]=true;
                q.push({i+1, j});
            }
            if(j+1<c && board[i][j+1]=='O' && !check[i][j+1]){
                check[i][j+1]=true;
                q.push({i, j+1});
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        this->r=board.size();
        this->c=board[0].size();
        vector<vector<bool>>check(r, vector<bool>(c, false));

        for(int i=0; i<r; i++){
            if(board[i][0]=='O' && !check[i][0])bfs(i, 0, board, check);
            if(board[i][c-1]=='O' && !check[i][c-1])bfs(i, c-1, board, check);
        }
        for(int j=0; j<c; j++){
            if(board[0][j]=='O' && !check[0][j])bfs(0, j, board, check);
            if(board[r-1][j]=='O' && !check[r-1][j])bfs(r-1, j, board, check);
        }

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(check[i][j])board[i][j]='O';
                else board[i][j]='X';
            }
        }
    }
};