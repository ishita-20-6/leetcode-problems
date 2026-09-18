/*LC-695 Max Area of Island*/

class Solution {
public:
    int bfs(vector<vector<int>>& grid, int r, int c) {
        int area=1;
        queue<pair<int, int>>q;
        q.push({r,c});
        grid[r][c]=0;
        while(!q.empty()) {
            auto [a,b]=q.front();
            q.pop();
            int dr[]={-1,1,0,0};
            int dc[]={0,0,-1,1};
            for(int i=0;i<4;i++) {
                int nr=a+dr[i];
                int nc=b+dc[i];
                if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]==1) {
                    grid[nr][nc]=0;
                    q.push({nr,nc});
                    area++;
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]==1) {
                    int area=bfs(grid,i,j); 
                    ans=max(area,ans);
                }
            }
        }
        return ans;
    }
};
