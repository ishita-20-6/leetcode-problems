/*LC-1020 Number of Enclaves*/

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& visited) {
        visited[r][c]=true;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        for(int i=0;i<4;i++) {
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]==1 && !visited[nr][nc]) {
                dfs(grid,nr,nc,visited);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        int moves=0;
        for(int i=0;i<grid.size();i++) {
            if(grid[i][0]==1) dfs(grid,i,0,visited);
            if(grid[i][n-1]==1) dfs(grid,i,n-1,visited);
        }
        for(int j=0;j<grid[0].size();j++) {
            if(grid[0][j]==1) dfs(grid,0,j,visited);
            if(grid[m-1][j]==1) dfs(grid,m-1,j,visited);
        }
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]==1 && !visited[i][j]) {
                    moves++;
                }
            }
        }
        return moves;
    }
};
