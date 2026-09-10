/* LC-200 Number of Island*/

class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        visited[i][j]=true;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        for(int k=0;k<4;k++) {
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]=='1' && !visited[nr][nc]) {
                dfs(grid,visited,nr,nc);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        vector<vector<bool>>visited(m, vector<bool>(n,false));
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]=='1' && !visited[i][j]) {
                    ans++;
                    dfs(grid,visited,i,j);
                }
            }
        }
        return ans;
    }
};
