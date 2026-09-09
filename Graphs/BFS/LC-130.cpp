/* LC-130 Surrounded Regions*/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        queue<pair<int,int>> q;
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        for(int i=0;i<n;i++) {
            if(board[0][i]=='O') {
                board[0][i]='S';
                q.push({0,i});
            }
            if(board[m-1][i]=='O') {
                board[m-1][i]='S';
                q.push({m-1,i});
            }
        }
        for(int i=0;i<m;i++) {
            if(board[i][0]=='O') {
                board[i][0]='S';
                q.push({i,0});
            }
            if(board[i][n-1]=='O') {
                board[i][n-1]='S';
                q.push({i,n-1});
            }
        }
        while(!q.empty()) {
            auto [r, c]=q.front();
            q.pop();
            for(int i=0;i<4;i++) {
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc] == 'O') {
                    board[nr][nc]='S';
                    q.push({nr,nc});
                }
            }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='S') board[i][j]='O';
            }
        }
    }
};
