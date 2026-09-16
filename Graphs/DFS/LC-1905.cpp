/*LC-1905 Count Sub Islands*/

class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c, vector<vector<bool>>& visited, bool& isIsland) {
        visited[r][c]=true;
        if(grid1[r][c]==0) isIsland=false;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        for(int i=0;i<4;i++) {
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<grid2.size() && nc>=0 && nc<grid2[0].size() && grid2[nr][nc]==1 && !visited[nr][nc]) {
                dfs(grid1,grid2,nr,nc,visited,isIsland);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        //if(grid1.size()==grid2.size() && grid1[0].size()==grid2[0].size()) return 0;
        int m=grid2.size();
        int n=grid2[0].size();
        int island=0;
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        for(int i=0;i<grid2.size();i++) {
            for(int j=0;j<grid2[0].size();j++) {
                if(grid2[i][j]==1 && !visited[i][j]) {
                    bool isIsland=true;
                    dfs(grid1,grid2,i,j,visited,isIsland);
                    if(isIsland) {
                        island++;
                    }
                }
            }
        }
        return island;
    }
};
