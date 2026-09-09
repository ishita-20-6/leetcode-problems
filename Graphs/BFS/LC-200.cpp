/* LC-200. Number of Islands*/

class Solution {
public:
    void bfs(vector<vector<char>>& grid, int row, int col) {
        queue<pair<int, int>>q;
        q.push({row, col});
        grid[row][col]='0';
        while(!q.empty()) {
            auto [r, c]=q.front();
            q.pop();
            int dr[]={-1,1,0,0};
            int dc[]={0,0,-1,1};
            for(int i=0;i<4;i++) {
                int r1=r+dr[i];
                int c1=c+dc[i];
                if(r1>=0 && r1<grid.size() && c1>=0 && c1<grid[0].size() && grid[r1][c1]=='1') {
                    grid[r1][c1]='0';
                    q.push({r1,c1});
                } 
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]=='1') {
                    count++;
                    bfs(grid,i,j);
                }
            }
        }
        return count;
    }
};
