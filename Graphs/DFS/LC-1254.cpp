/*LC-1254 Number of closed Islands*/

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& visited) {
        visited[r][c]=true;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        for(int i=0;i<4;i++) {
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]==0 && !visited[nr][nc]) {
                dfs(grid,nr,nc,visited);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        for(int i=0;i<m;i++) {
            if(grid[i][0]==0) dfs(grid,i,0,visited);
            if(grid[i][n-1]==0) dfs(grid,i,n-1,visited);
        }
        for(int j=0;j<n;j++) {
            if(grid[0][j]==0) dfs(grid,0,j,visited);
            if(grid[m-1][j]==0) dfs(grid,m-1,j,visited);
        }
        int closedIsland=0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]==0 && !visited[i][j]) {
                    closedIsland++;
                    dfs(grid,i,j,visited);
                }
            }
        }
        return closedIsland;
    }
};
