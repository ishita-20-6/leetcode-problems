/*LC-463 Island Perimeter*/

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& visited) {
        int perimeter=0;
        visited[r][c]=true;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        for(int i=0;i<4;i++) {
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr<0 || nr>=grid.size() || nc<0 || nc>=grid[0].size()) {
                perimeter++;
            } else if(grid[nr][nc]==0){
                perimeter++;
            } else if(grid[nr][nc]==1 && !visited[nr][nc]) {
                perimeter+=dfs(grid,nr,nc,visited);
            }
        }
        return perimeter;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<bool>>visited(grid.size(), (vector<bool>(grid[0].size(),false)));
        int perimeter=0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]==1 && !visited[i][j]) {
                    perimeter=dfs(grid,i,j,visited);
                }
            }
        } 
        return perimeter;  
    }
};
